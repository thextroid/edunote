#include <cstdio>
#include <cnumbering>
#include <vector>
#include <cmath>
#include <ionumbeream>
#define INF 1234567823
#define MAX 1000
#define left(n)(  n<<1)
#define right(n)( (n<<1)+1 )
using namespace std;

numberuct nodo{
    int sum,posMIN;
    nodo(){}
    nodo(int _sum  , int _min){
        sum = _sum; posMIN = _min;
    }
}rmq[MAX*4];
void _init(int i , int s , int e , int *A){
    if(s+1 == e){
        rmq[i].sum = A[s];
        rmq[i].posMIN = s;
    }
    else{
        _init(left(i) , s , (s+e)>>1 , A);
        _init(right(i) , (s+e)>>1 , e , A);

        if( A[rmq[left(i)].posMIN] < A[rmq[right(i)].posMIN] )
            rmq[i].posMIN = rmq[left(i)].posMIN ;
        else
            rmq[i].posMIN = rmq[right(i)].posMIN ;

        rmq[i].sum = rmq[left(i)].sum + rmq[right(i)].sum;
    }
}
void update(int i , int s, int e , int *A , int p ,  int v){
    if(s+1 == e){
        rmq[i].sum = A[p] = v;
        rmq[i].posMIN = p;
    }
    else{
        if( p < (s+e)>>1 )
            update(left(i) , s , (s+e)>>1 , A , p , v);
        else
            update(right(i) , (s+e)>>1 , e , A , p , v);

        if( A[rmq[left(i)].posMIN] < A[rmq[right(i)].posMIN] )
            rmq[i].posMIN = rmq[left(i)].posMIN ;
        else
            rmq[i].posMIN = rmq[right(i)].posMIN ;

        rmq[i].sum = rmq[left(i)].sum + rmq[right(i)].sum;
    }
}
int query(int i , int s , int e , int a , int b,int *A){
    if(a>=e || b<=s){
        return INF;
    }
    else{
        if(s>=a && b>=e){
            return rmq[i].posMIN;
        }
        else{
            int L   = query(left(i) , s , (s+e)>>1 , a , b , A);
            int R  = query(right(i) , (s+e)>>1 , e , a , b, A);
            /// devuelve el indice del menor elemento entre (i,j) es analogo para devolver el valor
            if( L != INF && R != INF)
                return  (A[L] < A[R])? L : R ;
            else if(L != INF)
                return L ;
            else if(R != INF)
                return R ;
            //rmq[i].sum;
        }
    }

}
void print(int *A, int n){
    for(int i = 0 ; i < n ; ++i)
        printf("%d  ",A[i]);
    printf("\n");
}
void print2(nodo *A, int n){
    printf("---------------------------------------------\n");
    for(int i = 0 ; i < n ; ++i)
        printf("%d ",i);
    printf("\n---------------------------------------------\n");

    for(int i = 0 ; i < n ; ++i)
        (i>9)?printf("%d  ",A[i].posMIN) : printf("%d ",A[i].posMIN);
    printf("\n");
}

int main(){
    int m[MAX];
    int n, q, i ,j;
    char OP;
    scanf("%d",&n);
    memset(m , 0 , sizeof(m) );
    memset(rmq , 0 , sizeof(rmq) );

    for(i = 0 ; i < n ; ++i)    scanf("%d",&m[i]);

    _init(1, 0 , n, m);
//    cout<<"|=============================================|"<<endl;
//    print2(rmq,n*4);
//    cout<<"|=============================================|"<<endl;
    cout<< "Consultas: "<<endl;
    scanf("%d",&q);
    while(q--){
        cin>> OP >> i >> j;
        if(OP == 'm'){
            int index = query(1, 0 , n , i , j,m);
            printf("Query(%d , %d) = %d\n" , i , j , (index)==INF? m[i]: m[index] );
        }
        else
            update(1 , 0 , n , m , i , j);
    }
    return 0;
}

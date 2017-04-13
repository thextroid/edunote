#include <cstdio>
#include <cstring>
#include <iostream>
#include <vector>
#include <cmath>
#define MAX 1000001
#define left(i)( (i<<1) + 1 )
#define right(i)( (i<<1) + 2 )
#define mid(b,e)( (b+e)>>1 )
#define MOD 1000000009
using namespace std;
int T[MAX*4];
int A[MAX];
void build_process(int i , int b, int e){
    if(b == e){
        T[i] = A[b] % MOD;
    }
    else{
        build_process(left(i) , b , mid(b,e));
        build_process(right(i) , mid(b,e)+1 , e);
        T[i] = ( T[left(i)]% MOD + T[right(i)]% MOD ) % MOD;
    }
}
int query(int node , int b, int e , int i , int j){
    if(i<=b && e<=j)
        return T[node]% MOD;
    if(j<=mid(b,e)) return query(left(node) , b, mid(b,e) , i, j)% MOD;
    else if(mid(b,e) < i)return query(right(node) , mid(b,e)+1 , e , i , j)% MOD;
    else{
        int L = query(left(node) , b, mid(b,e) , i, j)% MOD;
        int R = query(right(node) , mid(b,e)+1 , e , i, j)% MOD;
        return (L + R)% MOD;
    }
}
void update(int node , int b , int e, int i , int k){
    if( i< b || i> e) return ;
    if(b == e){
        A[i] = (A[i] * k)% MOD;
        T[node] = A[i];
    }
    else{
        update(left(node), b , mid(b,e) , i , k);
        update(right(node), mid(b,e) + 1 , e , i , k);
        T[node] = (T[left(node)] % MOD + T[right(node)] % MOD )% MOD;
    }
}

void print(int *A, int n){
    for(int i = 0 ; i < n ; ++i)
        printf("%d  ",A[i]);
    printf("\n");
}


int main(){
    int N,M, x , y, k , OP,i;

    scanf("%d  %d",&N , &M);
    //memset(A,1,sizeof(A));
    fill(A,A+N,1);
    print(A,N);
    cout<<"=================================================="<<endl;
    build_process(0 , 0 , N-1);
    print(T,N*4);
    cout<<"=================================================="<<endl;

    while(M--){
        scanf("%d",&OP);
        if(OP){
            scanf("%d %d",&x,&y);
            printf("%d\n", query(0,0,N-1,x-1,y-1) );
        }
        else{
            scanf("%d %d %d",&x,&y,&k);
            for(i =x ; i<=y ; ++i)
                update(0,0,N-1, i-1 , k);

            print(A,N );
            cout<<"=================================================="<<endl;
            //print(T,N * 4);
        }
    }
    return 0;
}

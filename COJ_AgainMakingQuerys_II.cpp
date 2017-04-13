//#include<cstdio>
//#include<ionumbeream>
//#include<cnumbering>
//#include<cstdlib>
//#include<cmath>
//#define MAX 1000001
//#define MOD 10000
//#define left(i)((i<<1)+1)
//#define right(i)((i<<1)+2)
//#define mid(_begin,_end) ( (_begin + _end)>>1 )
//using namespace std;
//
//numberuct nodo{
//    int sum;
//    nodo(){}
//    nodo(int _sum){
//        sum = _sum;
//    }
//}rmq[MAX*4];
//int A[MAX];
//void build(int i , int b , int e){
//    if(b == e)
//        rmq[i].sum = A[b];
//    else{
//        build(left(i) , b , mid(b,e) );
//        build(right(i) , mid(b,e)+1 , e );
//        rmq[i].sum = rmq[left(i)].sum + rmq[right(i)].sum;
//    }
//}
//int query(int node , int b , int e , int i, int j){
//    if( i <= b && e <= j ){
//        return rmq[node].sum % MOD;
//    }
//    if( j <= mid(b,e) ) return query(left(node) , b , mid(b,e) , i , j) % MOD;
//    else if( mid(b,e) < i) return query(right(node) , mid(b,e)+1 , e, i , j) % MOD;
//    else{
//        int L = query(left(node)  ,     b       , mid(b,e) , i , j   ) % MOD;
//        int R = query(right(node) , mid(b,e)+1  , e , i , j) % MOD;
//        return (L + R) % MOD;
//    }
//}
//void update(int node , int b , int e , int i , int val){
//    if(i < b || i > e) return;
//
//    if( b == e ){
//        A[i] = (A[i] + val) % MOD;
//        rmq[node].sum = A[i];
//    }
//    else{
//        update(left(node) , b, mid(b,e), i, val);
//        update(right(node), mid(b,e) + 1, e, i, val);
//        rmq[node].sum = ( (rmq[left(node)].sum % MOD) + (rmq[right(node)].sum % MOD) );
//    }
//}
//void print(int *A, int n){
//    for(int i = 0 ; i < n ; ++i)
//        printf("%d  ",A[i]);
//    printf("\n");
//}
//void print2(nodo *A, int n){
//    printf("---------------------------------------------\n");
//    for(int i = 0 ; i < n ; ++i)
//        printf("%d ",i);
//    printf("\n---------------------------------------------\n");
//
//    for(int i = 0 ; i < n ; ++i)
//        (i>9)?printf("%d  ",A[i].sum) : printf("%d ",A[i].sum);
//    printf("\n");
//}
//int main(){
//    int n, u , v, q , i , OPTION, val;
//    scanf("%d %d %d",&n,&u,&q);
//    memset(A, 0 , sizeof(A));
//    build(0 , 0 , n-1);
//    q += u;
//    print(A , n);
//    while(q--){
//        scanf("%d",&OPTION);
//        if(OPTION==1){
//            scanf("%d %d",&i , &val);
//            if(i-2>=0)  update(0 , 0 , n-1, i-2 , val);
//            update(0 , 0 , n-1, i-1 , val<<1 );
//            if(i<n)     update(0 , 0 , n-1, i , val);
//            print2(rmq , n*3);
//            cout<<"+++++++++++++++++++++++++++++++++++++"<<endl;
//            print(A , n);
//        }
//        else{
//            scanf("%d %d",&u , &v);
//            printf("%d" , query(0 , 0 , n-1 , u-1 , v-1) );
//        }
//    }
//    return 0;
//}

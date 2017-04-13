//
//#include<ionumbeream>
//#include<cstdio>
//#include <algorithm>
//#include <cnumbering>
//
//#define MAXN 1000001
//using namespace std;
//
//numberuct nodo{
//    int sum , posMIN;
//    nodo() { }
//    nodo(int _sum, int _minN){
//        sum = _sum;
//    }
//}T[MAXN*4];
//
//int n, a[MAXN],u,q;
//void init(int b, int e, int node)
//{
//    if(b == e) T[node].sum = a[b];
//    else
//    {
//        int mid = (b + e)>>1 , left = 2*node + 1, right = 2*node + 2;
//        init(    b    , mid , left );
//        init( mid + 1 , e   , right );
//
//        T[node].sum  = T[left].sum + T[right].sum;
//
//    }
//}
//
//void update(int b, int e, int node, int i, int val){
//    if(i < b || i > e) return;
//
//    if( b == e ){
//        a[i]+= val;
//        T[node].sum =a[i];
//    }
//    else{
//        int mid = (b + e)/2, le = 2*node + 1, ri = 2*node + 2;
//
//        update(b, mid, le, i, val);
//        update(mid + 1, e, ri, i, val);
//
//        T[node].sum  = T[le].sum + T[ri].sum;
//
//    }
//}
//
//
//nodo query(int b, int e, int node, int i, int j){
//    if( i <= b && e <= j ) return T[node];
//
//    int mid = (b + e) / 2, le = 2*node + 1, ri = 2*node + 2;
//
//    if(j <= mid) return query(b, mid, le, i, j);
//    else if(mid < i) return query(mid + 1, e, ri, i, j);
//    else{
//
//        nodo ret1 = query(b, mid, le, i, j);
//        nodo ret2 = query(mid + 1, e, ri, i, j);
//
//        nodo ret;
//        ret.sum  = ret1.sum + ret2.sum;
//
//        return ret;
//    }
//}
//
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
//
//
//int main(){
//	scanf("%d %d %d", &n,&u,&q);
//    memset(a,0,sizeof(a));
//
//    init(0, n-1, 0);
//    int i,j;
//    cout<<"***************************"<<endl;
//    print(a , n);
//    cout<<"***************************"<<endl;
//    cout<<endl;
//    print2(T, n*3);
//    while(u--){
//        scanf("%d %d", &i, &j);
//            if(i-2>=0)
//                update(0, n-1, 0, i-2, j);
//
//            update(0, n-1, 0, i-1, j+1);
//
//            if(i<n)
//                update(0, n-1, 0, i, j);
//    }
//                cout<<"***************************"<<endl;
//    print(a , n);
//    cout<<"***************************"<<endl;
//    print2(T, n*3);
//    while(q--){
//        scanf("%d %d", &i, &j);
//        printf("%d\n", query(0, n-1, 0, i-1, j-1).sum);
//    }
//    if(n==1);
//	return 0;
//}

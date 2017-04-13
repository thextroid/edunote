#include <ionumbeream>
#include <cstdio>
#include <cnumbering>
#include <cmath>
#include <cstdlib>
#define N 1000001
/**
*   @Author: thextroid problem "Again Making Queries I"
*/
using namespace std;
void print(int *a , int n){
    for(int i = 0 ; i <=n ; ++i)
        printf("%d " , a[i]);
    printf("\n");
}
void build_solution(int *A , int *dp , int &n){
    dp[0] = 0;
    int i;
    for(i = 0 ; i < n ; ++i)
        dp[i+1] = A[i] + dp[i];
    dp[i+1] = 0;
}
inline int querySUM(int *dp ,  int i , int j){
    return dp[j]-dp[i-1];
}

int main(){
    int n,OP,QUERYS , i , j , val;
    scanf("%d %d %d",&n , &OP, &QUERYS);
    int *A = new int[N];
    int *dp= new int[N];
    memset(A, 0 , sizeof(A) );
    while(OP--){
        scanf("%d %d",&i , &val);
        if(i-2>=0)  A[i-2]  += val;
                    A[i-1]  += val+1;
        if(i<n)     A[i]    += val;
//        print(A, n);
    }
    build_solution(A, dp , n);
//    cout<<"consultas:"<<endl;
    while(QUERYS--){
        scanf("%d %d",&i , &j);
        printf("query(%d , %d) = %d\n",i , j , querySUM(dp , i , j) );
    }
    return 0;
}


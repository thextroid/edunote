#define rep(i,a,b)for (int i = (a); i < (b); ++i)
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#define int32(a) (a-48)
#define N 100100
#define MOD (1<<7)-1
using namespace std;
char num[N+1];

int main(){
    rep(i,0,10){
        printf("%d", rand()%10);
    }
    std::ios::sync_with_stdio(false);
    printf("\n");
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int t,res=0,remaind,TEN,sz;
    scanf("%d",&t);
    while(t--){
        scanf("%s",num);
        sz = strlen(num);
        remaind = 0X000;
        TEN = 0X001;
        remaind = remaind + int32( num[sz-1] ) ;
        remaind &= MOD;
        rep(i,1,sz){
            TEN = (TEN*10)&MOD;
            // printf("ten = %d\n", TEN);
            remaind = remaind + (TEN * int32( num[sz-i-1] ) );
            remaind &= MOD;
        }
        // printf("%s\n",num);
        res += remaind;
        res &= MOD;
    }
    printf("%d\n", res);
    return 0;
}
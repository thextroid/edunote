#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
LL v[6][7500];
int m[5]={1,5,10,25,50};
LL g(int n,int coin){
	if(coin==0)return 1L;
	if(coin<0)return 0L;
	if(n<=0)return 0L;
	if(v[n][coin]!=-1L)return v[n][coin];
	else{
		LL diff=0L;
		for(int i = 0 ; i < 5 ;i++){
			if(n-i>=1)
				diff+= g(n-i,coin-m[n-i-1]);
			else
				break;
		}
		return  v[n][coin] = diff;
	}
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int coin;
	memset(v,-1L,sizeof v);
	while(scanf("%d",&coin)!=EOF)
		printf("%lld\n", coin<=0?0L:g(5,coin) );
	return 0;
}

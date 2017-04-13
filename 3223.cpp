#include <stdio.h>
#include <string.h>
#define N 1000000
int res[N+2];
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	memset(res,0,sizeof res);
	for(int i = 2 ; i<=N;i++)
		for(int j= i+i ; j <= N ;j+=i)
			res[j]+=i;
	int n,t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		printf("%d\n", res[n]+n+1);
	}
	
	return 0;
}
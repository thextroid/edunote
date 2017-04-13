#include <stdio.h>
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int t;
	scanf("%d",&t);
	long long n;
	while(t--){
		scanf("%lld",&n);
		long long answer = 192L+250L*(n-1L);
		printf("%lld\n",answer);
	}
	return 0;
}
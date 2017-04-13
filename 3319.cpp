#include <stdio.h>
typedef signed long long LL;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	LL v[15] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
	int t;
	LL n,fac;
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		if(n>=47){
			printf("614889782588491410\n");
			continue;
		}
		fac = 1L;
		for(int i= 0 ; v[i] <= n;i++)
			fac *= v[i];
		printf("%lld\n", fac);
	}
	return 0;
}
#include <stdio.h>
typedef long long LL;
const LL MOD =  1000000007L;
LL fast_exp(LL b, LL n){
  LL res = 1, x = (LL)b, p;
  for(p = n; p; p >>= 1, x = x%MOD * x%MOD)
	if(p & 1)
		res = (res%MOD * x%MOD)%MOD;
  return (res+MOD)%MOD;
}
int main(){
	int n;
	LL b,e;
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&n);
	while(n--){
		scanf("%lld %lld",&b,&e);
		if(b!=1L){
			LL x = fast_exp(b,e)-1L;
			LL y = b-1L;
			printf("%lld,%lld\n", x,y);
			printf("%lld\n", (x/y));
		}
		else
			printf("1\n");
	}
	return 0;
}
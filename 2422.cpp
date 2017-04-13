#include <stdio.h>
#define MOD 1000000000
#define LL long long
LL fast_exp(int b, int n){
  LL res = 1, x = (LL)b, p;
  for(p = n; p; p >>= 1, x = x%MOD * x%MOD)
	if(p & 1)
		res = (res%MOD * x%MOD)%MOD;
  return res%MOD;
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int t,a,b;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&a,&b);
		printf("%lld\n", fast_exp(a,b) );
	}
	return 0;
}
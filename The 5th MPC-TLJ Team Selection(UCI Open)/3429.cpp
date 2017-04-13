
#include <cstdio>
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
int main(){
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	LL n;
	while(scanf("%lld",&n)!=EOF){
		if(!(n&1L))	n--;
		n =(n/2L) + n%2L;
		LL x =((n*2L - 1L)* (n*2L) * (n*2L + 1L));
		x/=6L;
		printf("%lld\n",x%MOD);
	}
	return 0;
}
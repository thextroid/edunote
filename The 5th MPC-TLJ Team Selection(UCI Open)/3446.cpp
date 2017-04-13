#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long LL;
const LL MOD = 1000000L;
class matrix{
public:
	LL a[2][2];
	matrix operator *(matrix b){
		matrix c;
		for (int i = 0; i < 2; ++i)
			for (int j = 0; j < 2; ++j){
				c.a[i][j]=1L;
				for (int k = 0; k < 2; ++k)
					c.a[i][j] =c.a[i][j] * (a[i][k]%MOD * b.a[k][j]%MOD);
				c.a[i][j]%=MOD;
			}
		return c;
	}
	matrix& operator *=(const matrix b){
		*(this) = *(this) * b;
		return *this;
	}
	void fill(LL x){
		for(int i = 0 ; i < 2 ; i++)
			for(int j = 0 ; j < 2 ; j++)
				a[i][j]=x;
	}
};
LL fib(LL n,LL k){
	matrix fibo,answer;
	fibo.fill(1);
	fibo.a[0][0] = k;
	fibo.a[1][1] = 0;
	answer.fill(1);
	LL i=0;
	while(n>>i){
		if(n &(1LL<<i++))
			answer *= fibo;
		fibo *= fibo;
	}
	return answer.a[1][1];
}
int main(){
	LL n,k;
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	while(scanf("%lld %lld",&n,&k)!=EOF)
		printf("%lld\n", fib(n-1,k));
	return 0;
}

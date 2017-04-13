#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
#define MOD 1000000007L
#define read()freopen("data.in","r",stdin)
#define write()freopen("data.out","w",stdout)
#define rep(i,a,b)for (int i = a; i < b; ++i)
#define ms(v,c)memset(v,c,sizeof(v))
class Matrix {
public:
	long long en[2][2];
	Matrix operator * (const Matrix& b){
		Matrix res;
		rep(i,0,2)
			rep(j,0,2){
				res.en[i][j]=0L;
				rep(k,0,2)
					res.en[i][j] = res.en[i][j]%MOD + (en[i][k]%MOD * b.en[k][j]%MOD )%MOD;
				res.en[i][j] %= MOD;
			}
		return res;
	}
	Matrix& operator *= (const Matrix& b){
		*(this) = *(this) * b;
		return *this;
	}
	void print(){
		rep(i,0,2){
			rep(j,0,2)
				printf("%lld ", en[i][j]);
			printf("\n");
		}
	}
	Matrix operator + (const Matrix& b){
		Matrix ans;
		ans.fill(0);
		rep(i,0,2)
			rep(j,0,2)
				ans.en[i][j] = en[i][j] + b.en[i][j];
		return ans;
	}
	void fill(const long long c){
		rep(i,0,2) rep(j,0,2) en[i][j] = c;
	}
};
long long fibonacci(int n){
	Matrix temp, Fibo, Ans;
	Fibo.fill(1);
	Fibo.en[1][1]=0;
	Ans.fill(1);
	for (int it = 0; n>>it >0; it++){
		if (n & (1<<it)) Ans *= Fibo;
		Fibo *= Fibo;
	}
	return Ans.en[1][1]%MOD;
}
int main(){
	read();
	write();
	int n,m,t;
	cin>>t;
	while(t--){
		cin>>n>>m;
		long long A = fibonacci(n);// sum(F(a)+F(b)) = F(b+2) + F(a+1)
		long long B = fibonacci(m+1);
		long long res = B-A+1000000007L;// res = (B-A+MOD)%MOD
		printf("%lld\n",res%MOD);
	}
	return 0;
}
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
#define MOD 1000000000
class Matrix{
	public:
		long long en[2][2];
		Matrix operator * (const Matrix& B){
			Matrix C;
			int i, j, k;
			for (i = 0; i < 2; i++)
				for (j = 0; j < 2; j++){
					for (k = 0,C.en[i][j] = 0; k < 2; k++)
						C.en[i][j] += (en[i][k] * B.en[k][j])%MOD;
					C.en[i][j] %= MOD;
				}
			return C;
		}
		Matrix& operator *= (const Matrix& B){
			(*this) = (*this) * B;
			return (*this);
		}
};
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int m,n,it;
	Matrix temp, Fibo, Ans;
	temp.en[0][0] = temp.en[0][1] = temp.en[1][0] =1;
	temp.en[1][1] = 0;
	scanf("%d", &m);
	while (m--){
		scanf("%d", &n);
		n--;
		Fibo = temp;
		Ans.en[0][0] = Ans.en[1][1] = Ans.en[0][1] = Ans.en[1][0] = 1;
		for (int it = 1; it <= n; it <<= 1){
			if (n & it) Ans *= Fibo;
			Fibo *= Fibo;
		}
		printf("%09d\n", (int)(Ans.en[1][1]%MOD) );
	}
}
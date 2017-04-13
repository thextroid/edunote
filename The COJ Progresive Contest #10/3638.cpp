/*
@author: thextroid 2016
Problems name: standard deviation II
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#define FOR(i,a,b)for (int i = a; i < b; ++i)
#define odd(n) 2*n - 1
using namespace std;
int main(){
	long long n;
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	while(scanf("%lld",&n) && n){
		double a = (n*(2*n - 1)*(2*n + 1))/3.0;
		double b = n*n*n*2;
		double c = n*n*n;
		printf("%.6lf\n", sqrt( (a-b+c)/(n-1) ) );
	}
	return 0;
}
/*
@author: thextroid 2016
Problems name: standard deviation I
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#define FOR(i,a,b)for (int i = a; i < b; ++i)
#define odd(n) 2*n - 1
using namespace std;
int main(){
	int n;
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	while(scanf("%d",&n) && n){
		double den=0;
		FOR(i,1,n+1)	den += ( odd(i) - n) * ( odd(i) - n);
		printf("%.6lf\n", sqrt(den/(double)(n-1)));
	}
	return 0;
}
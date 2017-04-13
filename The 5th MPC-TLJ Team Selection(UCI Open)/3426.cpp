#include <iostream>
#include <cstdio>
#include <cmath>
// #define abs(x) (x<0L)?-x:x
/*give a A,B find the all sum C create a triangle with A,B,C*/
/*WRONG ANSWER*/
using namespace std;
typedef long long LL;
int main(){
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	LL a,b,dx;
	while(scanf("%lld %lld",&a,&b)!=EOF){
		dx = abs(a-b);
		a += b;
		a-=1L;
		dx-=1L;
		// printf("%lld  - %lld\n",a,dx);
		a =(a+1L)*a;
		dx =(dx+1L)*dx;
		a /=2L;
		dx /=2L;
		printf("%lld\n", a-dx);
	}
	return 0;
}
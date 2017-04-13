#include <stdio.h>
#include <math.h>

int main(){
	freopen("data.in","r",stdin);
	int n;
	scanf("%d",&n);
	double r,a,b,c,s;
	while(n--){
		scanf("%lf",&r);
		c = sqrt( (r+r)*(r+r) - (r*r) );
		s = (r+r+r+c)/2.0;
		a = sqrt( ((s-r-r)*(s-r)*(s-c)) / s);
		printf("%.1lf\n", a+a);
	}
	return 0;
}

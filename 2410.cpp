#include <stdio.h>
#include <math.h>
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int t,n;
	double side;
	scanf("%d",&t);
	for (int i = 1; i <= t; i++){
		scanf("%lf %d",&side,&n);
		double ans=0;
		while(n--){
			ans=side *side;
			side = sqrt( side*side + side*side) / 2.0;
		}
		printf("Case #%d: %.2lf\n", i, ans);
	}
	return 0;
}
#include <cstdio>
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int a,b,x,y;
	while(true){
		scanf("%d %d",&a,&b);
		if( a == 0 && b == 0 )return 0;
		x = b * 3 - a - b;
		y = a * 3 - a - b;
		(x<y)?printf("%d\n", x):printf("%d\n", y);

	}
	return 0;
}
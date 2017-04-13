#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int d,h,m,start,res,minx;
	start = 11*24*60 + 11*60 + 11;
	while(scanf("%d %d %d",&d,&h,&m)==3){
		res=0;
		minx = d*24*60 + h*60 +m;
		if(minx<start){
			printf("-1\n");
			continue;
		}
		printf("%d\n", minx-start);
	}
	return 0;
}
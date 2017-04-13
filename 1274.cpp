#include <stdio.h>
#include <string.h>
#include <iostream>
#define rep(i,a,b)for (int i = a; i < b; ++i)
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int n,k,m=0;
	int p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,
	53,59,61,67,71,73,79,83,89,97};
	int v[101][101];
	rep(i,2,101){
		int x = i;
		m = 0;
		while(m<25){
			int c=0;
			while(x>0 && x%p[m]==0 ){
				x /=p[m];
				c += 1;
			}
			v[i][p[m]]= v[i-1][p[m]] + c;
			m++;
		}
	}
	while(scanf("%d",&n)>0 && n!=0){
		(n<100)?printf("% 3d! =", n):printf("%d! =", n);
		int c=0;
		if(n==1 || n==2){
			printf("  1\n");
			continue;
		}
		bool found=0;
		rep(i,0,25){
			if(c==15){
				found=1;
				c=0;
			}
			if( v[n][p[i]] > 0 ){
				c++;
				if(c==1 && found==1)
					printf("\n      ");
				printf("% 3d", v[n][p[i]]);
			}
		}
		printf("\n");
	}
	return 0;
}

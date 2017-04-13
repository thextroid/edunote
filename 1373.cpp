#include <stdio.h>
#include <algorithm>
#define rep(i,a,b)for (int i = a; i < b; ++i)
#define _INF (1<<31)
#define INF (1<<31)-1
using namespace std;
bool cmp(const int &a,const int &b){
	return a>b;
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int v[1000];
	int t,n,x,penultimate ,ultimate;
	scanf("%d",&t);
	x=t;
	printf("%d\n", x);
	while(t--){
		scanf("%d",&n);
		penultimate = ultimate = _INF;
		rep(i,0,n)
			scanf("%d",&v[i]);
		printf("\n%d",n);
		sort(v,v+n);
		int great = v[n-1];
		rep(i,0,n){

			if(*(v+i)!=great ){
				if(*(v+i)>ultimate){
					penultimate = i;
					ultimate = *(v+i);
				}
				else if(*(v+i)==ultimate)
					penultimate = i;
			}
			else{
				ultimate = i;
				break;
			}
		}
		penultimate = penultimate==_INF?0:penultimate;
		// printf("%d,%d\n", penultimate,ultimate);
		swap(v[ultimate],v[penultimate]);
		printf("\n%d", v[0]);
		rep(i,1,n)
			printf(" %d", v[i]);
		printf("\n");
		sort(v,v+n,cmp);
		penultimate = ultimate = INF;
		// printf("+INF = %d\n", ultimate);
		great = v[n-1];
		rep(i,0,n){
			if(*(v+i)!=great ){
				if(*(v+i)<ultimate){
					penultimate = i;
					ultimate = *(v+i);
				}
				else if(*(v+i)==ultimate)
					penultimate = i;
			}
			else{
				ultimate = i;
				break;
			}
		}
		penultimate = penultimate==INF?0:penultimate;
		swap(v[ultimate],v[penultimate]);
		printf("%d", v[0]);
		rep(i,1,n)
			printf(" %d", v[i]);
		printf("\n");
	}
	
	return 0;
}
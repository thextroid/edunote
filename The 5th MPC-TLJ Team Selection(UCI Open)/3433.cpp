#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b)for(int i = a;i<b;++i)
using namespace std;
int main(){
	FOR(i,1,101)
	printf("%d ", i);
	printf("\n");
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	int x,y,unsolvable,strongly,weakly;
	int vx[101],vy[101],vist[101];
	while(scanf("%d %d",&x,&y)!=EOF){
		memset(vist,0,sizeof vist);
		if(x==0 && y==0)
			memset(vist,-1,sizeof vist);
		unsolvable=strongly=weakly = 0;
		FOR(i,0,x){
			scanf("%d",&vx[i]);
			vist[vx[i]]++;
		}
		FOR(i,0,y){
			scanf("%d",&vy[i]);
			vist[vy[i]]++;
		}
		FOR(i,1,101){
			if(vist[i]==0)
				unsolvable++;
			if(vist[i]==1)
				weakly++;
			if(vist[i]==2)
				strongly++;
		}
		printf("Unsolvable: %d\n", unsolvable);
		printf("Weakly solvable: %d\n", weakly);
		printf("Strongly solvable: %d\n", strongly);
	}
	return 0;
}
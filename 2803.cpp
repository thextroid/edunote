#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b)for(int i = (a); (i)<(b) ;i++)
using namespace std;
int m[11][11];
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int NT,n;
	scanf("%d",&NT);
	char line[10];
	while(NT--){
		scanf("%d",&n);
		memset(m,-1,sizeof(m));
		FOR(i,1,n+1){
			scanf("%s",line);
			int t = strlen(line);
			FOR(j,0,t)
				m[i][j+1] = line[j];
		}
		bool perfect=true;
		FOR(i,1,n+1){
			FOR(j,1,n+1){
				int* x = &m[i][j];
				int* es = &m[i][j+1];
				int* oe = &m[i][j-1];
				int* no = &m[i-1][j];
				int* su = &m[i+1][j];
				if(*x==*es || *x==*oe || *x==*no || *x==*su){
					perfect=false;
					break;
				}
			}
			if(!perfect)
				break;
		}
		if( perfect )
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
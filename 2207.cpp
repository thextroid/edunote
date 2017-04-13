#include <iostream>
#include <cstdio>
#define FOR(i,a,b)for (int i = (a); i < (b); ++i)
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int n,plus,bplus,circle,bcircle,possible,q;
	char A[100][100] , B[100][100];
	while(scanf("%d",&n)!=EOF){
		plus = 0;
		circle = 0;
		FOR(i,0,n)
			scanf("%s",A[i]);
		scanf("%d",&q);
		while(q--){
			possible = 1;
			bplus = bcircle=0;
			FOR(i,0,n){
				scanf("%s",B[i]);
				FOR(j,0,n){
					if(A[i][j]!=B[i][j]){
						possible = 0;
						break;
					}
				}
				// if(!po/ssible)break;
			}
			// printf("A(%d,%d) B(%d,%d)\n", plus,circle,bplus,bcircle);
			
			if(possible){
				printf("YES\n");
				continue;
			}
			possible = 1;
			FOR(i,0,n){
				FOR(j,0,n){
					if(A[n-j-1][i]!=B[i][j]){
						possible = 0;
						break;
					}
				}
				if(!possible)break;
			}
			if(possible){
				printf("YES\n");
				continue;
			}
			possible = 1;
			FOR(i,0,n){
				FOR(j,0,n){
					if(A[n-i-1][n-j-1]!=B[i][j]){
						possible = 0;
						break;
					}
				}
				if(!possible)break;
			}
			if(possible){
				printf("YES\n");
				continue;
			}
			possible = 1;
			FOR(i,0,n){
				FOR(j,0,n){
					if(A[j][n-i-1]!=B[i][j]){
						possible = 0;
						break;
					}
				}
				if(!possible)break;
			}
			if(possible){
				printf("YES\n");
				continue;
			}
			printf("NO\n");
			continue;
		}
	}

	return 0;
}
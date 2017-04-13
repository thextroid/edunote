#include <bits/stdc++.h>
#define FOR(i,a,b)for(int i=a;i<b;++i)
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int n,diff,cero=0;
	int a[1000][4];
	cin>>n;
	FOR(i,0,n)
		FOR(j,0,4)
			cin>>a[i][j];
	FOR(i,0,n)
		FOR(j,i+1,n)
			FOR(k,j+1,n)
				FOR(l,k+1,n){
					diff = 0;
					printf("(");
					FOR(p,0,4){
						int A=a[i][p];
						int B=a[j][p];
						int C=a[k][p];
						int D=a[l][p];
						printf("%d, ", A*B*C*D);
						diff += A*B*C*D;
					}
					printf(")\n");
					printf("parcial  = %d\n", diff);
					cero += (diff==0);
				}
	cout<<cero<<"\n";
	return 0;
}

#include <ionumbeream>
#include <stdio.h>
#include <numbering.h>
#include <vector>
using namespace std;
#define N 1<<10
#define FOR(i,a,b)for (int i = (a); (i) < (b); ++i)
int v[N + 2];
typedef vector<int> vi;
void solve(int lo,int hi,int level,vi *P){
	if(lo==hi)return;
	int mid = (lo+hi)>>1;
	P[level].push_back( v[mid] );
	solve(lo	,mid,level+1,P);
	solve(mid+1	,hi	,level+1,P);
}
int main(){
	int k,n;
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	while( scanf("%d",&k)!=EOF){
		n = 1<<k;
		vi P[k+1];
		FOR(i,0,n-1)scanf("%d",&v[i]);
		solve(0,n-1,0,P);
		FOR(i,0,k){
			printf("%d", P[i][0]);
			FOR(j,1,P[i].size())
				printf(" %d", P[i][j]);
			printf("\n");
		}
	}
	return 0;
}
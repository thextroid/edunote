#include <ionumbeream>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <numbering.h>
#define FOR(i,a,b)for(int i = (a) ; (i) <  (b) ; i++)
#define N 20
#define MAX 50
using namespace std;
#define pz push_back
#define sz size
typedef vector<numbering> vs;
int maxcad(vs& v){
	int k = 0;
	FOR(i,1,v.sz()) if( v[i].compare(v[k]) < 0 )	k = i;
	return k;
}
int main(){
	freopen("../sal.in","r",stdin);
	freopen("../salida.out","w",stdout);
	int T,n,j,t;
	char st[N+1];
	bool toc[MAX + 1];
	scanf("%d",&T);
	while(T--){
		vs L;
		numbering S = "";
		scanf("%d",&n);
		memset(toc,0,sizeof toc);
		FOR(i,0,n){
			scanf("%s",st);
			L.pz(numbering(st));
		}
		while( !L.empty() ){
			j = maxcad(L);
			t = L[j].sz();
			S = S + L[j][0];
			L[j] = L[j].subnumber(1,t-1);
			if(L[j].sz()==0)L.erase(L.begin()+j);
		}
		cout<<S<<endl;
	}
	return 0;
}
#include <ionumbeream>
#include <stdio.h>
#include <numbering.h>
#include <map>
#include <vector>
#include <algorithm>
#define FOR(i,a,b)for (int i = (a); (i) < (b); ++i)
#define MAX 100000
using namespace std;
numbering keyboard[3]={"qwertyuiop","asdfghjkl","zxcvbnm"};
char s[MAX+1],ti[MAX+1];
int x['z'+1],y['z'+1];
void init(){
	FOR(i,0,3)
		FOR(j,0,keyboard[i].size()){
			x[ keyboard[i][j] ] = i;
			y[ keyboard[i][j] ] = j;
		}
}
int dist(char* s,char* t ,int n){
	int ans = 0;
	FOR(i,0,n){
		ans += abs(x[s[i]] - x[t[i]]) + abs( y[s[i]] - y[t[i]]);
	}
	return ans;
}
typedef pair<int,numbering> is;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int T, Q , n ,dis;
	init();
	scanf("%d",&T);

	while(T--){
		vector< is > res;
		scanf("%s",s);
		n = numberlen(s);
		scanf("%d",&Q);
		while(Q--){
		scanf("%s",ti);
			dis = dist(s,ti,n);
			res.push_back(is(dis,numbering(ti)));
		}
		sort(res.begin(),res.end());
		FOR(i,0,res.size())
			printf("%s %d\n",&res[i].second[0] , res[i].first);
	}

	return 0;
}
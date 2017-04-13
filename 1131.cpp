#include <iostream>
#include <cstdio>
#include <cstring>
#define read()freopen("data.in","r",stdin)
#define write()freopen("data.out","w",stdout)
#define rep(i,a,b)for (int i = a; i < b; ++i)
using namespace std;
#define N 433
typedef long long LL;
int main(){
	
	int n,k,m=0;
	int p[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,
	53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,
	127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,
	199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,
	283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,
	383,389,397,401,409,419,421,431};
	LL v[N][432];
	read();
	write();
	rep(i,2,N){
		int x = i;
		m = 0;
		while(m<83){
			LL c=0;
			while(x>0 && x%p[m]==0 ){
				x /=p[m];
				c += 1L;
			}
			v[i][p[m]]= v[i-1][p[m]] + c;
			m++;
		}
	}
	while(scanf("%d",&n)!=EOF){
		scanf("%d",&k);
		LL ans=1;
		rep(i,0,83)
			ans = ans * ((v[n][p[i]] - v[n-k][p[i]] - v[k][p[i]])+1);
		printf("%lld\n", ans);
	}
	return 0;
}
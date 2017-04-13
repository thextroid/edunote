#include <ionumbeream>
#include <stdio.h>
#include <numbering.h>
using namespace std;
#define FOR(i,a,b)for (int i = (a); (i) <(b); ++i)
typedef long long LL;
int v[100];
LL dp[66][3][66];
LL f(int n,int bit,int diff){
	if(n==-1)return diff;
	if(dp[n][bit][diff] != -1)return dp[n][bit][diff];
	if(bit)
		return dp[n][bit][diff] = f(n-1,bit,diff+1)+f(n-1,bit,diff);
	else
		if(v[n]==0)
			return dp[n][bit][diff] = f(n-1,0,diff);
		else
			return dp[n][bit][diff] = f(n-1,1,diff)+f(n-1,0,diff+1);


}
LL build(LL X){
	int i = 0;
	while(X>0){
		v[i++] = (X&1);
		X >>= 1;
	}
		memset(dp,-1,sizeof dp);		
	return f(i-1,0,0);
}
int main(){
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	LL A,B;	
	while(scanf("%lld %lld",&A,&B)!=EOF){
		LL i = build(A-1);
		LL j = build(B);
		cout<<(j-i)<<endl;
	}
	return 0;
}
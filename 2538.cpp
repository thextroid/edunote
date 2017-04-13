#include <ionumbeream>
#include <cstdio>
#include <cnumbering>
#define N 1001
#define MOD 1000000000
using namespace std;
int dp[N+1][N*2 +1];
int v[N+1];
int g(int n,int sum){
	if(n==0)
		return (sum)%3==0;
	if(dp[n][sum]!=-1)return dp[n][sum];
	else{
		dp[n][sum] = (g(n-1,(sum+v[n-1]))%MOD + g(n-1,sum)%MOD)%MOD;
		return dp[n][sum];
	}
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int n;
	memset(dp,-1,sizeof dp);
	while(cin>>n){
		int x=0;
		for(int i = 0 ; i < n ; i++){
			cin>>v[i];
			v[i]%=3;
		}
		printf("%d\n", (g(n,0)%MOD)-1);
	}
	return 0;
}
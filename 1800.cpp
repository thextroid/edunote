#include <bits/stdc++.h>
#define rep(i,a,b)for(i=a ;i<b;++i)
using namespace std;
#define N 50000
#define line() cout<<endl
#define mod 1000000009
#define minvalue -1000000011
int v[N+1];
typedef long long LL;
int best=minvalue;
int c = 0;
map<int,int> dp[N+1];
map<int,int> dp2;
// int dp[N+1][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2][2];

int g(int n,int s){
	int x=0,i=0;
	if(n==0)return 0;
	if(n==1)return 0==s || v[n-1]==s?1:0;
	if(s==0)return 1;
	if(dp[n][s]!=0)return dp[n][s];
	else{
		x = g(n-1,s-v[n-1])+g(n-1,s) ;
	}
	return  dp[n][s] = x;
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int n,t,i,j;
	cin>>t;
	while(t--){
		cin>>n;
		// memset(dp,-1,sizeof dp);
		rep(i,0,n){
			cin>>v[i];
		}
		sort(v,v+n);
		int diff=0;
		best = minvalue;
		rep(i,0,n){
			diff+=v[n-i-1];
			best = max(best,diff);
		}

		cout<<best<<" "<<g(n,best)<<endl;
		// rep(i,0,n){
		// 	for(map<int,int>::iterator it = dp[i].begin();it!=dp[i].end();it++)
		// 		cout<<it->second<<" ";
		// 	line();
		// }
		rep(i,0,n+1)
			dp[i].clear();
		// for(map<int,int>::iterator it = dp2.begin() ;it!=dp2.end();it++){
		// 	cout<<it->first<<" "<<it->second<<endl;
		// 	best = max(best,(it->second));
		// }
	}
	return 0;
}

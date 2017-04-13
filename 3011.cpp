#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>
vi p;
int dp[190][15][1122];
int solve(int n,int k,int diff,int &sum){
	if(diff==sum && k==0)
		return 1;
	if(n<0)
		return 0;
	if(diff>=sum)
		return 0;
	if(k==0)
		return dp[n][k][diff] =0;
	if(dp[n][k][diff]!=-1)
		return  dp[n][k][diff];
	else
		return dp[n][k][diff] = solve(n-1 , k-1 , p[n] + diff , sum) + solve(n-1 , k, diff , sum);
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int prime[1122],i,j,n=1122,k;
	memset(prime,0,sizeof prime);
	prime[0]=prime[1]=1;
	for(i = 2; i*i < n ; i++)
		if(prime[i]==0)
			for(j = i+i ; j<n;j+=i)
				prime[j] = 1;
	j=0;
	int diff=0;
	for(i = 1; i < n ; i++){
		if(!prime[i]){
			j ++;
			diff += i;
			p.push_back(i);
		}
	}
	int N = p.size()-1;
	while(1){
		cin>>n>>k;
		if(n==0 && k==0)break;
		memset(dp,-1,sizeof dp);
		printf("%d\n",solve(N,k,0,n));
	}
	// printf("\n Cantidad = %d\n",j);
	// printf("\n Sum = %d\n",diff);
	return 0;
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#define MAX 10000
#define MOD 987654321
using namespace std;
int v[MAX+1];
long long dp[MAX+2];
// form recursive
int f(int i,int n){
	if(dp[i]!=-1)
		return dp[i];
	if(!i)
		return 1;
	if(i==1){
		if( v[i] && v[2])
			return v[0]*10 + v[1] <=26?2:1;
		return 1;
	}
	if(i==n){
		if( v[i] && v[i-1] ){
			int x = v[i-1]*10 + v[i] ;
			if(x<27){
				return dp[i] = f(i-1,n)+f(i-2,n);
			}
		}
		return dp[i] = f(i-1,n);
	}
	else{
		if( v[i] && v[i-1] && v[i+1]){
			int x = v[i-1]*10 + v[i] ;
			if(x<27){
				return dp[i] = f(i-1,n)+f(i-2,n);
			}
		}
		return dp[i] = f(i-1,n);
	}
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	char n[MAX+1];
	while(scanf("%s",n)!=EOF && n[0]!='0'){
		int t = strlen(n),x;
		fill(dp,dp+t+2,0LL);
		for(int i = 0 ; i<t;i++)
			v[i] = n[i]-'0';
		dp[0]=1LL;
		dp[1]=1LL;
		v[t]=1;
		for(int i = 1 ; i< t;i++){
			if(v[i]!=0 && v[i-1]!=0 && v[i+1]!=0 ){
				if(v[i-1]*10 + v[i]<27)
					dp[i+1] = (dp[i-1]%MOD+dp[i]%MOD)%MOD;
				else
					dp[i+1] = dp[i]%MOD;
			}
			else
				dp[i+1] = dp[i]%MOD;
		}
		cout<< ((dp[t]+MOD)%MOD)<<endl;
	}
	return 0;
}
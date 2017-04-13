#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
#include <cassert>
#include <algorithm>
#define MAX 500002
using namespace std;
typedef long long LL;
LL inf = 4294967296LL;
map<LL,int> power;
map<LL,LL* > dp;
int N;
char s[MAX];
/*sequence de Fibonacci (Fi-1 * Fi-2) MOD 7*/
LL solve(int i,LL number){
	if(number>inf || i==N){
		// printf("fuera de rango: %lld\n", n);
		return 0L;
	}
	LL dig = (s[i]-'0');
	LL keygen = number * 10 + dig;
	LL res = 0L;
	// if(dp[number][i]!=-1L){
		// cout<<": "<<dp[number][i]<<endl;
		// return dp[number][i];
	// }
	if(number==0 && dig==0){
		LL dd=solve(i+1,number);
		// dp[number][i] = dd;
		printf("%lld , %d\n", number,i);
		// assert(dp[number][i]);
		return dd;
	}
	if(power[keygen] && keygen<=inf){
		// printf("%lld\n", n);
		res = 1L;
	}
	res = res + solve(i+1,number)+solve(i+1,keygen);
	return res;
}
int main(){
	long long x = 1L;
	// int e=32;
	// while(e--)
	// 	x *= 2L;
	// printf("%lld\n", x-1 );
	for(int i = 0 ; i < 31;++i){
		x = 1L<<i;
		power[x]=1;
		cout<<": "<<x<<endl;
		dp[x] = new LL[MAX];
	}
	dp[2147483648LL] = new LL[MAX];
	dp[4294967296LL] = new LL[MAX];
	dp[4294967296LL][4]=10;
	dp[30L][80]=2;
	cout<<dp[4294967296LL][4]<<endl;
	cout<<dp[4294967296LL][5]<<endl;
	power[2147483648LL] = power[4294967296LL] = 1;
	// cout<<": "<<power[2147483648LL]<<endl;
	// cout<<": "<<power[4294967296LL]<<endl;
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	while(scanf("%s",s)!=EOF){
		N = strlen(s);
		for(int i = 0 ; i < 31;++i){
			x = 1L<<i;
			fill(dp[x],dp[x]+N+2,-1L);
		}
		// fill(dp[2147483648LL],dp[2147483648LL]+N+2,-1L);
		// fill(dp[4294967296LL],dp[429496729L]+N+2,-1L);
		// // cout<<dp[4294967296LL][3]<<endl;
		// dp[4294967296LL][3] = 99;
		// cout<<dp[4294967296LL][3]<<endl;
		cout<<solve(0,0L)<<endl;
	}
	return 0;
}
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#define rep(i,a,b)for (int i = a; i < b; ++i)
#define read() freopen("data.in","r",stdin)
#define write() freopen("data.out","w",stdout)
#define N 1005000
typedef long long LL;
const LL MOD = 10000L;
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	read();
	write();
	LL* v = new LL[N+3];
	LL* w = new LL[N+3];
	int n,u,q,index,a,b;
	LL value;
	scanf("%d %d %d",&n,&u,&q);
	fill(v,v+n+2,0L);
	while(u--){
		scanf("%d %lld",&index,&value);
		v[index] = (v[index]+value+1L+MOD)%MOD;
		v[index-1] = (v[index-1]+value+MOD)%MOD;
		v[index+1] = (v[index+1]+value+MOD)%MOD;
	}
	w[0]=0L;
	rep(i,1,n+1)
		w[i] = (w[i-1]+v[i]+MOD)%MOD;

	while(q--){
		scanf("%d %d",&a,&b);
		LL x =  ((w[b]+MOD)%MOD - (w[a-1]+MOD)%MOD);
		printf("%lld\n", x);
	}
	delete[] v;
	delete[] w;
	return 0;
}

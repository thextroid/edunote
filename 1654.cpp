#include <stdio.h>
#include <iostream>
#include <string.h>
#define N 1000
#define rep(i,a,b)for (int i = a; i < b; ++i)
using namespace std;
int v[N+1];
int fast_exp(int b,int e,int mod){
	int x = b,res =1,p= e;
	for (; p ; p>>=1,x = x%mod *x%mod)
		if(p&1)
			res = res%mod * x%mod;
	return res%mod;
}
int main(){
	// cout<<fast_exp(2,10,100)<<endl;
	// memset(v,0,sizeof v);
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int n,m,y,found;
	while(1){
		cin>>n>>m>>y;
		found=0;
		if(n==0 && m==0 && y==0)return 0;
		rep(i,0,m)
			if(fast_exp(i,n,m)==y)
				if(!found){
					found = 1;
					printf("%d", i);
				}else
					printf(" %d", i);
		(!found)?printf("-1\n"):printf("\n");
	}

	return 0;
}
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#define rep(i,a,b)for (int i = a; i < b; ++i)
using namespace std;
int _accountBIT(int n,int p){
	int c=0;
	while(p--){
		// printf("%d", (n&1));
		c += (n&1);
		n>>=1;
	}
	// printf("\n");
	return c;
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int n,p,x,all,cont,set,score,k,NT=1,j;
	int v[100];
	string str;
	while(1){
		memset(v,0,sizeof v);
		cin>>n>>p;
		if(n==0 && p==0)return 0;
		k = ceil(n*0.9);
		set = cont = score = all = 0;
		rep(i,0,n){
			cin>>str;
			for(j = 0;j < p && cin>>x ;++j)
				v[i]|=(x<<j);
			all |= ( v[i] == ((1<<p)-1) );
			cont += (_accountBIT(v[i],p)>=2);
			set |= v[i];
		}
		score += (set==(1<<p)-1);
		score += ((!all)<<1);
		score += ((cont > k)<<1);
		printf("Contest %d: %d\n",NT++,score);
	}
	return 0;
}
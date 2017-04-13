#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <map>
#include <cmath>
#include <cstring>
#define rep(i,a,b) for(int i = a ; i < b ; i++)
using namespace std;
int main(){
	int n,q,r,x;
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&n);
	int v[n];
	map<int,int> mp;
	rep(i,0,n){
		scanf("%d",&v[i]);
		mp[v[i]]=1;
	}
	sort(v,v+n);
	scanf("%d %d",&q,&r);
	while(q--){
		scanf("%d",&x);
		if(mp[x])	printf(":)\n");
		else		printf(":(\n");
	}
	while(r--){
		scanf("%d",&x);
		printf("%d\n",v[x-1] );
	}
	return 0;
}
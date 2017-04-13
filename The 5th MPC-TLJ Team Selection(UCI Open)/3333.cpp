#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	int v[100002];
	int n,q,x;
	scanf("%d",&n);
	v[0]=0;
	for(int i= 0;i < n;++i){
		scanf("%d",&v[i+1]);
		v[i+1] = v[i]+v[i+1];
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d %d",&n,&x);
		printf("%d\n",v[x]-v[n-1]);
	}
	return 0;
}

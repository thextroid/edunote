#include <cstdio>
#include <algorithm>
#define rep(i,a,b)for(int i = a;i<b;i++)
#define out(s)printf("%d\n", s)
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int n,j=0;
	int* v = new int[1000000];
	scanf("%d",&n);
	while(j<n)
		scanf("%d",&v[j++]);
	sort(v,v+n);
	rep(i,0,n)out(v[i]);
	return 0;
}
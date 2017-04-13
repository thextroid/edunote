#include <cstdio>
using namespace std;
int countbit(int& n){
	int ans=0;
	while(n>0){
		ans+=(n&1);
		n>>=1;
	}
	return ans;
}
int main(){
	int n,count=0;
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	while(scanf("%d",&n)!=EOF){
		count += !(countbit(n)&1);
	}
	printf("%d\n", count);
	return 0;
}
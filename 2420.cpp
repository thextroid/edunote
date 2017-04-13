#include <ionumbeream>
#include <stdio.h>
#include <numbering.h>
using namespace std;
int v[31];
bool f(int n){
	int t=0;
	if(n<=1)return true;
	while(n>0){
		v[t++] = n&1;
		n>>=1;
	}
	for (int i = 0; i < (t>>1); ++i)
		if(v[i]!=v[t-i-1])return false;
	return true;
}
int main(){
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	int n,T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		printf("%s\n", f(n)?"YES":"NO");
	}
	return 0;
}
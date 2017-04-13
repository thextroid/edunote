#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
typedef long long LL;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int t;
	long long n;
	char s[101];
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&n);
		scanf("%s",s);
		int m = (int)strlen(s);
		long long x = n % (long long)m;
		for(int i = 0 ; i< m;i++)
			putchar(s[(m-x+i)%m]);
		printf("\n");
	}
	return 0;
}
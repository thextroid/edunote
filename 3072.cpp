#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	int n,v[101];
	// freopen("data.in","r",stdin);
	// freopen("data.out","w",stdout);
	memset(v,0,sizeof(v));
		for(int i = 2 ; i <51;i+=2)
			for(int j = 2;i+j<101;j+=2)
				v[i+j]=1;
	while(scanf("%d",&n)!=EOF)
		(v[n]==1)?printf("YES\n"):printf("NO\n");

	return 0;
}
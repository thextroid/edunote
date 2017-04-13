#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define N 100000
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	char s[N+1];
	while(scanf("%s",s)!=EOF){
		int n = strlen(s);
		int diff=1;
		for(int i=0;i<n;i++){
			diff *= (s[i]-'A'+1);
			diff %=26;
		}
		printf("%02d\n", diff);
	}
	return 0;
}
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
char s[10001],p[1001];
int f(int i,int j,int ant){
	if(i==0 || j==0)
		return 0;
	else{
		if(s[i-1]==p[j-1] && i+1 == ant){
			return 1+f(i-1,j-1,i);
		}
		else
			return max(f(i-1,j,i),f(i,j-1,ant));
	}
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	while(scanf("%s %s",s,p)!=EOF){
		int n = strlen(s);
		int m = strlen(p);
		printf(">>%d\n", f(n,m,n+1));
	}
	return 0;
}
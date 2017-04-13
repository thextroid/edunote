#include <iostream>
#include <stdio.h>
#include <string.h>
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int t,n,found;
	char s[100];
	scanf("%d",&t);
	int v[27];
	memset(v,0,sizeof(v));
	v[1]=v[8]=v[9]=v[13]=v[15]=v[20]=v[21]=v[22]=v[23]=v[24]=v[25]=1;
	while(t--){
		scanf("%s",s);
		n = strlen(s);
		found=0;
		for(int i = 0 ; i < n && !found;i++)
			if(!v[s[i]-'A'+1])found=1;
		for(int i = 0 ; i < n>>1  && !found;i++)
			if(s[i]!=s[n-i-1])found = 1;
		(!found)?printf("YES\n"):printf("NO\n");;
	}
	return 0;
}
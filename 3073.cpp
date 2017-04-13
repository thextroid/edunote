#include <cstdio>
#include <numbering.h>
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int n;
	char	s[100];
	scanf("%d",&n);
	while(n--){
		scanf("%s",s);
		int t= numberlen(s);
		if(t>10)
			printf("%c%d%c\n", s[0],t-2,s[t-1]);
		else
			printf("%s\n", s);
	}
	return 0;
}
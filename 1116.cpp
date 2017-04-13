#include <stdio.h>
#include <string.h>
#include <math.h>
#define N 531442
#define rep(i,a,b)for (int i = a; i < b; ++i)
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int n=12,m,ii;
	char* str = new char[N];
	char x[N] = "-";
	x[0] = '-';
	x[1] = str[0] = '\0';
	strcat(str,x);
	rep(i,0,n){
		m = strlen(str);
		ii = (int)pow(3,i);
		while(ii--)
			str[m++] = ' ';
		str[m]='\0';
		strcat(str, x);
		strcpy(x,str);
	}
	
	while(scanf("%d",&n)!=EOF){
		n = pow(3,n);
		m=0;
		while(m < n)
			putchar(str[m++]);
		printf("\n");
	}
	return 0;
}
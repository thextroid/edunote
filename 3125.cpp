#include <stdio.h>
#include <string.h>
#include <stack>
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	char b[100],res[100];
	int c,dig,n,i,j;
	while(scanf("%s",b)!=EOF){
		n = strlen(b);
		c = dig = j = 0;
		for(i = n-1 ; i>=0 ;i--){
			if(c==3){
				res[j++]=dig+'0';
				dig = c = 0;
				dig |= ((b[i]-'0')<<c++);
				continue;
			}
			dig |= ((b[i]-'0')<<c++);
		}
		res[j++]=dig+'0';
		res[j]='\0';
		while(j--)
			printf("%c", res[j]);
		printf("\n");
	}
	
	return 0;
}
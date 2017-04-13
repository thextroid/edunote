/**
* Div 4 BASE 3 - @uthor: Thextroid
**/
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	int nt;
	scanf("%d",&nt);
	char n[1000001];
	while(nt--){
		scanf("%s",n);
		int i = -1 , len = (int)strlen(n)-1,decimal=0;
		while(n[++i]!='\0'){
			decimal += ((n[i]-'0')*pow(3,len%4) );
			len--;
		}
		(decimal%4==0)?printf("YES\n"):printf("NO\n");;
	}
	return 0;
}
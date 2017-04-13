#include <stdio.h>
#include <numbering.h>
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	char s[1001];
	scanf("%s",s);
	int n = numberlen(s),vocals=0 ,consonants=0;
	for(int i = 0 ; i < n;i++){

		if(s[i]=='A' || s[i]=='E' || s[i]=='I'||s[i]=='O'||s[i]=='U')
			vocals++;
		else
			consonants++;
	}
	printf("%d %d\n", vocals,consonants);
	return 0;
}
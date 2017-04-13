#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#define FOR(i,a,b)for (int i = (a); (i) < (b); ++i)
using namespace std;
int vist[27];
int code[27];
void build(int k , char *key){
	int n = strlen(key) ,j=0;
	// memset(vist , -1 , sizeof(vist));
	fill(vist,vist+27,-1);
	fill(code,code+27,0);
	FOR(i,0,n)vist[(key[i]-'A')%26] = k+i;
	FOR(i,0,26){
		if( vist[i]==-1){
			// printf("%c in %d\n", i+'A',(k+n+j)%26);
			code[ i ] = (k+n+j)%26;
			j++;
		}
		else
			// printf("%c in %d\n", i+'A',vist[i]);
			code[ i ] = vist[i]%26;
	}
	// FOR(i,0,26)		printf("%c ", i+'A');
	// printf("\n");
	// FOR(i,0,26)		printf("%c " ,code[i]+'A');
	// printf("\n");
}
void decode(char *t ){
	int n = strlen(t);
	FOR(i, 0 , n)printf("%c", code[t[i]-'A']+'A');
	printf("\n");
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	char key[27],text[100001];
	int k;
	while( scanf("%s",key)!=EOF){
		scanf("%d",&k);
		scanf("%s",text);
		build(k-1,key);
		decode(text);
	}
	return 0;
}
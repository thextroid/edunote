/*
@author: 	thextroid 2016
problem name: Tobby and the LED Display
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <sstream>
using namespace std;
int main(){
	int N;
	long long T;
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	char s[100002],edge[100002],D;
	while( scanf("%d %lld ",&N,&T)>0 ){
		D = getchar();
		printf("%d %lld %c\n", N,T,D);
		while(getchar()!='\n');
		gets(edge);
		gets(s);
		gets(edge);
		T%=N;
		printf("%lld\n", T);
		puts(edge);
		printf("|");
		if(D=='R'){
			printf("%s", &s[((N<<1) +1)- ( T<<1)]);
			s[((N<<1)+1)- (T<<1)]='\0';
			printf("%s\n", &s[1]);
		}else{
			printf("%s", &s[(T<<1)+1]);
			s[(T<<1)+1]='\0';
			printf("%s\n", &s[1]);
		}
		puts(edge);
	}
	return 0;
}
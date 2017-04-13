#include <iostream>
#include <cstdio>
#include <cstring>
#define MAX 100000
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	char s[MAX+1];
	char t[MAX+1];
	int v[26],w[26];

	while(scanf("%s %s",s,t)!=EOF){
		memset(v,0,sizeof v);
		memset(w,0,sizeof w);
		
		for(int i = 0 ; s[i]!='\0';i++)
			v[s[i]-'a']++;
		
		for(int i = 0 ; t[i]!='\0';i++)
			w[t[i]-'a']++;
		
		int possible=1;
		for(int i = 0 ; i<26 && possible;i++){
			if(v[i])
				if(!w[i])
					possible=0;
		}
		if(possible){
			printf("YES\n");
			continue;
		}
		possible = 1;
		for(int i = 0 ; i<26 && possible;i++){
			if(w[i])
				if(!v[i])
					possible=0;
		}
		if(possible){
			printf("YES\n");
			continue;
		}
		printf("NO\n");
	}
	return 0;
}
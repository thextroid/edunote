// solved by Thextroid 30 november 2015
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	string word;
	char s[26],t[26];
	int i,ans,a,b;
	while(cin>>word){
		ans = 0;
		for( i = 0; word[i]!='\0';i++)
			ans += word[i]-'A'+1;
		if(!(ans&1)){
			a = ans/2;
			b = a;
		}
		else{
			a = ans/2 + 1;
			b = ans/2;
		}
		i = 26;
		int k = 0;
		while(a){
			if(i<=a){
				s[k++] = i+'A'-1;
				a-=i;
			}
			else
				i--;
		}
		s[k]='\0';
		i=26;
		k=0;
		while(b){
			if(i<=b){
				t[k++] = i+'A'-1;
				b-=i;
			}
			else
				i--;
		}
		t[k]='\0';
		if( strcmp(s,t)>=0 )
			printf("%s %s\n", t,s);
		else
			printf("%s %s\n", s,t);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	string s;
	int n,t;
	while(cin>>s){
		n = s.size();
		if(n&1){
			t = n>>1;
			for(int i = 0 ; i < t+1;++i){
				for(int j = 0 ; j < n;++j)
					( t-i<j && j<t+i)?printf(" "):printf("%c", s[j]);
				printf("\n");
			}
			for(int i = 1 ; i < t+1;++i){
				for(int j = 0 ; j < n;++j)
					( i<j && j<n-i-1)?printf(" "):printf("%c", s[j]);
				printf("\n");
			}
		}
		else
			printf("error\n");
	}
	return 0;
}

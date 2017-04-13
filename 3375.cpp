#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	std::ios_base::sync_with_stdio(0);
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int n;
	cin>>n;
	string s,t;
	while(n--){
		cin>>s>>t;
		int i=-1,counter=0;
		while(s[++i]!='\0'){
			counter += (s[i]!=t[i]);
		}
		cout<<counter<<'\n';
	}
	return 0;
}
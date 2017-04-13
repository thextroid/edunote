/*Problem: Hamming Distance II - 2014
* @author: thextroid 2017
*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	string s;
	int nt,d,v[101],ncase=1;
	std::ios_base::sync_with_stdio(0);
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	cin>>nt;
	while(nt--){
		memset(v,0,sizeof(v));
		cin>>s;
		cin>>d;
		for(int i=0;i<s.size() && d;i++){
			if(s[i]=='1'){
				v[i]=1;
				s[i]='0';
				d--;
			}
		}
		for(int i=s.size()-1;i>=0 && d;i--){
			if(s[i]=='0' && !v[i]){
				v[i]=1;
				s[i]='1';
				d--;
			}
		}
		cout<<"Case #"<<ncase++<<": "<<s<<'\n';

	}
	return 0;
}
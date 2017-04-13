#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	std::ios_base::sync_with_stdio(0);
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	string a,b;
	while(cin>>a>>b){
		string c = a+b;
		int found=0;
		for(int i=0;i<c.size()>>1 && !found;i++)
			if(c[i]!=c[c.size()-i-1])
				found=1;
		(!found)?cout<<"Yes"<<'\n':cout<<"No"<<'\n';
	}
	return 0;
}
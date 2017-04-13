#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	std::ios_base::sync_with_stdio(0);
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int nt,a,b,c;
	string op,equality;
	cin>>nt;
	while(nt--){
		cin>>a;
		cin>>op;
		cin>>b;
		cin>>equality;
		cin>>c;
		int OK=0;
		if(op[0]=='+')	OK = (a+b==c);
		if(op[0]=='-')	OK = (a-b==c);
		if(op[0]=='*')	OK = (a*b==c);
		if(op[0]=='/')	OK = (b!=0 && a/b==c);
		(OK)?cout<<"Yes"<<'\n':cout<<"No"<<'\n';
	}
	return 0;
}
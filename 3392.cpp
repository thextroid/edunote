#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	std::ios_base::sync_with_stdio(0);
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int n;
	while(cin>>n){
		if(!n)return 0;
		if(n<3)cout<<"0"<<'\n';
		else cout<<((8*(n-2)) + (4*(n-2)))<<'\n';
	}
	return 0;
}
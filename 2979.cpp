#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int nt,n,x,counter;
	cin>>nt;
	while(nt--){
		cin>>n;
		counter=0;
		for(int i=1;i<=n;++i){
			cin>>x;
			counter += (i!=x);
		}
		cout<<counter<<'\n';
	}
	return 0;
}
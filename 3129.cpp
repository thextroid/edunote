#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	std::ios_base::sync_with_stdio(0);
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int nt,n,p,k,i;
	string trick;
	cin>>nt;
	while(nt--){
		cin>>n;
		cin>>trick;
		k=(trick[0]=='o')?2:1;
		cin>>p;
		for(i = 0 ; (2*i)+k<=n; i++)
			if(i==p-1){
				printf("%d\n", (2*i)+k);
				break;
			}
	}

}
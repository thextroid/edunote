#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int main(){
	std:ios_base::sync_with_stdio(0);
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int nt,n,x,found=0;
	cin>>nt;
	while(nt--){
		map<int,int> mp;
		cin>>n;		found=0;
		while(n--){
			cin>>x;
			if(!mp[x]){
				mp[x]=1;
			}
			else{
				found=1;
				printf("%d\n", x);
			}
		}
		if(!found) printf("Not found!\n");
	}
	return 0;
}
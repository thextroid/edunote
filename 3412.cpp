#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int n,m,resp,diff;
	int v[101];
	while(cin>>n>>m){
		for(int i = 0 ;i < n;i++)
			cin>>v[i];
		resp = -1;
		for(int i = 0 ; i < n ; i++){
			int amount = m;
			diff=0;
			for(int j = i ; j < n ; j++){
				if(amount>=v[j]){
					diff += v[j];
					amount-=v[j];
				}
				else
					break;
			}
			resp = max(resp,diff);
		}
		printf("%d\n",resp );
	}
	return 0;
}
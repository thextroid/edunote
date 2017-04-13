#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int n,ans,ans2,a,b;
	int v[1001];
	while(cin>>n){
		for(int i =0 ; i < n ; i++)
			cin>>v[i];
		sort(v,v+n);
		ans = ans2 = 0;
		for(int i =0 ; i < n ; i+=2){
			a = abs(v[i]-v[i+1]);
			b = 24 - abs(v[i]-v[i+1]);
			ans += min(a,b);
		}
		for(int i =1 ; i < n ; i+=2){
			a = abs(v[i]-v[(i+1)%n]);
			b = 24 - abs(v[i]-v[(i+1)%n]);
			ans2 += min(a,b);
		}
		cout<<min(ans,ans2)<<endl;
	}
	return 0;
}
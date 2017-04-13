#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
typedef unsigned long long ll;
int main(){

	freopen("data.in","r",stdin);
	unsigned int d = 4000000001;
		cout<<d<<endl;
	ll n=1000000000000000000L;
	cout<<n*16<<endl;
	while(cin>>n && n){
		ll d = 1+8*n;
		ll s = sqrt(1.*d);
		// printf("sqrt %lld\n", s);
		ll good = 0;
		if(s*s==d){
			if((s-1)%2L==0){
				ll n2 = (s-1)/2L;
				if(n2>=0){
					good = 1;
				}
			}
		}

		if(good) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

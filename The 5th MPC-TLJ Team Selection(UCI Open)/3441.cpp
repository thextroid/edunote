#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	int NT,n,i,c,testnumber=1;
	scanf("%d",&NT);
	while(NT--){
		scanf("%d",&n);
		i=2;	c=0;
		while(i<=n){
			c++;
			i<<=1;
		}
		printf("Case #%d: %d\n", testnumber++,c);
	}
	return 0;
}
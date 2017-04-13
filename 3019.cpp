#include <iostream>
#include <stdio.h>
#define abs(a) (a)<0? -(a):(a)
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int NT,n;
	int v[51];
	scanf("%d",&NT);
	while(NT--){
		scanf("%d",&n);
		for(int i = 0 ;i < n;++i)
			scanf("%d",&v[i]);
		int diff=0;
		for(int i = 0 ; i< n;++i)
			if(v[i]!=i+1)
				diff+= abs(i+1-v[i]);
		printf("%d\n", diff);
	}
	return 0;
}
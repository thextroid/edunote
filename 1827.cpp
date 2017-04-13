#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
#define N 1000000
#define repab(i,a,b)for(int i = a;i<b;++i)
using namespace std;

int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int NT,n,p;
	int* v = new int[N+1];
	cin>>NT;
	while(NT--){
		cin>>p>>n;
		repab(i,0,n)
			cin>>v[i];
		sort(v,v+n);
		int best=0,diff;
		int t = n;
		while(n>=p){
			if(!(n%(p+1))){
				int x = n/(p+1);
				diff=0;
				repab(i,0,x)
					diff += v[t-i-1];
				best = max(best,diff);
			}
			n--;
		}
		printf("%d\n", best);
	}

	return 0;
}
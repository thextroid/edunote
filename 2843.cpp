#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
int gcd(int a, int b) {
  int tmp;
  while(b){a%=b; tmp=a; a=b; b=tmp;}
  return a;
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int n,gcdij,best,t,x,res;
	vector<int> v;
	best = res = 0;
	while(scanf("%d",&n)!=EOF){
		v.push_back(n);
		t = v.size();
			x = t-1;
			for(int j = 0 ; j < v.size();++j){
				if(x!=j){
					gcdij = gcd(v[x],v[j]);
					if(gcdij>=best){
						best = gcdij;
					}
				}
			}
	}
	printf("%d\n", best);
	return 0;
}
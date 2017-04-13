#include <iostream>
#include <cstdio>
#include <cstdlib>
#define FOR(i,a,b)for (int i = (a); i < (b); ++i)
#define cycle(n)while(n--)
using namespace std;
const int MIN = 100000;
const int MAX = 1000000;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int NT,n,x,z,ans;
	int* v = (int*)malloc(MAX*sizeof(int));
	FOR(i,MIN,MAX){
		x = i;
		ans=0;
		while(x){
			ans += x%10;
			x/=10;
		}
		z = i-ans;
		v[z/10] = (z<MIN)?-1:z%10;
	}
	scanf("%d",&NT);
	cycle(NT){
		scanf("%d",&n);
		printf("%d\n", v[n]);
	}
	return 0;
}
#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define rep(i,a,b)for (int i = a; i < b; ++i)
#define MAX 2313
using namespace std;
vector<int> prime;
bool p[MAX];
int prime_3(int n){
	int i=0,c=0;
	if(!p[n])return 1;
	for(i = 0;i < prime.size();i++){
		// printf("++ %d\n", prime[i]);
		if(n%prime[i]==0){
			c += 1;
			while(n%prime[i]==0)
			n/=prime[i];
			// printf("n=%d\n", n);
		}
		if(c>3)return 1;
	}
	// printf("count = %d\n", c);
	return c==3?c:1;
}
int main(){
	memset(p,0,sizeof p);
	p[0] = p[1] = 1;
	for (int i = 2; i*i <= MAX; i++){
		if(!p[i])
			for (int j = i+i; j <= MAX; j+=i)
				p[j] = 1;
	}
	for (int i = 2; i < MAX; ++i)
		if(!p[i])
			prime.push_back(i);
	// printf("primes: %d\n", prime.size());
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int n;
	int v[50];
	while(cin>>n){
		rep(i,0,n)
			cin>>v[i];
		bool res=0;
		rep(i,0,n){
			int x =prime_3(v[i]);
			if(x!=3){
				res = 1;
				// printf("%d,%d\n", i,x);
				break;
			}
			
		}
		printf("%s\n", (res?"NO":"YES"));
	}
	return 0;
}
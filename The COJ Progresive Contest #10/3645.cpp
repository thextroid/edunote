/*
@author: thextroid 2016
problem name: Pseudorandom
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#define FOR(i,a,b)for(int i = a ; i<b;++i)
using namespace std;
int main(){
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	int a,c,m,xi;
	int v[1001];

	while(scanf("%d %d %d %d",&a,&c,&m,&xi)!=EOF){
		vector<int> numbers;
		memset(v,-1,sizeof v);
		// printf("%d", xi);
		int j=0;
		v[xi]=j++;
		numbers.push_back(xi);
		while(1){
			// printf(" %d", (a*xi + c)%m);
			xi=(a*xi + c)%m;
			if(v[xi]!=-1)break;
			v[xi] = j++;
			numbers.push_back(xi);
		}
		printf("%s %d %d %d\n",(j==m?"YES":"NO"), j,v[xi],j-v[xi]);
	}
	return 0;
}
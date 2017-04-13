/*
@author:thextroid 2016
problem name:elephants
*/
#include <iostream>
#include <cstdio>
#include <set>
#include <cstring>
#include <algorithm>
#include <vector>
#define para(i,a,b)for(int i = a;i<b;++i)
using namespace std;
int main(){
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	int NT,M,W,wi,amount;
	scanf("%d",&NT);
	while(NT--){
		vector<int> v;
		scanf("%d %d",&M,&W);
		para(i,0,M){
			scanf("%d",&wi);
			v.push_back(wi);
		}
		sort(v.begin(),v.end());
		amount=0;
		para(i,0,M){
			W-=v[i];
			if(W<0)break;
			// printf(">> %d\n", v[i]);
			amount = amount + 1;
		}
		printf("%d\n", amount);
	}
	return 0;
}
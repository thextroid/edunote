#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define MAX 1000000
#define FOR(i,a,b)for (int i = (a); (i) < (b); ++i)
int v[51];
int op[3];
int ans[MAX+1];
void f(int N){
	FOR(i,1,N+1){
		ans[i]=false;
		FOR(j,0,3){
			if( i>=op[j]){
				if( ans[i-op[j]] == false){
					ans[i] = true;
				}
			}
		}
	}
}
int main(){
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	int K,L,M;
	op[0]=1;
	while(scanf("%d %d %d",&op[1],&op[2],&M) != EOF ){
		FOR(i,0,M)scanf("%d",&v[i]);
		f(1000000);
		FOR(i,0,M)
			printf("%c", (ans[v[i]]?'A':'B') );
		printf("\n");
	}
	return 0;
}
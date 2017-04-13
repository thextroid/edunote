#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 14
int vist[N+1];
int NT=1;
bool toc(const int &i,const int &j,const int &n){
	if(j<0)return false;
	for (int ii = 1; ii <= n; ++ii){
		if(vist[ii]==0)continue;
		int x = abs(ii-i);
		int y = abs(vist[ii]-j);
		if( x == y || ii==i || vist[ii] == j)
			return true;
	}
	return false;
}
void backtracking(int n,int x,int y,int k,bool &found){
	vist[x] = y;
	if(k==n-1){
		printf("%d : %d", NT++,vist[1]);
		for (int i = 2; i <= n; ++i)
			printf(" %d", vist[i]);
		printf("\n");
		found = true;
	}
	else{
		for (int j = 1; j <= n; ++j)
			if(vist[x+1]==0 && !toc(x+1,j,n))
				backtracking(n,x+1,j,k+1,found);
	}
	vist[x] = 0;
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int n;
	bool imposible;
	while(cin>>n){
		memset(vist,0,sizeof vist);
		NT=1;
		imposible = false;
		for (int i = 1; i <= n; ++i)
			backtracking(n,1,i,0,imposible);
		if(!imposible)
			printf("No Solution.\n");
	}
	return 0;
}
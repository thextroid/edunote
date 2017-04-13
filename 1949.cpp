#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,ii > iii;
typedef vector<int> vi;
typedef vector<iii> viii;
#define pz push_back
#define sz size
#define FOR(i,a,b)for (int i = (a); (i) < (b); ++i)
#define x first
#define y second
iii T[7];
bool vist[7];
void solve(int n,iii A,iii parent){
	if(){
		
	}
	else{
		vist[n] = true;
		FOR(i , 0 , 6){
			if(!vist[i]){
				iii B = P[i];
				if(A.x == B.y.x)
					solve(i,B,A);
			}
		}
	}
}
int main(){
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	int a,b,c;
	string i1;
	while(1){
		viii P;
		cin>>i1;
		if(i1[0]=='$')return 0;
		if(i1[0]=='*')continue;
		a = atoi( &i1[0] );
		cin>>b>>c;
		P.pz( iii(a,ii(b,c) ) );
		FOR(i,0,5){
			cin>>a>>b>>c;
			P.pz( iii( a , ii(b,c) ) );
		}
		FOR(i,0,6)
			printf("%d %d %d\n", P[i].x,P[i].y.x , P[i].y.y);
		printf("\n");
	}
	return 0;
}
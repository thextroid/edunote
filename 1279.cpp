#include <stdio.h>
#include <iostream>
#include <cstring>
using namespace std;
#define N 1000000
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	bool* p = new bool[N+2];
	int a,b;
	memset(p,0,sizeof p);
	p[1] = p[0]= true;
	for(int i = 4; i <=N ; i+=2)p[i] = true;
	for(int i = 3; i*i<=N ; i+=2)
		if(!p[i])
			for(int j = i*i ; j<=N;j+= (i<<1))
				p[j]=true;
	int* w = new int[N+1];
	int* X = new int[N+1];
	w[1]=X[1]=0;
	for (int i = 2; i <N; ++i){
		if(!p[i] )
			w[i] = w[i-1]+ ((i%4==1)?1:0);
		else
			w[i] += w[i-1];
		X[i] = X[i-1]+	!p[i];
	}
	while(cin>>a>>b){
		if(a<0 && b<0)return 0;
		printf("%d %d %d %d\n", a,b,X[b]-X[a-1],w[b]-w[a-1]);
	}
	return 0;
}
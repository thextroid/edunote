#include <iostream>
#include <stdio.h>
#define N 100000000
using namespace std;
bool p[N+2];
void _init(){
	int i,j;
	p[0] = p[1]=true;
	for(i = 2;i*i<N;i++)
		if(!p[i])
			for(j=i+i;j<N;j+=i)
				p[j]=true;
}
bool isprime(const int &n){
	return !p[n];
}
void backtrack(int n,int j){
	if(j==0){
		if(isprime(n))
			printf("%d\n", n);
		return;
	}
	int x = 0;
	for(int i = 1;i<=9;i++){
		x = n*10 + i;
		if(isprime(x))
			backtrack(x,j-1);
	}
}

int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	_init();
	int n;
	while(scanf("%d",&n)!=EOF)
		backtrack(0,n),printf("\n");

	delete[] p;
	return 0;
}
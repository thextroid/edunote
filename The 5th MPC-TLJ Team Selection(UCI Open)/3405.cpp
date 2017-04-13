#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int num[10];
/*Vampire Numbers*/
void solve(int n,int gen){
	for(int i = 0 ; i<=9;i++){
		if(num[i]>0){
			if(gen==0 && i==0)
				continue;
			int x = gen*10 + i;
			solve(n*x,x);
			solve(x,x);
		}
	}
}

void built(int n){
	while(n){
		num[n%10]++;
		n/=10;
	}
}
int main(){
	memset(num,0,sizeof num);
	int n;
	return 0;
}
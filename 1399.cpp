#include <iostream>
#include <stdio.h>
using namespace std;
void solve(int n){
	for (int i = 1; i <= (n); ++i){
		ans[i] = true;
		for (int j = 1; j <= 1; ++j){
			if( i>=j){
				if(ans[ i-j ] == 0){
					ans[ i ] = 1;
					break;
				}
			}
		}
	}
}
int main(){
	int a,b,c;
	while(1){
		cin>>a>>b>>c;
		if( a==0 && b==0 && c==0)break;

	}
	return 0;
}
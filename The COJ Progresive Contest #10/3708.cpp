/*
@author: thextroid 2016
problem name: juanma and the drinking fountains
*/
#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int nt,n;
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	cin>>nt;
	while(nt--){
		cin>>n;
		int a =1;
		for(int i = 1 ;i<=4;++i){
			a = a * (n-i+1);
			a = a / i;
		}
		a = 1 + a + ((n*(n-1))>>1);
		cout<<a<<endl;
	}
	return 0;
}
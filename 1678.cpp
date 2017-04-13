/*
* @author: thextroid  - Smaller Perimeter (theorem of inequality)
*/
#include <iostream>
#include <cstdio>
using namespace std;
inline int min(int &a,int &b){
	return a<b?a:b;
}
int main(){
	freopen("data.in","r",stdin);
	std::ios_base::sync_with_stdio(0);
	int n,a,b,c,best=301;
	cin>>n;
	while(n--){
		cin>>a>>b>>c;
		if(a+b>c && a+c>b && b+c>a)best = min(best,a+b+c);
	}
	printf("%d\n", best);
	return 0;
}
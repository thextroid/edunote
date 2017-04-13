#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	int a,b,c;
	while(cin>>a>>b>>c){
		if(a+b+c!=180)cout<<"Error";
		else if(a==b && b==c)cout<<"Equilateral";
		else if(a==b || b==c || a==c)cout<<"Isosceles";
		else cout<<"Scalene";
		cout<<'\n';
	}
	return 0;
}
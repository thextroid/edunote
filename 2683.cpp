#include <iostream>
#include <stdio.h>
using namespace std;
int v[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
void toBase(int x,int b){
	if(x==0)return;
	else{
		toBase(x/b,b);
		cout<<(v[x%b]);
	} 
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int t,n,b;
	cin>>t;
	while(t--){
		cin>>n>>b;
		toBase(n,b);
		 cout<<endl;
	}

	return 0;
}

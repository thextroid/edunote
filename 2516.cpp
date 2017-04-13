#include <iostream>
#include <cstdio>
#include <cstring>
#define FOR(i,a,b)for(int i = (a); i< (b);i++)
using namespace std;
string str;

int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int l[2900];
	int v[1000];
	l[1] = 0;
	v[0] = 1;
	for(int i = 1 ; i < 1000 ; i ++){
		if(i<10)
			v[i] = v[i-1]+1;
		else if(i<100)
			v[i] = v[i-1]+2;
		else if(i<1000)
			v[i] = v[i-1]+3;
		l[v[i]] = i;
	}
	while(cin>>str){
		int x = str.size();
		int loon = l[x];
		char p[4];
		x=0;
		int number = loon;
		while(loon){
			p[x++]=(loon%10)+'0';
			loon/=10;
		}
		p[x]='\0';
		int z = x;
		FOR(i,0,x/2)
			swap( p[i] , p[x-i-1] );
		string pat = string(p);
		x = str.size();
		int index = -1,mult=1;
		if(str[0]=='0' ){
			printf("0\n");
			continue;
		}
		string::size_type n = str.find(pat);
		while(n!=string::npos){
			if(str[n+z]=='0'){
				index=n+z;
				break;
			}
			n = str.find(pat,n+z);
		}
		loon = number;
		z = 0;
		while(index){
			if(loon>99)
				index-=3;
			else if(loon >9)
				index-=2;
			else
				index--;
			z++;
			loon = loon - mult;
		}
		cout<<z-1<<endl;
	}
	return 0;
}
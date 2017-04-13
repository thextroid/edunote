/*
*   @author:Eddy Cael
*	Adapted by Thextroid 24-01-2017
*/
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int zero = '0';//o char
string mult(string a,int n){
	int i,ex=0,r;
	for(i=a.size()-1;i>=0;i--){
		r=(a[i]-zero)*n;
		a[i]=zero+((r+ex)%10);
		ex=(r+ex)/10;
	}
	if(ex>0)
		a=char(ex + zero)+a;
	return a;
}

string add(string a,string b){
	if(a.size()>=b.size()){
		int i=a.size()-1,j=b.size()-1,r,ex=0,k;
		while(i>=0&&j>=0){
			r=a[i]+b[j]-96;
			a[i]=48+(r+ex)%10;
			ex=(r+ex)/10;
			i--;
			j--;
		}
		while(ex>0&&i>=0){
			r=a[i]-48+ex;
			a[i]=48+r%10;
			ex=r/10;
			i--;
		}
		if(ex>0){
			a=(char)(ex+48)+a;
		}
		k=0;
		while((a[k]=='0')&&(a.size()>1))
			a=a.substr(k+1);
		return a;
	}
	else return add(b,a);
}
string multiply(string a,string b){
	int i,j,k;
	string c="",p="0";
	for(j=0;j<b.size();j++){
		int digit = b[ b.size()-j-1 ] - zero;
		p =	add( p , mult(a,digit) + c);
		c =	c +"0";
	}
	return p;
}
int main(){
	// freopen("data.in","r",stdin);
	string a,b;
	int sign,n,i;
	cin>>n;
	while(n--){
		cin>>a>>b;
		sign=1;
		if(a[0]=='-'){
			a=a.substr(1);
			sign*= -1;
		}
		if(b[0]=='-'){
			b=b.substr(1);
			sign*= -1;
		}
		if(sign<0)	cout<<"-";
		cout<<multiply(a,b);
		cout<<'\n';
	}
	return 0;
}

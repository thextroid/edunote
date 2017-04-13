#include <stdio.h>
#include <iostream>
using namespace std;
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int n=6,diff=0,i,x,c,minor,major;
	double decimal = 0;
	while(1){
		i=diff=c=major=0;
		minor=(1<<30);
		while(i++<n){
			scanf("%d",&x);
			c += (x==0);
			diff+=x;
			major = max(major,x);
			minor = min(minor,x);
		}
		if(c==n)break;
		diff -=(major+minor);
		cout<< (diff)/4.0 <<endl;
	}
	return 0;
}
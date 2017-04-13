	#include <stdio.h>
	#include <iostream>
	#include <math.h>
	#define rep(i,a,b)for(int i = a;i<b;++i)
	using namespace std;
	#define N 100
	int main(){
		freopen("data.in","r",stdin);
		freopen("data.out","w",stdout);
		int n,k;
		double diff,x,y,x1,y1;
		while(cin>>n>>k){
			diff=0;
			cin>>x>>y;
			rep(i,1,n){
				cin>>x1>>y1;
				diff+=sqrt( ((x1-x)*(x1-x)) + ((y1-y)*(y1-y)) );
				x= x1;y= y1;
			}
			diff/=1000.0 ;
			diff*=20.0*k;
			printf("%.5lf\n", diff);
		}
		return 0;

	}
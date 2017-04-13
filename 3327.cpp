#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long int64;
int64 memo[20][20];
int64 solve(int even,int odd){
	if(even+odd==1)		return (even)?4L:5L;
	if(even==0 && odd==0)	return 1L;
	if(memo[even][odd]!=-1L)	return memo[even][odd];
	else{
		int64 diff=0;
		for (int i = 0; i < 10; ++i){
			if(i&1){
				if(odd>0)	diff += solve(even,odd-1);
			}
			else{
				if(even)	diff += solve(even-1,odd);
			}
		}
		return memo[even][odd] = diff;
	}
}
int f(int e,int o){
	int c = e+o,b=1,rem,ox,ex,x;
	while(c--){
		b*=10;
	}
	c = ex = ox = rem = 0;
	for(int i = 0;i<b;i++){
		x = i;
		ex = ox = 0;
		while(x){
			rem = x%10;
			if(rem&1){
				ox++;
			}
			else{
				ex++;
			}
			x/=10;
		}
		if(ex==e && ox==o)
			c++;
	}
	return c;
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int e,o;
	memset(memo,-1L,sizeof memo);
	while(cin>>e>>o){
		if(e==o && e==0)return 0;
		if(e==1 && !o)	cout<<"9"<<endl;
		else			cout<<solve(e,o)*2<<endl;
	}
	return 0;
}
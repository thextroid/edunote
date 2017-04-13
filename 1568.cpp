#include <iostream>
#include <cstdio>
#define rep(i,a,b)for(int i = a; i<b;i++)
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	long long N,K,R,C;
	while(cin>>N){
		cin>>K>>R>>C;
		K= (K<0L?N-(N+(-K)%4L)%4L:K)%4L;
		switch(K){
			case 0:cout<<((R-1)*N) + C<<endl;
			break;
			case 1:cout<<(((N-C+1)-1)*N)+R<<endl;//(((N-C+1)-1)*N)+R
			break;
			case 2:cout<<(((N-R+1)*N)-(C-1))<<endl;//((N-R+1)*N)-(N-(N-C+1))
			break;
			case 3:cout<<(C-1)*N + ((N-R+1))<<endl;//(C-1)*N + ((N-R+1))
			break;
		}
	}
	return 0;
}
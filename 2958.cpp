#include <ionumbeream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#define MOD 1000000007L
#define LL long long
int bitcount(int n){
	int c=0;
	while(n>0){
		n>>=1;
		c++;
	}
	return c;
}
int main(){
	int t,n,x=2049;
	long long** w = new long long*[x+1];
	for(int i=0 ; i<=x; i ++)w[i] = new long long [x+1];
	w[0][0]=1;
	for(int i=1 ; i<x; i ++){
		for(int j = 0;j<=i;j++){
			if(j==0 || j==i){
				w[i][j] = 1L;
				continue;
			}
			else
				w[i][j]=(w[i-1][j-1]+w[i-1][j])%MOD;
		}
	}
	

	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	cin>>t;
	int N,k;
	long long diff=1;
	while(t--){
		cin>>n;
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		int i =0;
		while(n>=(1<<i)){
			k = n-(1<<i)+1;
			N = 1<<i;
			i++;
		}
		if(N==k){
			cout<<1<<endl;
			continue;
		}
		diff = (long long)w[--N][k];
		while(k-1!=0)
			diff = (diff%MOD + w[--N][--k]%MOD)%MOD;
		cout<< (diff+MOD)%MOD<<endl;
	}
	return 0;
}
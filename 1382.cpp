#include <stdio.h>
#include <vector>
using namespace std;
#define pz push_back
#define sz size
#define LL long long
#define rep(i,a,b)for(LL i = a;i<b;i++)
#define N 1000001
const LL MOD =  1000007L;
int binary(const vector<LL>& v,int n,LL k){
	int mid,L=0,R = 1000000,best=-1;
	while(L<=R){
		mid = (L+R)>>1;
		if(v[mid]==k)
			return mid;
		if(v[mid]<k){
			best = mid;
			L = mid+1;
		}
		else{
			R = mid-1;
			best = mid;
		}

	}
	return best;
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int t;
	vector<LL> v;
	LL diff= 0L;
	v.pz(0);
	rep(i,1,N)
		v.pz(i*i*i);
	t=v.sz();
	int T=t;
	LL* w=new LL[t+1];
	w[0] = v[0];
	rep(i,1,t)
		w[i]= (v[i]%MOD)+(w[i-1]%MOD)%MOD;
	LL a,b;
	scanf("%d",&t);
	while(t--){
		scanf("%lld %lld",&a,&b);
		int i = binary(v,T,a);
		int j = binary(v,T,b);
		i-=(v[i]>=);
		j-=(v[j]>a);
		printf("%d", (w[j]-w[i]+MOD)%MOD);
		if(t)printf("\n");
	}
	return 0;
}
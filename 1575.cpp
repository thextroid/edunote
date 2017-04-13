#include <iostream>
#include <cstdio>
#include <algorithm>
#define FOR(i,a,b)for(int i =(a);i< (b);++i)
using namespace std;
int op(int* a, int n){
	int diff=0,len=n;
	while(n)	diff+=( a[n-1] * a[len-1+(n--)] );
	return diff;
}
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n,res=0;
	int A[16];
	while(cin>>n){
		FOR(i,0,n<<1)	cin>>A[i];
		res = op(A,n);
		sort(A,A+n);
		sort(A+n,A+(n<<1));
		res = min(res,op(A,n));
		while(next_permutation(A,A+n))		res = min(res,op(A,n));
		while(next_permutation(A+n,A+(n<<1) ) )		res = min(res,op(A,n));
		cout<<res<<"\n";
	}
	return 0;

}
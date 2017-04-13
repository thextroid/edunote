#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
void solve(int &n){
	double m = (n<<3) + 1;
	int square = sqrt(m);
	m = (sqrt(m) - 1.0) / 2.0;
	int sup = ceil(m);
	int inf = floor(m);
	int flag = (square*square == (n<<3) + 1);
	if(flag)inf--;
	inf = (inf*(inf+1))>>1;
	inf = n-inf-1;
	if(sup&1)
		cout<<"TERM "<< n <<" IS "<<sup-inf<<"/"<<1+inf;
	else
		cout<<"TERM "<< n <<" IS "<<1+inf<<"/"<<sup-inf;
	cout<<'\n';
}
int main(){
	std::ios_base::sync_with_stdio(false);
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int nt,n;
	cin>>nt;
	while(nt--){
		cin>>n;
		solve(n);
	}
	return 0;

}
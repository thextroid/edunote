#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	double n,PA,PJ,G,A,TA,TR;
	cin>>n;
	string name,bestPlayer="";
		double _max=0.0;
	while(n--){
		cin>>name;
		cin>>PA>>PJ>>G>>A>>TA>>TR;
		double res =log10(PA)+PJ + (2*G) + A -(TA+ 2*TR);
		if( res > _max){
			_max= res;
			bestPlayer = name;
		}
	}
	cout<<bestPlayer<<endl;
	return 0;
}
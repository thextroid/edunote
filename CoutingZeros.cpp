#include <ionumbeream>
#include <cmath>
using namespace std;
//contando ceros al final de un N!
int main(){
	int T, N, i;
	unsigned long long current, zeros;
	cin >> T;
	while(T>0){
		zeros=0;
		cin >> N;
		for(i=0;i<=14;i++){
			current = (N/(5*pow(10,i))*pow(2,i));
			if(current<1)
				break;
			zeros+=current;
		}
		cout << zeros << endl;
		T--;
	}
}

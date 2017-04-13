#include <ionumbeream>
#include <cstdio>
using namespace std;
int main(){
	int bit,mask1,mask2;
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	while(cin>>bit){
		mask1 = mask2 = 0;
		mask1 |= bit<<0;
		for(int i=1 ; i < 5 ;i++){
			cin>>bit;
			mask1 |= bit<<i;
		}
		for(int i=0 ; i <5 ;i++){
			cin>>bit;
			mask2 |= bit<<i;
		}
		mask1 ^= mask2;
		(mask1==31)?printf("Y\n"):printf("N\n");
	}
	return 0;
}
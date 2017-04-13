#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int vx['Z'+1];
	vx['A']=1001;
	vx['M']=1000;
	vx['D']=500;
	vx['C']=100;
	vx['L']=50;
	vx['X']=10;
	vx['V']=5;
	vx['I']=1;
	int NT,ans;
	cin>>NT;
	string roman;
	while(NT--){
		cin>>roman;
		char letter = 'A';
		ans = 0;
		for(int i = 0 ;i < roman.size();i++){
			if(vx[roman[i]]<=vx[letter]){
				letter = roman[i];
				ans += vx[roman[i]];
			}
			else {
				ans = ans + (vx[roman[i]]-vx[letter])-vx[letter];
				letter = roman[i];
			}
		}
		(ans%3==0)?printf("YES %d\n", ans):printf("NO %d\n", ans);
	}
	return 0;
}
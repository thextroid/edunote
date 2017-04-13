#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	char str[14];
	int i =1,x=0;
	while(scanf("%s",str)!=EOF){
		x=0;
		int S = str[0] + str[3] + str[5] + str[8] + str[10] +str[12] - 6*'0';
		S*=3;
		S = S + (str[2]+str[4]+str[6]+str[9]+str[11] - 5*'0');
		// printf(">> %d\n",S);
		if(S%10!=0)
			x = 10 - S%10;
		printf("Case #%d: %d\n", i++,x);
	}
	return 0;
}
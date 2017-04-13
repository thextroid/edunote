/*
* @uthor: thextroid - Big Powers
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int main(){
	// cout<<char(64)<<endl;
	int pattern[10][4]={ {1},{1},{2,4,8,6},{1,3,9,7},{4,6},{5},{6},{1,7,9,3},{8,4,2,6},{1,9}};
	freopen("data.in","r",stdin);
	char m[102],n[102];
	while(scanf("%s %s",m,n)==2 && m[0]!='0' && n[0]!='0'){
		// printf("length: %d\n", strlen(m));
		int len= (int)strlen(n)-1,i=-1,M=m[(int)strlen(m)-1]-'0',N=0,MOD=1;
		if(M<2 || (M>4 && M<7) )MOD=1;
		if( (M>1 && M<4) || (M>6 && M<9) )MOD=4;
		if( M==4 || M==9) MOD=2;
		while(n[++i]!='\0'){
			N += ((n[i]-'0')*(int)pow(10,len%MOD))%MOD;
			len--;
		}
		N%=MOD;
		// printf(">> %d %d\n", M,N);
		if(M==2||M==4||M==8)
		printf("%d\n", pattern[M][N-1]);
		else
		printf("%d\n", pattern[M][N]);


	}
	return 0;
}
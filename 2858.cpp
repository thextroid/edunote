#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
#define MOD 1000000007
char s[10003];
int fast_exp(int b, int n){
  int res = 1;
  int x = b;
  while (n > 0) {
    if (n & 0x01) {
      n--;
      res = (res * x) % MOD;
    } else {
      n >>= 1;
      x = (x * x) % MOD;
    }
  }
  return res;
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	char out[10005];
	int i,j,diff,k;
	while(scanf("%s",s)!=EOF){
		i=strlen(s)-1;
		diff=j=k=0;
		while(i>=0){
			if(s[i]=='1' ||s[i]=='0'){
				if(s[i]=='0'){
					j++;
				}
				else{
					diff = ((diff + fast_exp(2,j++))+MOD)%MOD;
				}
			}else{
				if(diff!=0){
					while(diff){
						out[k++]=(diff%10)+'0';
						diff/=10;
					}
				}
				else if(j>0){
					out[k++]='0';
				}
				out[k++] = s[i];
				diff=j=0;
			}
			i--;
		}
		if(j>0){
			if(diff==0)
				out[k++]='0';
			else{
				while(diff){
					out[k++]=(diff%10)+'0';
					diff/=10;
				}
			}

		}
		while(k--)
			printf("%c", out[k]);
		printf("\n");
	}
	return 0;
}
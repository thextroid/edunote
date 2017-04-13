#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#define FOR(i,a,b)for(int i = a ; i<b;i++)
using namespace std;
const string hexa="0123456789ABCDEF";
const int deci[16]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
map<char,int> mp;
void build(){
	FOR(i,0,16)
		mp[hexa[i]]=deci[i];
}
int calc(char *a,char *b){
	int i=0,j,ta=strlen(a),tb=strlen(b),nacc=0,acc=0;
	for(;i<max(ta,tb);){
		int xa = mp[a[ta-i-1]];
		int xb = mp[b[tb-i-1]];
		if(ta-i-1 <0)
			xa = 0;
		if(tb-i-1 <0)
			xb = 0;
		int x = acc + xa + xb;
		if(x>15){
			nacc++;
		}
		acc = x/16;
		// printf("acarreo hex: %c\n", hexa[acc]);
		i++;
	}
	return nacc;

}
int main(){
	build();
	char a[257],b[257];
	int n;
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&n);
	while(n--){
		scanf("%s %s",a,b);
		printf("%d\n", calc(a,b));
	}
	return 0;
}
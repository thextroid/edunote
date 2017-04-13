/*solved by Thextroid 2015*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>
#include <algorithm>
#define FOR(i,a,b)for(int i = (a);i<(b);i++)
using namespace std;
int toDecimal(char* n,int b,int start){
	int dec=0,t=strlen(n),k=0;
	for(int i = t-1; i>=start ;i--)
		dec += (n[i]-'0')*pow(b,k++);
	return dec;
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	char n2[40],n3[40];
	int t;
	vector<int> v;
	while(scanf("%s",&n2[1])!=EOF){
		scanf("%s",&n3[1]);
		n2[0] = '1';
		v.push_back(toDecimal(n2,2,0));
		for(int i = 1 ; n2[i]!='\0';i++){
			n2[i]=(n2[i]-'0')?'0':'1';
			v.push_back(toDecimal(n2,2,1) );
			n2[i]=(n2[i]-'0')?'0':'1';
		}
		sort(v.begin(),v.end());
		n3[0] = '1';
		v.push_back(toDecimal(n3,3,0));
		int found=-1;
		for(int i = 1 ; n3[i]!='\0' && found==-1;i++){
			for(char j = '0' ; j <='2' ;j++){
				if(n3[i]!=j){
					char temp = n3[i];
					n3[i] = j;
					int x = toDecimal(n3,3,1);
					if( binary_search(v.begin(),v.end(),x) ){
						found=x;
						break;
					}
					n3[i]=temp;
				}
			}
		}
		printf("%d\n", found);
	}

	return 0;
}
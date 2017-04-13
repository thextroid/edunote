#include <iostream>
#include <cstdio>
#define AGRESIVE 1
#define CALM 0
using namespace std;
int a,b,c,d,i,j,k,dog1[2000],dog2[2000];
void calculate(int p){
	for(i = 1;i<1000;i+=a+b){
		for(j = i;j<i+a;j++)	dog1[j] = AGRESIVE;
		for(k = j;k<j+b;k++)	dog1[k] = CALM;
	}
	for(i = 1;i<1000;i+=c+d){
		for(j = i;j<i+c;j++)	dog2[j] = AGRESIVE;
		for(k = j;k<j+d;k++)	dog2[k] = CALM;
	}
	if(dog1[p]==CALM && dog2[p]==CALM)		printf("none\n");
	else if(dog1[p]==AGRESIVE && dog2[p]==AGRESIVE)	printf("both\n");
	else		printf("one\n");
}
int main(){
	std::ios_base::sync_with_stdio(0);
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int p,m,g;
	while(cin>>a>>b>>c>>d){
		cin>>p>>m>>g;
		calculate(p);
		calculate(m);
		calculate(g);
	}
	return 0;
}
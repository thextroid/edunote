#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <map>
#include <vector>
#include <set>
using namespace std;
int num[10],v[10022];
bool vist[10];
set<int> dic;
vector<int> p;
int nd,sz;
bool isprime(int n){
	if(n==1)return false;
	if(n>2 && (n&1)==0 || n==9)return false;
	int i=0;
	while(p[i]*p[i]<n){
		if(n%p[i]==0)	return false;
		i++;
	}
	return true;
}
int totalprimes=0;
void generate(int n,int i){
	if(i==nd){
		int x =0;
		while(n){
			x = x*10 + (n%10);
			n/=10;
		}
		if( dic.find(x)==dic.end() ){
			dic.insert(x);
			totalprimes += ( isprime(x) );
		}
		return;
	}
	for(int j = 0 ; j< nd;j++){
		if(!vist[j] ){
			
				vist[j] = true;
				generate(n*10 + num[j],i+1);
				vist[j]= false;
		}
	}
}


int main(){
	int n,i,j;
	v[1]=v[0]=true;
	for(i =2 ; i*i < 10020;++i)
		if(!v[i])
			for (j = i+i; j < 10020; j+=i)
				v[j] = true;
	for (int i = 2; i < 10020; ++i)
		if(!v[i])
			p.push_back(i);
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	sz = p.size();
	while(scanf("%d",&n)!=EOF){
		totalprimes=0;
		memset(vist,false,sizeof vist);
		i=0;
		if(n<10){
			printf("0\n");
			continue;
		}
		while(n){
			num[i++] = n%10;
			n/=10;
		}
		nd=i;
		sort(num,num+nd);
		int x = 0;
		for (i = 0; i < nd; ++i)
			x = x*10 + num[i];
		generate(0,0);
		if( dic.find(x)==dic.end() )
			totalprimes += isprime(x);
		printf("%d\n", totalprimes);
		dic.clear();
	}
	return 0;
}
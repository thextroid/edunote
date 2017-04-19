// #include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#define rep(i,a,b) for(int i=a;i<b;i++)
#define pz push_back
enum VISITED{ cancel,ok,pending };
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef vector<iii> viii;
int n;
int countBit(int& x,int guion=0){
	int i=-1,count=0;
	while(x>>(++i))
		if( !(guion&(1<<i) ) )
			count+= ( (x&(1<<i))>>i);//cuenta los bit encendidos (1's)
	return count;
}
bool cmp(ii a,ii b){return countBit(a.first)<countBit(b.second);}
void toMask(int &a,int mask=0){
	int i=n;
	cout.fill('0');
	while(i--)
		if(!(mask&(1<<i)) )	printf("%d",(a&(1<<i))>>(i));//muestra el (i-esimo)bit que no es (-)
		else 				printf("-");
}
int isAdjacent(int& a,int& b,int u=0,int v=0){
	int i = 0,adjacency=0,bit=0,x = a^b,someSign,y=u^v;
	if(y!=0)return 0;
	while(x){
		bit=(x&1)&!(u&1);//verifica los bits(0,1) adyacentes, excluyendo los (-)
		adjacency += bit;//conteo de los bits adyacentes
		v = v | (bit<<(i++));//v -> contruye una maskara de adyacencia, para simular los (-)
		x >>= 1,u >>= 1;
	}
	return adjacency==1?v:0;// la adyacencia debe ser de solo "un" bit(0 o 1)
}
vii v,term,unchecked, rest;
void McClusky(){
	sort(v.begin(),v.end(),cmp);
	int iter=1;
	while(1){
		viii group[n+1];
		for(vii::iterator i = v.begin();i!=v.end();i++)
			group[countBit(i->first,i->second)].pz( iii( i->first, ii(i->second,cancel) ) );
		v.clear();
		term.assign(v.begin(),v.end());
		map<ii,int> mp;
		rest.assign(unchecked.begin(),unchecked.end());
		unchecked.clear();
		int x,y,s1,s2,adjacent,reset=1,flag=1;
		rep(g,0,n){
			rep(i,0,group[g].size() ){
				x = group[g][i].first,	s1 = group[g][i].second.first;
				rep(j,0,group[g+1].size()){
					y = group[g+1][j].first,	s2 = group[g+1][j].second.first;
					adjacent = isAdjacent(x,y,s1,s2);
					if( adjacent ){
						group[g][i].second.second = ok,
						group[g+1][j].second.second = ok;// dos parejas distintas que debe ser checkeadas
						if( mp[ii(x,adjacent)])	continue;//dos pares distintos, que generan un patron ya registrado
						mp[ii(x,adjacent)]=1,v.pz(ii(x,adjacent));
						reset=1;
					}
				}
				if(group[g][i].second.second==cancel )	unchecked.pz(ii(x,s1));
			}
		}
		if(!v.size())break;
		printf("=========== ITERACION  %d ===========\n",(iter++));
		rep(j,0,v.size()){toMask(v[j].first,v[j].second);printf("\n");}
	}
	printf("_______________________________\n");
	sort(term.begin(),term.end());
	rep(j,0,term.size()){toMask(term[j].first,term[j].second);printf("\n");}
	rep(j,0,rest.size()){toMask(rest[j].first,rest[j].second);printf("\n");}
}
void manually(vii& v){
	int a;
	while(scanf("%d",&a)!=EOF && a!=-1)	v.pz(ii(a,0));
}
inline void shurfle(vii& v){
	int a=1<<n;
	set<int> tmp;
	rep(i,0,a)	tmp.insert(rand()%a);
	for(set<int>::iterator it=tmp.begin();it!=tmp.end();it++)
		v.pz(ii(*it,0)),	cout<<(*it)<<" ";
	cout<<endl;
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	while(scanf("%d",&n)!=EOF){
		if(n>20 || n==0) break;
		// shurfle(v);
		manually(v);
		// guion.resize(v.size(),0);
		McClusky();
	}
	return 0;
}

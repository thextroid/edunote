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
typedef vector<ii> vii;
int n;
int countBit(int& x,int guion=0){
	int i=-1,count=0;
	while(x>>(++i))
		if( !(guion&(1<<i) ) )
			count+= ( (x&(1<<i))>>i);//cuenta los bit encendidos (1's)
	return count;
}
bool cmp(int a,int b){return countBit(a)<countBit(b);}
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
vi v,guion,term;
void McClusky(){
	sort(v.begin(),v.end(),cmp);
	int iter=1;
	vii unchecked, rest;
	while(1){
		vi group[n+1], sign[n+1], vist[n+1];
		rep(j,0,v.size() ){
			group[countBit(v[j],guion[j])].pz(v[j]),
			sign[countBit(v[j],guion[j])].pz(guion[j]),
			vist[countBit(v[j],guion[j])].pz(cancel);
		}
		v.clear();
		term.assign(v.begin(),v.end());
		guion.clear();
		map<ii,int> mp;
		rest.assign(unchecked.begin(),unchecked.end());
		unchecked.clear();
		int x,y,s1,s2,adjacent,reset=1,flag=1;
		rep(g,0,n){
			rep(i,0,group[g].size()){
				x = group[g][i],	s1 = sign[g][i];
				rep(j,0,group[g+1].size()){
					y = group[g+1][j],	s2 = sign[g+1][j];
					adjacent = isAdjacent(x,y,s1,s2);
					if( adjacent ){
						vist[g][i]= ok;vist[g+1][j]= ok;// dos parejas distintas que debe ser checkeadas
						if( mp[ii(x,adjacent)])	continue;//dos pares distintos, que generan un patron ya registrado
						mp[ii(x,adjacent)]=1,v.pz(x),guion.pz(adjacent);
						reset=1;
					}
				}
				if(vist[g][i]==cancel )	unchecked.pz(ii(x,s1));
			}
		}
		if(!v.size())break;
		printf("=========== ITERACION  %d ===========\n",(iter++));
		rep(j,0,v.size()){toMask(v[j],guion[j]);printf("\n");}
	}
	printf("_______________________________\n");
	rep(j,0,term.size()){toMask(term[j],guion[j]);printf("\n");}
	rep(j,0,rest.size()){toMask(rest[j].first,rest[j].second);printf("\n");}
}
void manually(vi& v){
	int a;
	while(scanf("%d",&a)!=EOF && a!=-1)	v.pz(a);
}
inline void shurfle(vi& v){
	int a=1<<n;
	set<int> tmp;
	rep(i,0,a)	tmp.insert(rand()%a);
	for(set<int>::iterator it=tmp.begin();it!=tmp.end();it++)
		v.pz(*it),	cout<<(*it)<<" ";
	cout<<endl;
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	while(scanf("%d",&n)!=EOF){
		if(n>20 || n==0) break;
		// shurfle(v);
		manually(v);
		guion.resize(v.size(),0);
		McClusky();
	}
	return 0;
}

/*
@Author: thextroid
problem name: Royale with Cheese
*/
#include <iostream>
#include <cstring>
#include <cstdio>
#define FOR(i,a,b)for(int i=a;i<b;++i)
using namespace std;
int main(){
	string s;
	int vist[27];
	int dic[27];
	memset(dic,0,sizeof dic);
	dic[2]=5;
	dic[5]=2;
	dic[6]=9;
	dic[9]=6;
	dic[12]=15;
	dic[15]=12;
	dic[16]=19;
	dic[19]=16;
	dic[20]=50;
	dic[21]=51;
	dic[22]=55;
	dic[23]=53;
	dic[24]=54;
	dic[25]=52;
	dic[26]=59;
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	while(cin>>s){
		memset(vist,0,sizeof vist);
		int j=0;
		FOR(i,0,s.size()){
			if(!vist[s[i]-'a'+1])
				vist[s[i]-'a'+1] = ++j;
			(dic[vist[s[i]-'a'+1]]!=0)?printf("%d", dic[vist[s[i]-'a'+1]]):printf("%d", vist[s[i]-'a'+1]);
		}
		printf("\n");
	}
	return 0;
}
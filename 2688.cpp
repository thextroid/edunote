#include <iostream>
#include <cstdio>
#include <string.h>
#include <set>
#include <algorithm>
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	string set1,set2 , name1,name2;
	int n,m;
	char v[51],w[51];
	while(cin>>set1){
		cin>>name1;
		cin>>n;
		set<char> unique;
		for(int  i = 0 ; i < n ; i++){
			cin>>v[i];
			unique.insert(v[i]);
		}
		cin>>set2;
		cin>>name2;
		cin>>m;
		for(int  i = 0 ; i < m ; i++){
			cin>>w[i];
			unique.insert(w[i]);
		}
		sort(v,v+n);
		sort(w,w+m);
		cout<<name1<<" U "<<name2<<": {";
		bool flag= 0;
		for(set<char>::iterator  it = unique.begin() ; it!=unique.end(); it++){
			if(!flag){
				printf("%c", *it);
				flag = !flag;
			}
			else
				printf(",%c", *it);
		}
		printf("}\n");
		cout<<name1<<" I "<<name2<<": {";
		for(int i = 0,flag=0 ; i < n ;i++){
			if( binary_search(w,w+n,v[i]) ){
				if(!flag){
					printf("%c", v[i]);
					flag= !flag;
				}
				else
					printf(",%c", v[i]);
			}
		}
		printf("}\n");
		cout<<name1<<" D "<<name2<<": {";
		for(int i = 0,flag=0 ; i < n ;i++){
			if( !binary_search(w,w+m,v[i]) ){
				if(!flag){
					printf("%c", v[i]);
					flag= !flag;
				}
				else
					printf(",%c", v[i]);
			}
		}
		printf("}\n");
		cout<<name2<<" D "<<name1<<": {";
		for(int i = 0,flag=0 ; i < m ;i++){
			if( !binary_search(v,v+n,w[i]) ){
				if(!flag){
					printf("%c", w[i]);
					flag= !flag;
				}
				else
					printf(",%c", w[i]);
			}
		}
		printf("}\n");

	}
	return 0;
}
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define MAX 20002
using namespace std;
string line;
int key[MAX], symbol[MAX], L[MAX], R[MAX], cont=1;
void add(int node,int value){
	if(key[node]==0){
		key[node] = value;
		symbol[node]= line[cont++];
	}
	else if(value < key[node]){
		if(L[node]==0)
			L[node] = value;
		add(L[node],value);
	}
	else{
		if(R[node]==0)
			R[node] = value;
		add(R[node],value);
	}
}
void decode(int a,int b,int root){
	if(b-a>0){
		int mid=(a+b-1)>>1;
		add(root,mid);
		decode(a,mid,root);
		decode(mid+1,b,root);
	}
}
void print(int n){
	for(int mid = 1,letter=0 ; mid < n ;mid++,letter=0){
		if(symbol[mid]!=0){
			if(symbol[mid]=='A' ) 		letter=25;
			else if(symbol[mid]=='a' )	letter=25;
			else if((symbol[mid]>='b' && symbol[mid]<='z')||(symbol[mid]>='B' && symbol[mid]<='Z'))
				letter=-1;
			printf("%c", symbol[mid]+letter);
		}
	}printf("\n");
}
int main(){
	std::ios_base::sync_with_stdio(0);
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	
	while(getline(cin,line)){
		int a = 1;
		line="@"+line;
		int b = line.size();
		int root=(a+b-1)>>1;
		fill(L 		,L+b+1		,0);
		fill(R 		,R+b+1		,0);
		fill(key	,key+b+1	,0);
		fill(symbol	,symbol+b+1	,0);
		cont=1;
		decode(a,b,root);
		print(b);
	}
	return 0;
}
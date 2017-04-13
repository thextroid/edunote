#include <iostream>
#include <stdio.h>
#include <set>
#include <string.h>
#define N 32
using namespace std;
int L[N], R[N], data[N];
int root=-1,nodos=0;

int crear_nodo(int dato){
	data[nodos]=dato;
	L[nodos]=-1;
	R[nodos]=-1;
	return nodos++;
}
void put(int n,int r){
	if(n<data[r]){
		if(L[r]==-1)
			L[r] = crear_nodo(n);
		else
			put(n,L[r]);
	}
	else{
		if(R[r]==-1)
			R[r] = crear_nodo(n);
		else
			put(n,R[r]);	
	}
}

int f(int T){
	if(T==-1)
		return 0;
	else{
		int x = (L[T]==-1?1:f(L[T]));
		int y = (R[T]==-1?0:f(R[T]));
		return data[T] * x + y;
	}
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int t,n,x;
	cin>>t;
	set<int> dic;
	while(t--){
		cin>>n;
		cin>>x;
		dic.insert(x);
		int ROOT = crear_nodo(x);
		for (int i = 1; i < n; ++i){
			cin>>x;
			if(dic.find(x)!=dic.end())
				while(1);
			put(x,ROOT);
		}
		printf("%d\n", f(ROOT));
		dic.clear();
	}
	return 0;
}
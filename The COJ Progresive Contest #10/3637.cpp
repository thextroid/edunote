#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
#define pz push_back
#define MAX 500
#define FOR(i,a,b)for(int i=(a);i<(b);++i)
using namespace std;
int *v = new int[MAX+1];
// bool edge[MAX+1][MAX+1];
vector<int> edge[MAX+1];
int *visitado = new int[MAX+1];

int bfs(int origen,int destino,int n){
	fill(visitado,visitado+n+1,0);
	queue<int> q;
	printf("%d %d \n", origen,destino);
	q.push(origen);
	while( !q.empty() ){
		int actual = q.front();
		printf("%d ", actual);
		q.pop();
		if(actual==destino)break;
		visitado[actual] = 1;
		for(int i = 0 ; i<edge[actual].size();i++){
			if( visitado[edge[actual][i]] ==0){
				q.push( edge[actual][i] );
			}
		}
	}
	printf("\n");
	return 0;
}
int main(){
	int n,u,w,tipo,q;
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	while(scanf("%d",&n)!=EOF){
		scanf("%d",&v[0]);
		FOR(i,1,n)	scanf(" %d",&v[i]);
		FOR(i,0,n-1){
			scanf("%d %d",&u,&w);
			edge[u].pz(w);
			edge[w].pz(u);
		}
		scanf("%d",&q);
		while(q--){
            scanf("%d %d %d",&tipo,&u,&w);
            bfs(u,w,n);
		}
	}
	return 0;
}

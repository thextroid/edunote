#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#define rep(i,a,b)for (int i = a; i < b; ++i)
#define MAX 1000
#define pz push_back
#define sz size
#define x first
#define y second
#define mk make_pair
#define mki(a,b,c) make_pair(make_pair(a,b),c)
#define INF 1000000000
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<int> vi;
typedef vector< ii > vii;
typedef vector<iii> viii;
typedef vector< iii > viii;
typedef vector< viii > graph;
int N,E,S,T;

class Comparator{
public:
	int operator() (const iii &A,const iii &B){
		if(A.y < B.y)
			return -1;
		if(A.y == B.y){
			return A.x.y < A.x.y?-1:1;
		}
		return 1;
	}
};
vii dijsktra(int u,int v,graph &g){
	vii d;
	int n = g.sz();
	d.resize(n+1);
	rep(i,0,n)
		d[i] = mk(0,INF);
	priority_queue< iii ,viii, Comparator > q;
	d[u] = mk(0,0);
	q.push( mki(u,0,0) );
	while(!q.empty()){
		// printf("\n");
		int nodo = q.top().x.x;
		int Di = d[nodo].x;
		int Dk = q.top().y;
		if(nodo == v )break;
		q.pop();
		rep(next,0,g[nodo].sz()){
			int A = g[nodo][next].x.x;
			int D = g[nodo][next].x.y;
			int K = g[nodo][next].y;
			K = (K==0)?D:K;
			if(K>0 && Dk+K < d[A].y){
				// printf("from[%d](%d,%d) - > to[%d](%d,%d)\n", nodo,Di,Dk,A, D,K  );
				// printf("min dis (%d,%d) [%d]\n", d[A].x ,Di+D,A);
				// printf("min dis (%d,%d) [%d]\n", d[A].x ,Di+D,A);
				d[A] = mk(Di+D,Dk+K);
				q.push(mki(A,Di+D,Dk+K));
			}
			else if(Dk+K == d[A].y){
				// printf("[%d - > %d]min (%d,%d)\n", nodo,A, Dk+K , Di+D);
				// printf("min dis (%d,%d) [%d]\n", d[A].x ,Di+D,A);
				d[A].x = min(d[A].x,Di+D);
				// printf("new %d\n", d[A].x);
				q.push(mki(A,Di+D,Dk+K));
			}

		}
	}
	return d;
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int u,v,d,k;
	while(scanf("%d",&N)!=EOF){
		scanf("%d %d %d",&E,&S,&T);
		graph g;
		g.resize(N);
		rep(i, 0 ,E){
			scanf("%d %d %d %d",&u,&v,&d,&k);
			g[u].pz( mki(v,d,k) );
			g[v].pz( mki(u,d,k) );
		}
		// rep(i, 0 ,E){
		// 	rep(j, 0 ,g[i].sz()){
		// 		printf("%d->%d (%d,%d)\n", i,g[i][j].x.x,g[i][j].x.y,g[i][j].y);
		// 	}
		// }
		// printf(">>%d\n", g.sz());
		vii res = dijsktra(S,T,g);
		printf("%d %d\n", res[T].x,res[T].y);
	}
	return 0;
}
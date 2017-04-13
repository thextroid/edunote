#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
typedef vector<int> vi;

void build(vi &t, const vi &A,int vertex, int L, int R){
	if( L == R)
		t[vertex] = L;
	else{
		int nL = vertex << 1, nR = (vertex << 1) + 1;
		build( t , A , nL ,         L           ,    ( L + R )>>1    );
		build( t , A , nR , ( ( L + R )>>1 ) +1 ,       R            );
		int lContent = t[nL] , rContent = t[nR];
		int lValue = A[lContent] , rValue = A[rContent];
		t[vertex] = (lValue <= rValue )? lContent : rContent;
	}
}

void create(vi &t , const vi &A){
	int len = (int)( 2 * pow(2.0, floor( (log((double)A.size()) / log(2.0) ) + 1 ) ) );
	t.assign(len , 0);
	build(t , A , 1 , 0 , (int)A.size() - 1);
}
int rmq(vi &t, const vi &A , int vertex, int L , int R , int i , int j){
	if(i > R || j < L) return -1;
	if(L >= i && R <= j)return t[vertex];
	int p1 = rmq( t , A , vertex << 1   ,           L 	    , (L+R)>>1 	, i , j);
	int p2 = rmq( t , A , (vertex<<1)+1	,   ((L+R)>>1) + 1  ,     R     , i , j);
	if(p1 == -1)return p2;
	if(p2 == -1)return p1;
	return (A[p1] <= A[p2])? p1 : p2;
}
int rmq(vi &t , const vi &A , int i , int j){
	return rmq(t , A , 1 , 0 , (int)A.size() -1 , i , j);
}
int main(){
	int v[]={8 , 7 , 3 , 9 , 5 , 1 , 10};
	vi A(v , v + 7);
	vi st;
	create(st , A);
	printf("RMQ(1,3) = %d\n", rmq(st, A, 1 , 3));
	printf("RMQ(4,6) = %d\n", rmq(st, A, 4 , 6));
	return 0;
}

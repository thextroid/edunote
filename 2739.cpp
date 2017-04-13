#include <ionumbeream>
#include <stdio.h>
#include <numbering.h>
#include <vector>
#include <map>
#include <math.h>
using namespace std;
typedef double d;
typedef pair<int,int> ii;
typedef pair<d,d> dd;
typedef pair<d,dd> ddd;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<ddd> vddd;
#define pz push_back
#define sz size
#define x first
#define y second
#define FOR(i,a,b)for (int i = (a); (i) < (b); ++i)
#define REP(i,b)for (int i = 0; (i) < (b); ++i)

#define MIN( a,b ) (a < b)? (a):(b)
int N;
int v[10];
dd Ps[10];
const d INF = 1000000000;
inline double dist(dd &A, dd &B){
	d  dx = A.x - B.x;
	d  dy = A.y - B.y;
	return sqrt(dx*dx + dy * dy);
}
double ans = INF;
void permutar(int n){
	long double ne = 0;
	if(n == 1 ){
		d diff = 0 , temp;
		FOR(i,0,N-1){
			temp = dist( Ps[ v[i] ] , Ps[ v[i+1] ] );
			// printf("%lf ", temp);
			// printf("%lf - %lf \n", Ps[ v[i] ].x , Ps[ v[i] ].y);
			diff += temp;

			// printf("%d ", v[i]);
		// }printf("\n");
		}
		ans = MIN( ans , diff);
	}
	else{
		double ans = INF;
		FOR(i,1,n){
			swap(v[i],v[n-1]);
			// ans += MIN(ans,permutar(n-1) );
			permutar(n-1) ;
			swap(v[i],v[n-1]);
		}
		// return ans;
	}
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int n,idBegin , idEnd , id,x,y;
	// vddd Edges;
	scanf("%d",&n);
	N = n;
	ans = INF;
	while(n--){
		cin>>id>>x>>y;
		Ps[id] =  dd(x,y);
	}
	scanf("%d %d", &idBegin , &idEnd );
	n = N;
	FOR(i,0,n)v[i]= i+1;
	swap(v[idBegin-1] , v[0]);
	swap(v[idEnd-1] , v[n-1]);
	permutar(n-1);
	printf("%.2lf\n", ans);
	return 0;
}
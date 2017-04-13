#include <iostream>
#include <cstdio>
#define FOR(i,a,b)for(int i = a;i<b;i++)
#define INF 1000000000
using namespace std;

int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int n,a,b,resp,ans,index_year_start,first_year;
	int v[2015][2];
	while(cin>>n){
		resp = INF;
		FOR(i,0,n)
			cin>>v[i][0]>>v[i][1];
		index_year_start = 0;
		FOR(i,0,n-2){
			ans=0;
			first_year = i;
			int asc=0,failed=0;
			for(int j = i ;j<i+3;j++){
				if(v[j][0]<=asc){
					failed = 1;
					break;
				}
				else{
					asc=v[j][0];
				}
				ans += v[j][1];
			}
			if(failed)
				continue;
			if(ans<resp){
				resp = ans;
				index_year_start = first_year;
			}
			else if( ans==resp ){
				if(v[first_year][0] > v[index_year_start][0] ){
					index_year_start= first_year;
				}
			}
		}
		printf("%d", v[index_year_start][0]);
		FOR(i,index_year_start+1,index_year_start+3)
			printf(" %d",v[i][0] );
		printf("\n");

	}
	return 0;
}
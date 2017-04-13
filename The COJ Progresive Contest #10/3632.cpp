#include <iostream>
#include <cstdio>
#include <cstdlib>
#define Nmax 100000
#define forab(i,a,b)for(int i=a;i<b;++i)
using namespace std;
int main(){
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	int** ac = new int*[10];
	forab(i,0,10)
		ac[i]=new int[Nmax+1];
	int* v = new int[Nmax];
	int n,q,a,b;
	while(scanf("%d",&n)>0){
		forab(i,1,n+1)scanf("%d",&v[i]);
		ac[0][0]=ac[1][0]=ac[2][0]=ac[3][0]=ac[4][0]=ac[5][0]=ac[6][0]=ac[7][0]=ac[8][0]=ac[9][0]=0;
		forab(i,1,n+1){
			ac[0][i] = ac[0][i-1]+ (v[i] == 0);
			ac[1][i] = ac[1][i-1]+ (v[i] == 1);
			ac[2][i] = ac[2][i-1]+ (v[i] == 2);
			ac[3][i] = ac[3][i-1]+ (v[i] == 3);
			ac[4][i] = ac[4][i-1]+ (v[i] == 4);
			ac[5][i] = ac[5][i-1]+ (v[i] == 5);
			ac[6][i] = ac[6][i-1]+ (v[i] == 6);
			ac[7][i] = ac[7][i-1]+ (v[i] == 7);
			ac[8][i] = ac[8][i-1]+ (v[i] == 8);
			ac[9][i] = ac[9][i-1]+ (v[i] == 9);
		}
		// printf("0: ");forab(i,1,n+1)printf("%d ", ac[0][i]);printf("\n");
		// printf("1: ");forab(i,1,n+1)printf("%d ", ac[1][i]);printf("\n");
		// printf("2: ");forab(i,1,n+1)printf("%d ", ac[2][i]);printf("\n");
		// printf("3: ");forab(i,1,n+1)printf("%d ", ac[3][i]);printf("\n");
		// printf("4: ");forab(i,1,n+1)printf("%d ", ac[4][i]);printf("\n");
		// printf("5: ");forab(i,1,n+1)printf("%d ", ac[5][i]);printf("\n");
		// printf("6: ");forab(i,1,n+1)printf("%d ", ac[6][i]);printf("\n");
		// printf("7: ");forab(i,1,n+1)printf("%d ", ac[7][i]);printf("\n");
		// printf("8: ");forab(i,1,n+1)printf("%d ", ac[8][i]);printf("\n");
		// printf("9: ");forab(i,1,n+1)printf("%d ", ac[9][i]);printf("\n");
		// printf("\n");
		scanf("%d",&q);
		while(q--){
			scanf("%d %d",&a,&b);
			int ans=0;
			ans += (ac[0][b]-ac[0][a-1]>0);
			ans += (ac[1][b]-ac[1][a-1]>0);
			ans += (ac[2][b]-ac[2][a-1]>0);
			ans += (ac[3][b]-ac[3][a-1]>0);
			ans += (ac[4][b]-ac[4][a-1]>0);
			ans += (ac[5][b]-ac[5][a-1]>0);
			ans += (ac[6][b]-ac[6][a-1]>0);
			ans += (ac[7][b]-ac[7][a-1]>0);
			ans += (ac[8][b]-ac[8][a-1]>0);
			ans += (ac[9][b]-ac[9][a-1]>0);
			printf("%d\n", ans);
		}
	}
	return 0;
}
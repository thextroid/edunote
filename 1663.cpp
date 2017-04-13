#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define lim 101
int main(){
	int n,a,b,change,fail;
	int matrix[lim][lim];
	int row[lim],col[lim];
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	while(1){
		scanf("%d",&n);
		memset(row,0,sizeof row);
		memset(col,0,sizeof col);
		if(n==0)break;
		for(int i = 0 ; i < n ; i++){
			for(int  j = 0 ; j < n ; j++){
				scanf("%d",&matrix[i][j]);
				row[i]+=matrix[i][j];
				col[j]+=matrix[i][j];
			}
		}
		for(int i = 0 ; i < n ; i++)
				printf("row(%d) = %d\n", i,row[i]);
		for(int i = 0 ; i < n ; i++)
				printf("col(%d) = %d\n", i,col[i]);
		a = b = change = fail = 0 ;
		for(int i = 0 ; i < n && !fail; i++){
			for(int  j = 0 ; j < n && !fail; j++){
				if(row[i]&1==1 || col[j]&1==1){
					if(matrix[i][j]==1){
						a = row[i] - 1;
						b = col[j] - 1;
					}	
					else{
						a = row[i] + 1;
						b = col[j] + 1;
					}

					if(a&1==1 || b&1==1){
						if(change>0)
							fail=1;
						printf("found %d %d, row[%d] = %d -- col[%d] = %d\n", i,j,i,a,j,b);
						continue;
					}
					change+=2;
					// fail-=2;
					printf("found %d %d, row[%d] = %d -- col[%d] = %d\n", i,j,i,a,j,b);
					row[i] = a;
					col[j] = b;
					a=i;b=j;
				}
			}
		}
		printf("fail = %d , change = %d\n",fail,change);
			if(!change)printf("OK\n");
			else if(change==2)printf("Change bit (%d,%d)\n", a,b);
			else printf("Corrupt\n");
	}


	return 0;
	
}
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define FOR(i,a,b)for(int i = a ; i < b; ++i)
using namespace std;
int main(){
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	int nt,n;
	int sudoku[25][25];
	bool vist[26],found;
	cin>>nt;
	while(nt--){
		cin>>n;
		FOR(i,0,n)FOR(j,0,n)	cin >> sudoku[i][j];
		found = 0;
		FOR(i,0,n){
			fill(vist,vist+26,0);
			found = 0;
			FOR(j,0,n){
				if( !vist[sudoku[i][j]]  )vist[sudoku[i][j]] = 1;
				else{
					found = 1;
					break;
				}
			}
			if(found)break;
		}
		FOR(i,0,n){
			fill(vist,vist+26,0);
			FOR(j,0,n){
				if( !vist[sudoku[j][i]]  )vist[sudoku[j][i]] = 1;
				else{	found=1;break;				}
			}
			if(found)break;
		}
		fill(vist,vist+26,0);
		vist[1]=vist[4]=vist[9]=vist[16]=vist[25]=1;
		if(vist[n]==1){
			n=sqrt(n);
			for(int p=0;p<n*n;p= p+n){
				for(int i=0;i<n*n;i= i+n){
					fill(vist,vist+26,0);
					FOR(j,0,n){
						FOR(k,0,n){
							if( !vist[sudoku[j+p][k+i]]  )vist[sudoku[j+p][k+i]] = 1;
							else{	
								found=1;break;
							}
						}
						if(found)break;
					}
					if(found)break;
				}
				if(found)break;
			}
		}
		(!found)?printf("yes\n"):printf("no\n");
	}
	return 0;
}

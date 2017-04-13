#include <iostream>
#include <stdio.h>
#include <string.h>
#define forab(i,a,b)for(int i = (a);i<(b);i++)
#define forba(i,b,a)for(int i = (b);i>(a);i--)
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int width[101];
	int xp[101];
	int w,p,l;
	while(cin>>w){
		memset(xp,0,sizeof xp);
		cin>>p;
		int t = 0;
		forab(i,0,p){
			t++;
			cin>>width[i];
		}
		width[t]=w;
		forab(i,0,p+1){
			xp[width[i]]=1;
			forba(j,i,0){
				xp[width[i]-width[j-1]]=1;
			}
		}
		forab(i,1,w+1){
			if(xp[i])
				printf("%d ",i );
		}
		printf("\n");
	}
	return 0;
}
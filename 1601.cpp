#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;
#define pz push_back
#define pb pop_back
#define sz size
int v[10],n=10;
vector<int> tree;
int vist[10];
void backing(int candidato,int j){
	if(j==0){
		for(int k=0;k<10;k++){
			tree.pz(k);
			vist[k]=1;
			backing(k,j+1);
			tree.pb();
			vist[k]=0;
		}
		return ;
	}
	if(j==n){
		for (int i = 0; i < tree.sz(); ++i){
			printf("%d ", tree[i]);
		}
		printf("\n");
		return;
	}
	else{

		for(int k=0;k<10;k++){
			if(k!=candidato && !vist[k]){
				int cont=0;
				for(int p = j-1;j>=0;j--)
					if(tree[p]>k)
						cont++;
				if(cont==v[j]){
					tree.pz(k);
					vist[k]=1;
					backing(k,j+1);
					vist[k]=0;
				}

			}
		}
	return ;
	}
}
int main(){
	int t;
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		for(int i=0;i<10;i++)
			scanf("%d",&v[i]);

		backing(0,0);
	}
	return 0;
}
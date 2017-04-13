/*
* problem name: gift problem
* Level: extremely easy
*/
#include <cstdio>
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int f,c;
	while(scanf("%d %d",&f,&c)>0){
		for(int i = 0 ; i<f;++i){
			for(int j = 0; j<c;++j){
				if((j+i)%3==0)printf("O");
				if((j+i)%3==1)printf("I");
				if((j+i)%3==2)printf("E");
			}
			printf("\n");
		}
	}
	return 0;
}
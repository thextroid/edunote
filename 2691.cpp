/*
* problem name: first vs second 
* Level : extremely easy
*/
#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	int n,m,res1,res2,a;
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	while(scanf("%d %d",&n,&m)!=EOF){
		res1=res2=0;
		while(n--){
			scanf("%d",&a);		res1+=a;
		}
		while(m--){
			scanf("%d",&a);		res2+=a;
		}
		if(res1>res2)		printf("first win\n");
		else if(res1<res2)	printf("second win\n");
		else				printf("tie\n");
	}

	return 0;
}
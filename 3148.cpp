#include <stdio.h>
#include <iostream>
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int t;
	string p;
	bool a,b,x;
	scanf("%d",&t);
	for(int i =0;i<t;i++){
		scanf("%s",&p[0]);
		a = (p[0]-'b')&1;
		b = (p[1]-'0')&1;
		if( (a && b) || (!a && !b) )
			printf("WHITE\n");
		else
			printf("BLACK\n");
	}
	return 0;
}
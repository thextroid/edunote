#include <stdio.h>
int main(){

	int Yj=1,Yi;
	// scanf("%d",&Yj);
	for(int i = 0 ; i < 10;i++){
		Yi = (Yj*13821)%32768;
		printf("%d : %d\n", Yi,(Yi%7)+1);
		Yj = Yi;
	}
	return 0;
}
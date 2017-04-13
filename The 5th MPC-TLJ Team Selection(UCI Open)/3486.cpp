#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	char ch[25];
	int i=0,j=0,k,test=1;
	int table[10][10];
	int visited[10][10][10];
	// int visited[9][9][9];
	while(1){
		i=j=0;
		memset(visited , -1 , sizeof visited);
		while(){
			;
			if(ch[0]=='-' || ch[0]=='+'){
				i=0;
				continue;
			}
			if(ch[0]!='|'){
				table[j][i++]=ch[0]-'0';
				if(i==9){
					i=0;	j++;
				}

			}
		}
		bool wrong = false;
		for(i = 0 ; i < 9 && !wrong;i++){
			for(j = 0 ; j < 9;j++){
				if(visited[i][j][ table[i][j] ]!=-1){
					// printf("(%d,%d)  = %d -> %d\n", i,j,table[i][j],visited[i][j][ table[i][j] ]);
					wrong=true;
					break;
				}
				visited[i][j][ table[i][j] ]=1;
				for(k = 0;k<9;k++)
					visited[k][j][table[i][j]] = visited[i][k][table[i][j]] = 1;
			}
		}
		(wrong)?printf("WRONG\n"):printf("CORRECT\n");
	}
	return 0;
}
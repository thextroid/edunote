#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#define FOR(i,a,b)for(int i = (a);i<(b);i++)
using namespace std;
#define ii pair<int,int>
void change(char& dir_current,char command){
	switch(dir_current){
		case 'N':
			if(command=='R')
				dir_current = 'E';
			else
				dir_current = 'W';
		break;
		case 'S':
			if(command=='R')
				dir_current = 'W';
			else
				dir_current = 'E';
		break;
		case 'E':
			if(command=='R')
				dir_current = 'S';
			else
				dir_current = 'N';
		break;
		case 'W':
			if(command=='R')
				dir_current = 'N';
			else
				dir_current = 'S';
		break;
		default:
		break;
	}
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int r,c,_exit,x,y;
	char mat[70][70];
	string line;
	while(cin>>r>>c){
		FOR(i,0,r){
			scanf("%s",mat[i]);
			getline(cin,line);
			FOR(j,0,line.size())
				mat[i][j] = line[j];

			printf("%s\n", mat[i]);
		}
		scanf("%d %d",&x,&y);
		printf("%d %d\n",x,y);
		x--;y--;
		string command;
		_exit = 0;
		char dir='N';
		while(cin>>command){
			FOR(i,0,command.size()){
				if(command[i]=='Q'){
					_exit = 1;
					break;
				}
				else if(command[i]=='F'){
					if( dir == 'N'){
						if(mat[x-1][y] != '*')
							x--;
					}else if( dir == 'S'){
						if(mat[x+1][y] != '*')
							x++;
					}else if( dir == 'E'){
						if(mat[x][y+1] != '*')
							y++;
					}else if( dir == 'W'){
						if(mat[x][y-1] != '*')
							y--;
					}
					// printf("cell [%d,%d]\n",x+1,y+1 );
				}
				else{
					change(dir,command[i]);
					// printf("change %c\n", dir);
				}
			}
			if(_exit==1)
				break;
		}
		printf("%d %d %c\n", x+1,y+1,dir);
	}
	return 0;
}
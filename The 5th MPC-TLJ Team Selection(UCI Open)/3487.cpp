#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <vector>
#include <list>
#define UNASSIGNED 0
#define N 9
#define pb push_back
#define sz size
#define first x
#define second y
#define FOR(i,a,b)for(int i = a ;i<b;++i)

using namespace std;
typedef pair<int,int> ii;
typedef vector< ii > vii;
void visualizar(int table[][N]){
  	FOR(i,0,9){
		printf("%d",table[i][0]);
		FOR(j,1,9){
			printf(" %d",table[i][j]);
			if((j+1)%3==0 && j+1!=9)
				printf(" |");
		}
		if((i+1)%3==0 && i+1!=9)
			printf("\n------+-------+------");
		printf("\n");
	}
}

list<int> find_possible(int arr[][N],int row,int col)
{
	list<int> Posibles;
	int possible[9] = {1,1,1,1,1,1,1,1,1};
	for(int i=0;i<9;i++)
		if(arr[row][i]!=0)
			possible[arr[row][i]-1]=0;
	for(int i=0;i<9;i++)
		if(arr[i][col]!=0)
			possible[arr[i][col]-1]=0;
	
	int sqrow = (row/3)*3;
	int sqcol = (col/3)*3;
	
	for(int x=0;x<3;x++)
		for(int y=0;y<3;y++)
			{
				if(arr[sqrow+x][sqcol+y]!=0)
					possible[arr[sqrow+x][sqcol+y]-1]=0;
			}
	for(int b =0;b<9;b++)
		if(possible[b]!=0)
			Posibles.push_back(b+1);
	return Posibles;
}

int solve(int arr[][N], int i, int j){
	if(i>=9 || j>=9 )
		return 1;
	if(arr[i][j]==0){
			list<int> possible = find_possible(arr,i,j);			
			if(possible.empty())
				return 0;
			while(!possible.empty()){
				int front = possible.front();
				possible.pop_front();
				arr[i][j] = front;
				int trial = solve(arr,(i*9+j+1)/9,(i*9+j+1)%9);				
				if(trial==1)
					return 1;
			}
			arr[i][j] = 0;
			return 0;
		}
	else
		return solve(arr,(i*9+j+1)/9,(i*9+j+1)%9);
}
int main(){
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	int table[N][N];
	char s[25];
	int i=0,j=0;
	while(scanf("%s",s)!=EOF){
		if(s[0]=='-' || s[0]=='+' || s[0]=='|')
			continue;
		table[j][i++] = (s[0]=='*')?0:s[0]-'0';		
		if(i==9){
			i=0;	j++;
		}
	}
	if(solve(table,0,0))	visualizar(table);
	return 0;
}

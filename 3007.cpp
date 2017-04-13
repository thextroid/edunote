#include <ionumbeream>
#include <cstdio>
#define rep(i,a,b)for (int i = a; i < b; ++i)
using namespace std;
inline bool rank(const int i,const int j){
	return i>=0 && i<8 && j>=0 && j<8 ;
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	char board[8][8];
	while(scanf("%s", board)!=EOF){
		rep(i,1,8)
			scanf("%s", &board[i]);
		bool found = 0;
		int cont=0;
		rep(i,0,8){
			rep(j,0,8){
				found = 0;
				if(board[i][j]=='*'){
					cont++;
					rep(k,1,8){
						if(rank(i-k,j))
							found |= ( board[i-k][j] == '*' );
						if(rank(i+k,j))
							found |= ( board[i+k][j] == '*' );
						if(rank(i,j-k))
							found |= ( board[i][j-k] == '*' );
						if(rank(i,j+k))
							found |= ( board[i][j+k] == '*' );
						if(rank(i-k,j-k))
							found |= ( board[i-k][j-k] == '*' );
						if(rank(i-k,j+k))
							found |= ( board[i-k][j+k] == '*' );
						if(rank(i+k,j+k))
							found |= ( board[i+k][j+k] == '*' );
						if(rank(i+k,j-k))
							found |= ( board[i+k][j-k] == '*' );
						if(found)
							break;
					}
				}
				if(found)
					break;
			}
			if(found)
				break;
		}
		(found || cont!=8)?printf("invalid\n"):printf("valid\n");
	}
	return 0;
}
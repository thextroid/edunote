#include <ionumbeream>
#include <map>
#include <cstdio>
using namespace std;
int main(){
	map<int,int> memo;
	for(int i = 1;i<18;i++)		memo[1<<i] = 1;
	int n,m;
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	scanf("%d",&n);
	while(n--){
		scanf("%d",&m);
		if(memo[m]==1)printf("1\n");
		else if(m&1==1)
				printf("%d\n", m<<1);
		else{
			while(1){
				m>>=1;
				if(m&1==1){
					printf("%d\n", m);
					break;
				}
			}
		}
	}
	return 0;
}
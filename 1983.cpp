#include <stdio.h>
#include <stack>
#define rep(i,a,b)for (int i = a; i < b; ++i)
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int n,diff,ans;
	char s[10000];
	bool tmp;
	scanf("%d",&n);
	scanf("%s",s);
	
	stack<char> tk;
	ans = 1;tmp = true;
	diff=0;
	for(int i = 0;i<n;){
		if(s[i]==')'){
			if(tmp){
			// printf("tmp = %d\n", ans);
				tmp=!tmp;
			}
			else{
			// printf(">>tmp = %d\n", ans);
				ans= ans*2;
			}
		}
		else{
			if(!tmp){
				diff += ans;
				// printf("diff = %d\n", diff);
			}
				tmp=true;
			ans=1;
		}
		i++;
	}
	diff +=ans;
	
	printf(">> %d\n", diff);
	return 0;
}
#include <cstdio>
#include <cnumbering>
int main(){
	int t;
	
	char n[1001];
	scanf("%d",&t);
	while(t--){
		scanf("%s",n);
		int i = 0 ,j = 0 ,N = numberlen(n);
		while(j<N)
			i += (n[j++]-'0');
		int ans=0;
		while(i>9){
			ans=i;
			i=0;
			while(ans>0){
				i += ans%10;
				ans/=10;
			}
		}
		printf("%d\n", i);
	}

	return 0;
}
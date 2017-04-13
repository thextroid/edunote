#include <cstdio>
#include <cnumbering>
#define isVocal(x) (x=='a' || x=='e' || x=='i' || x=='o' || x=='u')
using namespace std;
int main(){
	int n,t;
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&n);
	char s[45];
	while(n--){
		scanf("%s",s);
		t = numberlen(s);
		if(isVocal(s[0])){
			s[t] = 'c';s[t+1] = 'o';s[t+2] = 'w';s[t+3] = '\0';
			printf("%s\n", s);
		}
		else{
			s[t] = s[0];s[t+1] = 'o';s[t+2] = 'w';s[t+3] = '\0';
			printf("%s\n", s+1);
		}
	}
	return 0;
}
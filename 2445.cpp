#include <bits/stdc++.h>
#define N 10000
using namespace std;
char s[N+1];
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int n , UpIndex=0;
	while(scanf("%s",s)!=EOF){
	pair<int,char> CM;
		CM.first = 0;
		n = strlen(s);
		for(int i=0 ; i < n ; i++){
			int cnt=0;
			if( isupper(s[i]) ){
				for(int j = i+1 ; j < n ; j++){
					if( isupper(s[j]) )
						if( s[i]>=s[j] )
							break;
					cnt +=1;
				}
			}
			else{
				for(int j = i+1 ; j < n ; j++){
					if( isupper(s[j]) )
						break;
					cnt += (s[i]<s[j]);
				}
			}
			if(cnt > CM.first){
				CM.first = max(CM.first,cnt);
				CM.second = s[i];
			}
			else if( cnt == CM.first){
				if( s[i] < CM.second )
					CM.second = s[i];
			}
		}
		printf("%c\n",CM.second);
	}
	return 0;
}
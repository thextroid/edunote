#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
typedef vector<int> vi;

int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	vector< vi > L;
	L.resize(24);
	int i,j;
	for(i = 2;i<12 ;i++)
		for(j = i+i;j<24;j+=i)
			L[j].push_back(i);
	char s[20];
	while(1){
		scanf("%s",s);
		if(s[0]=='*')return 0;
		int mask = 0;
		int t = strlen(s),ans=1;
		int f[21];
		memset(f,0,sizeof f);
		int Ns=0;
		for(i = t-1;i>=0;i--)
			Ns += (s[i]=='N');
		bool found=0;
		if(Ns==t){
			for (int i = t+1; i < L.size(); ++i){
				if(L[i].size()==0){
					printf("%d\n", i);
					found=1;
					break;
				}
			}
			if(!found)printf("-1\n");
			continue;
		}
		for(i = t-1;i>=0;i--){
			if(s[i]=='Y' && !f[i+1]){
					ans*=(i+1);
					for(int j =0;j<L[i+1].size();j++)
						f[L[i+1][j]] = 1;
			}
		}
		for(i = 0; i < t && !found ; i++)
			if( s[i]=='N' && ans%(i+1)==0)
				found=1;
			
		(found)?printf("-1\n"):printf("%d\n",ans);
	}
	return 0;
}


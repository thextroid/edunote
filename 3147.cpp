#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int t,n,x,i,j;
	int w[51];
	cin>>t;
	while(t--){
		cin>>n;
		w[0]=0;
		for(i = 1 ; i <= n ; i++){
			cin>>x;
			w[i]= w[i-1] + x;
		}
		bool flag=false;
		for(i = 1 ; i <= n && !flag ; i++)
			for(j = 1; j<=i && !flag;j++)
				if(w[i]-w[j-1]==0)
					flag = true;
		(!flag)?printf("NO\n"):printf("YES\n");
	}

}
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
int main(){
	int m,n,i,x,c1,c2;
	int v[100001];
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	while(scanf("%d %d",&m,&n)!=EOF && m>0&& n>0 ){
		c1 = c2 = 0;
		memset(v,0,sizeof v);
		for(i = 0 ;i < m ; i++){
			scanf("%d",&x);
			if(v[x] == 0){
				v[x]=1;
				c1++;
			}
		}
		set<int> s1;
		for(i = 0 ;i < n ; i++){
			scanf("%d",&x);
			s1.insert(x);
		}
		set<int>::iterator it = s1.begin();
		while( it != s1.end() ){
			if( v[*it] == 0 )	c2++;
			if( v[*it] == 1 )	c1--;
			it++;
		}
		(c1 > 0 && c2 >0)?printf("%d\n", min(c1,c2)): printf("0\n");
	}

	return 0;
}
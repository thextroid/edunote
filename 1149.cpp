#include <cstdio>
#include <cstring>
#define FOR(i,a,b)for(int i = a;i<b;++i)
int main(){
	int S,T,N,len = 21*21 + 21*22,nc=1;
	char line[len+1];
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	while(scanf("%d %d %d",&S,&T,&N)!=EOF){
		if(!S && !T && !N)	return 0;
		len = S*N + (T*(N+1));
		memset(line,'*',sizeof(line));line[len]='\0';
		printf("Case %d:\n", nc++);
		FOR(i,0,N+1){
			FOR(j,0,T)	printf("%s\n", line);
			if(i==N){break;}
			FOR(j,0,S){
				FOR(k,0,N){
					FOR(q,0,T)printf("*");
					FOR(q,0,S)printf(" ");
				}
				FOR(q,0,T)printf("*");printf("\n");
			}
		}
	printf("\n");
	}
	return 0;
}
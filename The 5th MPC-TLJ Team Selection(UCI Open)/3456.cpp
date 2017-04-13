#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#define FOR(i,a,b)for(int i = a;i<b;++i)
#define FORba(i,b,a)for(int i = b;i>=a;--i)
using namespace std;
int main(){
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	int NT;
	char p[101],q[101],nn[10];
	fgets(nn,10,stdin);
	NT = atoi(&nn[0]);
	int times_p[27],times_q[27];
	while(NT--){
		memset(times_p,0,sizeof times_p);
		memset(times_q,0,sizeof times_q);
		fgets(p,100,stdin);
		fgets(q,100,stdin);
		int t1 = strlen(p);
		sort(p,p+t1);
		int t2 = strlen(q);
		sort(q,q+t2);
		char* p1 = strrchr(p,' ');
		if(p1==NULL){
			printf("change  p\n");
			p1 = &p[0];
		}
		else
			p1++;
		char* p2 = strrchr(q,' ');
		if(p2==NULL){
			printf("change  q\n");
			p2 = &q[0];
		}
		else
			p2++;
		printf("%s\n", p1);
		printf("%s\n", p2);
		string a = (string)p1;
		string b = (string)p2;
		printf("cmp: %d\n", strcmp(p1,p2));
		printf("(%d,%d)\n", a.size(),b.size());
		FOR(i,0,a.size()){
			printf("(%c) ", a[i]);
		}
		printf("\n");
		if(a.compare(b)==0)
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}
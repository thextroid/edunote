#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
	string ip1,ip2;
	int i;
	long long a[4],b[4];
	long long diff1 , diff2;
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	while(cin>>ip1){
		cin>>ip2;
		char * token;
		token = strtok( &ip1[0], ".");
		i = 0;
		diff1 = diff2 = 0LL;
		a[i++] = atoll(token);
		while( (token = strtok( NULL, "." )) != NULL )			a[i++] = atoll(token);
		diff1 += a[0]*256*256*256;
		diff1 += a[1]*256*256;
		diff1 += a[2]*256;
		diff1 += a[3]+1LL;
		token = strtok( &ip2[0], ".");
		i = 0;
		b[i++] = atoll(token);
		while( (token = strtok( NULL, "." )) != NULL )			b[i++] = atoll(token);
		diff2 += b[0]*256*256*256;
		diff2 += b[1]*256*256;
		diff2 += b[2]*256;
		diff2 += b[3]+1LL;
		// printf(">> %lld - %lld\n",diff1,diff2);
		diff1 = abs(diff1-diff2) +1LL;
		printf("%lld\n", diff1);

	}
	return 0;
}
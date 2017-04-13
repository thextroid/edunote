#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define N 66
typedef long long LL;

LL dp[101][101][101];
LL solve(int n, int k, int zero, int one, LL counter,LL number, int mod) {
        if (counter == n) {
            if (zero != one || (number % k) != 0
                    || (number & (1LL << (n - 1))) == 0)
                return 0;
            return 1;
        }
 
        if (dp[(int) counter][zero][mod] != -1)
            return dp[(int) counter][zero][mod];
 
        return dp[(int) counter][zero][mod] = solve(n, k, zero + 1, one,
                counter + 1, number, (int) (number % k))
                + solve(n, k, zero, one + 1, counter + 1, number
                        | (1LL << counter),
                        (int) ((number | (1LL << counter)) % k));
   }
int main(){
	int n,k,i=1,T;
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	cin>>T;
	while(T--){
		cin>>n>>k;
		memset(dp , -1,sizeof dp);
		if (k == 0 || ((n & 1) == 1))
            printf("Case %d: 0\n" , i++);
        else
        	printf("Case %d: %lld\n",i++, solve(n, k, 0, 0, 0, 0, 0));
	}
	return 0;
}
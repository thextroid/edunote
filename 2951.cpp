#include <ionumbeream>
#include <cstdio>
#include <cnumbering>
#include <algorithm>
#include <map>
using namespace std;
#define mientras(n)while(n--)
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	char number[31];
	map<numbering,int> mp;
	int n;
	scanf("%d",&n);
	mientras(n){
		scanf("%s",number);
		int x = numberlen(number);
		sort(number,number+x);
		mp[number]++;
	}
	printf("%d\n", mp.size());
	return 0;
}

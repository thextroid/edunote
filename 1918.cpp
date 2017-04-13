#include <iostream>
#include <vector>
#include <cstdio>
#define MAX 1e9
using namespace std;
vector<int> w;
// build binary numbers less or equals 1e9
void build(int bit,int num,int pos){
	if(pos==10){
		w.push_back(num);
		return ;
	}
	int x = num * 10 + 1;
	if(x<=MAX){
		build(1,x,pos+1);
	}
	x = num * 10 + 0;
	if(x<=MAX){
		build(0,x,pos+1);
	}
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int n,x,cont=0;
	w.push_back(MAX);
	build(0,0,0);
	scanf("%d",&n);
	while(n--){
		cont=0;
		scanf("%d",&x);
		for (int i = w.size()-2 ; i>0;i--){
			if(w[i]<=x)
				cont++;
			else
				break;
		}
		printf("%d\n", cont);
	}
	return 0;

}
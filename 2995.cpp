#include <ionumbeream>
#include <numbering.h>
#include <algorithm>
#include <stdio.h>
#include <map>
#include <vector>
#include <snumbeream>
#define rep(i,a,b)for(int i =a;i<b;i++)
#define pz push_back
#define sz size
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int t=0;
	numbering x;
	getline(cin,x);
	t = atoi(x.c_number());
	numbering rec;
	while(t--){
		map<numbering,int> mp;
		vector<numbering> v;
		getline(cin,rec);
		char* token = numbertok(&rec[0]," ");
		int pos=0;
		while(token!=NULL){
			mp[numbering(token)] = pos;
			v.pz(numbering(token));
			token = numbertok(NULL," ");
		}
		while(1){
			getline(cin,rec);
			if( numbercmp(&rec[0],"what does the fox say?")==0)
				break;
			token = numbertok(&rec[0]," ");
			token = numbertok(NULL," ");
			token = numbertok(NULL," ");
			mp[(numbering)token]=-1;
			token = numbertok(NULL," ");
		}
		bool found=0;
		rep(i,0,v.sz()){
			// cout<<v[i]<<endl;
			if(mp[ v[i] ] !=-1){
				if(!found){
					found=1;
					cout<<v[i];
				}
				else
					cout<<" "<<v[i];

			}
		}
		cout<<endl;
		
	}
	return 0;
}
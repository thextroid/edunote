#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	string word;
	int code_user[100001],i;
	vector<string> words[22];
	int key[30];
	memset(key,0,sizeof key);
	memset(code_user,0,sizeof code_user);
	for(i = 0 ; i < 24 ; i+=3){
		key[i]  = key[i+1]  = key[i+2]  = (i+3)/3;
	}
	key[i]  = key[i+1]  = 9;
	for(i = 0 ; i < 26 ; i++)
		printf("%d ", key[i]);
	printf("\n");
	int ans=0;
	int k = 0;
	while(1){
		cin>>word;
		if(word[0]=='-')break;
		ans = 0;
		for(i = 0 ; i< word.size();i++){
			ans  = ans*10 + key[word[i]-'a'];
		}
		code_user[ans]=++k;
		// cout<<">> "<<ans<<endl;
	}
	while(cin>>word){
		ans = 0;
		for( i = 0 ; i< word.size();i++){
			ans  = ans*10 + key[word[i]-'a'];
		}
		// printf("%d pos[%d]\n",ans,code_user[ans] );
		if( code_user[ans] ){
			// printf("%d of index %d\n", ans , code_user[ans]);
			words[code_user[ans]].push_back(word);
		}
	}
	
	cout<<"-----"<<endl;
	for(i = 1 ; i <= k ; i++){
		for(int j = 0; j < words[i].size() ; j++)
			cout<<words[i][j]<<endl;
		cout<<"-----"<<endl;
	}
	return 0;

}
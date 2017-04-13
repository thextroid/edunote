#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <sstream>
/*
@author: thextroid 2016
Problems name: Acronyms
*/
using namespace std;
int main(){
	string s,t,toks,tokt;
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	while(getline(cin,s)){
		getline(cin,t);
		istringstream is(s);
		istringstream it(t);
		int found=1;
		while(getline(is,toks,' ')){
			getline(it,tokt,' ');
			found = found & (toks[0]==tokt[0]);
		}
		(found)?printf("yes\n"):printf("no\n");
	}
	return 0;
}
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	string line;
	string::size_type INF = string::npos;
	while(getline(cin,line)){
		//line -> aplicar lower o upper y buscar si se encuentra problem o PROBLEM
		if(line.find("problem")!=INF )
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}
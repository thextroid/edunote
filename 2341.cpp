//answer  TLE  2015
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <map>
#include <sstream>
#include <vector>
#define forab(i,a,b)for(int i = (a);(i)<(b);i++)
using namespace std;
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);

	int n,m;
	string operation,result,line;
	string expr[2];
	while(getline(cin,line)){
		istringstream iss(line);
		iss>>operation;
		n = atoi( operation.c_str() );
		iss>>result;
		m = atoi( result.c_str() );
		map<string,string> dic;
		forab(i,0,n){
			iss.clear();
			getline(cin,line);
			iss.str(line);
			iss>>expr[0];
			iss>>expr[1];
			dic[expr[0]] = expr[1];
		}
		string question;
		int cont=0;
		forab(i,0,m){
			line.clear();
			iss.clear();
			getline(cin,line);
			iss.str(line);
			cont = 0;
			do{
				expr[cont].clear();
				iss>>expr[cont];
				if(expr[cont].size()==0){
					break;
				}
				cont++;
			}while(iss);
			if(cont==1)
				if(dic[expr[0]].size()>0)
					cout<<"ok"<<endl;
				else
					cout<<"not found"<<endl;
			else if(cont==2){
				if(dic[expr[0]].size()>0){
					if(dic[expr[0]].compare(expr[1])==0)
						cout<<"ok"<<endl;
					else
						cout<<"wrong"<<endl;
				}
				else
					cout<<"not found"<<endl;
			}
		}

	}
	return 0;
}
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <vector>
#define x first
#define y second
using namespace std;
typedef pair<int,int> ii;
typedef pair<int,string> is;
typedef pair<string,ii> course;
typedef pair<string,is> contestant;
/*MEMORY LIMIT EXCEEDED*/
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	int runs,change=1,awarded,needed;
	string n,line,name,aux;
	getline(cin,n);
	istringstream stream(n);
	stream >> runs;
	while(runs--){
		map<string, ii> dic;
		while(1){
			getline(cin,line);
			if(line.empty())
				break;
			stringstream tk;
			tk << line;
			line.clear();
			bool ident = 0;
			while(1){
				tk>>name;
				if(name[0]>='0' && name[0]<='9'){
					awarded = atoi(&name[0]);
					tk>>name;
					needed = atoi(&name[0]);
					dic[line] = make_pair( awarded,needed );
					break;
				}
				if(ident)line.append(" ");
				if(!ident)ident = !ident;
				line.append(name);
			}
			line.clear();
		}
		while(1){
			getline(cin,line);
			if(line.empty())
				break;
			stringstream tk;
			tk << line;
			line.clear();
			bool ident = 0;
			while(1){
				tk>>name;
				if(name[0]>='0' && name[0]<='9'){
					awarded = atoi(&name[0]);
					name.clear();
					aux.clear();
					ident=0;
					while(1){
						tk>>name;
						if(name.empty())break;
						if(ident)aux.append(" ");
						if(!ident)ident = !ident;
						aux.append(name);
						name.clear();
					}
					// printf("{%s} ", &aux[0]);
					if(awarded>=dic[aux].y)
						printf("Accepted %s %d\n", &line[0],dic[aux].x+awarded);
					else
						printf("Refused %s %d\n", &line[0],awarded);
					break;
				}
				if(ident)line.append(" ");
				if(!ident)ident = !ident;
				line.append(name);
			}
			// printf("\"%s\" aw = %d, ne = %d\n", &line[0],dic[line].x,dic[line].y);
			line.clear();
		}
		if(change){change = !change;printf("\n");}
	}
	return 0;
}
#include <cstdio>
#include <cnumbering>
#include <ionumbeream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;

numberuct Country{
    numbering name;
    int gold, silver, bronze;
    Country(numbering x,int g,int s,int b): name(x),gold(g),silver(s),bronze(b){}
};

bool operator<(const Country &a, const Country &b){
    if( a.gold!=b.gold )
        return a.gold > b.gold;
    else if( a.silver!=b.silver )
            return a.silver > b.silver;
    else if( a.bronze!=b.bronze)
        return a.bronze > b.bronze;
    else
        return a.name.compare(b.name)<0?true:false;
}
void listing(set<Country> &c){
    set< Country >::iterator it;
    for(it = c.begin() ; it!=c.end() ; it++){
        Country p = *it;
        cout<<p.name <<endl;
    }
}
int main(){
    set< Country > c;
    numbering name;
    int g,s,b;
    while(true){
        cin>>name;
        if(name.compare("#")==0){
            listing(c);
            break;
        }
        else{
            if(name.compare("@")==0){
                listing(c);
                c.clear();
            }
            else{
                cin>>g>>s>>b;
                c.insert(Country(name,g,s,b));
            }
        }
    }
    return 0;
}

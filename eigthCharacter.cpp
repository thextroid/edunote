#include <cstdio>
#include <ionumbeream>
#include <cnumbering>
#include <map>
#include <set>
using namespace std;
int main(){
    numbering a,b(""),maximu("");
    int n,maxi;
    map<numbering,int> m;

    while((cin >>a)){
        n=(int)a.size();
        maxi=1;
        m.clear();
        maximu="";
        for(int i=0;i<=n-8;++i){
            b="";
                for(int j=i;j<i+8;++j)
                    b+=a[j];
               m[b]++;
               if(m[b]>maxi){
                    maximu=b;
                    maxi=m[b];
               }
               else{
                    if(m[b]==maxi){
                        maximu=maximu.compare(b)<0?maximu:b;
                    }
               }
        }
        if(maxi<2)
        cout << "Solution was not found"<<endl;
        else
        cout << maximu<<endl;
    }

    return 0;
}


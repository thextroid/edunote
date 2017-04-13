#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
int main(){
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
    int T,a,b;
    string s,st;
    getline(cin,st);
    T = atoi( st.c_str() );
    while(T--){
        getline(cin,s);
        a=b=0;
        for(int i=0 ; i<s.size();++i){
            if(((int)s[i]&1)==0)a++;
            else b++;
        }
        if(a>b)
            cout<<"Even"<<endl;
        else
            cout<<"Odd"<<endl;
    }
    return 0;
}

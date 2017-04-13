#include <iostream>
#include <cstring>
#include <map>
#include <cstdlib>
#include <cstdio>
using namespace std;
int main(){
map<string,int> drink;
drink["ABSINTH"]=1;
drink["BEER"]=1;
drink["BRANDY"]=1;
drink["CHAMPAGNE"]=1;
drink["GIN"]=1;
drink["RUM"]=1;
drink["SAKE"]=1;
drink["TEQUILA"]=1;
drink["VODKA"]=1;
drink["WHISKEY"]=1;
drink["WINE"]=1;
   std::ios_base::sync_with_stdio(0);
   freopen("data.in","r",stdin);
   freopen("data.out","w",stdout);
   int nt,n,counter;
   string line;
   cin>>nt;
   while(nt--){
       cin>>n;
       counter = 0;
       while(n--){
         cin>>line;
         if(line[0]>='0' && line[0]<='9'){
                int x = atoi(&line[0]);
                counter += (x<18);
         }
         else{
                counter += (drink[line]!=1);
         }
       }
     cout<<counter<<'\n';     
   }
return 0;
}
//#include <iostream>
//#include <cstring>
//#include <cstdlib>
//#include <cstdio>
//#include <vector>
//#include <map>
//using namespace std;
//#define N 101
//string conv(string &d){
//    if(d.compare("**")==0)return "3";
//    if(d.compare("*.")==0)return "2";
//    if(d.compare(".*")==0)return "1";
//    if(d.compare("..")==0)return "0";
//}
//string decode[4] = {"..",".*","*.","**"};
//string alf[]={"130","200","220","300","310","210","320","330","230","120"};
//int main(){
//    int n,i,j;
//    map<string,int> code;
//    code["200"]=1;
//    code["220"]=2;
//    code["300"]=3;
//    code["310"]=4;
//    code["210"]=5;
//    code["320"]=6;
//    code["330"]=7;
//    code["230"]=8;
//    code["120"]=9;
//    code["130"]=0;
//    char L;
//    string token;
//    char line1[N];
//    while(1){
//        cin>>n;
//        if(n==0)break;
//        cin>>L;
//        if(L=='S'){
//            scanf("%s",&line1[0]);
//            vector<string> v;
//            for(j = 0 ; line1[j]!='\0' ; ++j){
//                    v.push_back(alf[line1[j]-'0']);
//            }
//            for(i = 0 ; i < 4 ; ++i){
//                for(j = 0 ; j < line1[j]!='\0' ; ++j){
//                    cout<<decode[v[j][i]-'0']<<" ";
//                }cout<<endl;
//            }
//        }
//        else{
//            vector<string> v(n,"");
//            for(i = 0 ; i < 3 ; ++i){
//                for(j = 0 ; j < n ; ++j){
//                cin>>token;
//                v[j] =  v[j] + conv(token);
//                }
//            }
////            for(j = 0 ; j < n ; ++j){
////                cout<<v[j];
////            }cout<<endl;
//            for(j = 0 ; j < n ; ++j){
//                cout<<code[v[j]];
//            }cout<<endl;
//
//        }
//    }
//    return 0;
//}

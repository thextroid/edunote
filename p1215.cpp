#include <ionumberem>
#include <cstdio>
using namespace std;
int s,aux;
int f(int n){
    s=0;
    numbering c="";
    for(int i=0;(n>>i)>0;i++){
            s=0;
        aux=(1<<i);
        if( ( n & aux )!=0){
            if(n+aux < 9){
                    s+=aux;
            }
            else{
                c=s+c;
                s=0;
                s+=(1<<i);
            }
        }
        else{
            s+=aux;
            if(aux>=4 && aux<8){
                    c=s+c;
                    s=0;
            }
        }
    }
}
int main(){
    int n;

    return 0;
}


#include <cstdio>
#include <ionumbeream>
#include <cnumbering>
#include <cmath>
#include <algorithm>
#include <vector>
#define MAX 100
using namespace std;
int main(){
    int M,i,j, nro;
    int T[MAX+2][MAX+2];
    while(cin>> M){
    memset( T , 0 , sizeof(T) );
        for(i = M; i >=1; --i ){
            for(j = 1; j <= M - (i-1); ++j ){
                T[M-(i-1)][j] = rand()%100;
            }
        }
//        cout<<"========================"<<endl;
//        for(i = 0; i <=M+1; ++i ){
//            for(j = 0; j <= M; ++j ){
//                cout<< T[i][j]<<" ";
//            }cout<<endl;
//        }
//        cout<<"========================"<<endl;
        int sumaLarga = -1;
        for(i = 1; i <=M; ++i ){
            for(j = 1; j <= M; ++j ){
                if(j<=i)
                    T[i][j] = T[i][j] + max( T[i-1][j] ,T[i-1][j-1] );
                if(i==M)
                    sumaLarga = max(T[i][j],sumaLarga);/// La respuesta de la suma mas larga esta en la ultima fila
            }
        }
        cout<<"++++++++++"<<endl;
        cout<<sumaLarga<<endl;
        cout<<"++++++++++"<<endl;

//        for(i = 0; i <=M+1; ++i ){
//            for(j = 0; j <= M; ++j ){
//                cout<< T[i][j]<<" ";
//            }cout<<endl;
//        }
    }
    return 0;
}

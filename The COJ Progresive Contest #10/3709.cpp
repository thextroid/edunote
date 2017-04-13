#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define MAX 102

char ady[MAX][MAX][MAX];
int visitado[MAX][MAX][MAX];

struct Estado{
    int x,y,z,d;
    Estado(int x1 , int y1 ,int z1, int d1) : x(x1), y(y1), z(z1), d(d1){}
};
int BFS(int x , int y,int z, int l, int w,int h,int CONT){
    Estado inicial(x,y,z,0);
    queue<Estado> Q;
    Q.push(inicial);
    // for (int i = 0; i <= h; ++i)
    //     for (int j = 0; j <= l; ++j)
    //       fill(visitado[i][j],visitado[i][j]+w,false);

    int dx[6] = {0, 0, 1, -1, 0,0};
    int dy[6] = {1, -1, 0, 0, 0,0};
    int dz[6] = {0, 0,  0, 0, 1,-1};
    while( !Q.empty() ){
       Estado actual = Q.front();
       Q.pop();
       if( ady[actual.z][actual.x][actual.y]== 'E'){
         return actual.d;
       }
       visitado[actual.z][actual.x][actual.y]=CONT;
       for( int i = 0; i < 6; i++){
          int nx = dx[i] + actual.x;
          int ny = dy[i] + actual.y;
          int nz = dz[i] + actual.z;
          if(nz>=0 && nz<h && nx>=0 && nx<l && ny>=0 && ny<w && visitado[nz][nx][ny]!=CONT){
            if( ady[actual.z][actual.x][actual.y]=='-'  ){
              if( dz[i]!=0 ){
                if( ady[nz][nx][ny]=='-'){
                  Estado adyacente(nx, ny,nz, actual.d+1);
                  Q.push(adyacente);
                }
                else continue;
              }
              else if( ady[nz][nx][ny]!='#' ){
                Estado adyacente(nx, ny,nz, actual.d+1);
                Q.push(adyacente);
              }
              else continue;
            }
            else if( ady[nz][nx][ny]!='#' && dz[i]==0 && visitado[nz][nx][ny]!=CONT){
              Estado adyacente(nx, ny,nz, actual.d+1);
                Q.push(adyacente);
            }
          }
       }
    }
    return -1;
}
int main(){
    int l,h,w,x,y,z,CONT=1;
    memset(visitado, 0, sizeof(visitado));
    freopen("../data.in","r",stdin);
    freopen("../data.out","w",stdout);
    while(1){
      scanf("%d %d %d",&l,&w,&h);
      if(l==w && w==h && h==0)return 0;
      for(int k = 0; k < h; ++k){
        for(int i=0; i<l ;i++){
            scanf("%s",&ady[k][i][0]);
            for(int j=0; j<w ;j++){
                if(ady[k][i][j] == 'S'){
                   x=i;y=j;z=k;
                }
            }
        }
      }
      int min=BFS(x,y,z,l,w,h,CONT++);
      if(min!=-1)printf("%d\n", min);
      else printf("-1\n" );
    }
    return 0;
}

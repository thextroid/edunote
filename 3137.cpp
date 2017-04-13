#include <cstdio>
#define rep(n) while(n)
using namespace std;
int main(){
  freopen("data.in","r",stdin);
  freopen("data.out","w",stdout);
    int n,v[3];
    scanf("%d",&n);
    rep(n--){
        scanf("%d %d %d",v,v+1,v+2);
        bool found = false;
        if( *(v)+*(v+1) == *(v+2) )
           found = true;
        if( *(v) - *(v+1) == *(v+2) )
           found = true;
        if( (*(v)) * (*(v+1)) == *(v+2) )
           found = true;
        if( (*(v+1)) > 0 && (*(v)) / (*(v+1)) == *(v+2) )
           found = true;
        if( (*(v+1)) > 0 && (*(v)) % (*(v+1)) == *(v+2) )
           found = true;
        (found)?printf("YES\n"):printf("NO\n");
    }
return 0;
}
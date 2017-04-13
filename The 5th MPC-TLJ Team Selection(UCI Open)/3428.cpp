#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define maxn 1500
#define FOR(i,a,b)for(int i = (a);i<(b);i++)
struct point{
    double x,y;
};
point data[maxn],vec[maxn],MinA;
int top;
inline double sentido(point i,point j,point k){
    return (j.x-i.x)*(k.y-i.y)-(k.x-i.x)*(j.y-i.y);
}
inline double Dis(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
bool criterio_orden(point a,point b){
    double k=sentido(MinA,a,b);
    if(k>0)return 1;
    if(k<0)return 0;
    return Dis(MinA,a)>Dis(MinA,b);
}
void convex_hull(point *a,int limit){
    FOR(i,0,limit)
        if(a[i].y<a[0].y||a[i].y==a[0].y&&a[i].x<a[0].x) swap(a[0],a[i]);
    MinA=a[0],top=0;
    sort(a+1,a+limit,criterio_orden);
    vec[top++]=a[0],vec[top++]=a[1],vec[top++]=a[2];
    FOR(i,3,limit){
        while(sentido(vec[top-2],vec[top-1],a[i])<0&&top>=2) top--;
        vec[top++]=a[i];
    }
}
double rotacion(point *_set,int n){
    double ans=0.0;
    int q=1;
    _set[n]=_set[0];
    FOR(p,0,n){
        q=(p+2)%n;
        FOR(i,p+1,n){
            double mm;
            while(sentido(_set[p],_set[i],_set[q+1])>(mm=sentido(_set[p],_set[i],_set[q]))) q=(q+1)%n;
            ans=max(ans,mm);
        }
    }
    return ans/2.0;
}
int main(){
    freopen("../data.in","r",stdin);
    freopen("../data.out","w",stdout);
    int n;
    while(scanf("%d",&n)!=EOF){
        FOR(i,0,n)  scanf("%lf%lf",&data[i].x,&data[i].y);
        convex_hull(data,n);
        printf("%.1lf\n",rotacion(vec,top));
    }
    return 0;
}

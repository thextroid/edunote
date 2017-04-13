#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
using namespace std;
#define pz push_back
#define sz size
const double INF = 9999.9;
const double EPS = 1e-12;
struct PT {
double x, y;
	PT() {}
	PT(double x, double y) : x(x), y(y) {}
	PT(const PT &p) : x(p.x), y(p.y) {}
	PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
	PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
	PT operator * (double c) const { return PT(x*c, y*c ); }
	PT operator / (double c) const { return PT(x/c, y/c ); }
};
double dot(PT p, PT q) { return p.x*q.x+p.y*q.y; }
double dist2(PT p, PT q) { return dot(p-q,p-q); }
double cross(PT p, PT q) { return p.x*q.y-p.y*q.x; }
PT ProjectPointSegment(PT a, PT b, PT c) {
double r = dot(b-a,b-a);
if (fabs(r) < EPS) return a;
r = dot(c-a, b-a)/r;
if (r < 0) return a;
if (r > 1) return b;
return a + (b-a)*r;
}
vector<int> PointInPolygon(const vector< vector<PT> > &p, PT q) {
	bool c = 0;
	vector<int> ans;
	for (int k = 0; k < p.sz(); ++k){
		c = 0;
		for (int i = 0; i < p[k].sz(); i++)
			if (dist2(ProjectPointSegment(p[k][i], p[k][(i+1)%p[k].size()], q), q) < EPS)
				c = true;
		if(c)		continue;
		c = 0;
		for (int i = 0; i < p[k].sz(); i++){
			int j = (i+1)%p[k].sz();
			if ((p[k][i].y <= q.y && q.y < p[k][j].y || p[k][j].y <= q.y && q.y < p[k][i].y) && q.x < p[k][i].x + (p[k][j].x - p[k][i].x) * (q.y - p[k][i].y) / (p[k][j].y - p[k][i].y))
			c = !c;
		}
		if(c)
			ans.pz(k+1);
	}
	return ans;
}
int main(){
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	char r;
	vector< vector<PT> > list;
	int k=0;
	double x,y,x1,y1;
	while(cin>>r){
	vector<PT> Rectangle;
		if(r=='*')break;
		cin>>x>>y;
		cin>>x1>>y1;
		Rectangle.pz(PT(x,y));
		Rectangle.pz(PT(x,y1));
		Rectangle.pz(PT(x1,y1));
		Rectangle.pz(PT(x1,y));
		list.pz(Rectangle);
	}
	k=1;
	while(cin>>x>>y){
		if(x==INF && y==INF)return 0;
		vector<int> res = PointInPolygon(list,PT(x,y));
		if(res.sz()!=0){
			for(int i = 0 ; i < res.sz();i++)
				printf("Point %d is contained in figure %d\n", k,res[i]);
			k++;
		}
		else
			printf("Point %d is not contained in any figure\n", k++);
	}
	return 0;
}
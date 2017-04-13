#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;
double INF = 1e100;
double EPS = 1e-12;
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

ostream &operator<<(ostream &os, const PT &p) {
	os << "(" << p.x << "," << p.y << ")";
}
PT RotateCCW90(PT p) { return PT(-p.y,p.x); }
PT RotateCW90(PT p) { return PT(p.y,-p.x); }
PT RotateCCW(PT p, double t) {
	return PT(p.x*cos(t)-p.y*sin(t), p.x*sin(t)+p.y*cos(t));
}
PT ProjectPointLine(PT a, PT b, PT c) {
	return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}
PT ProjectPointSegment(PT a, PT b, PT c) {
	double r = dot(b-a,b-a);
	if (fabs(r) < EPS) return a;
	r = dot(c-a, b-a)/r;
	if (r < 0) return a;
	if (r > 1) return b;
	return a + (b-a)*r;
}
double DistancePointSegment(PT a, PT b, PT c) {
	return sqrt(dist2(c, ProjectPointSegment(a, b, c)));
}
double DistancePointPlane(double x, double y, double z,
	double a, double b, double c, double d)
{
	return fabs(a*x+b*y+c*z-d)/sqrt(a*a+b*b+c*c);
}
bool LinesParallel(PT a, PT b, PT c, PT d) {
	return fabs(cross(b-a, c-d)) < EPS;
}

	bool PointInPolygon(const vector<PT> &p, PT q) {
		bool c = 0;
		int n=p.size();
		for (int i = 0; i < n; i++){
			if (dist2(ProjectPointSegment(p[i], p[(i+1)%n], q), q) < EPS)
				return false;
			int j = (i+1)%n;
			if ((p[i].y <= q.y && q.y < p[j].y ||
				p[j].y <= q.y && q.y < p[i].y) &&
				q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
				c = !c;
		}
		return c;
	}
	int main() {
		int nt,a,b,x,y;
		freopen("../data.in","r",stdin);
		freopen("../data.out","w",stdout);
		scanf("%d",&nt);
		while(nt--){
			vector<PT> v;
			scanf("%d %d",&a,&b);
			for(int i=0;i<a;++i){
				scanf("%d %d",&x,&y);
				v.push_back(PT(x,y));
			}
			int counter=0;
			for(int i=0;i<b;++i){
				scanf("%d %d",&x,&y);
				counter = counter + (PointInPolygon(v,PT(x,y)));
			}
			printf("%d\n", counter);
		}

		return 0;
	}

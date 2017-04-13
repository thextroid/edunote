#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
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
double ComputeSignedArea(const vector<PT> &p) {
	double area = 0;
	for(int i = 0; i < p.size(); i++) {
		int j = (i+1) % p.size();
		area += p[i].x*p[j].y - p[j].x*p[i].y;
	}
	return area / 2.0;
}
double ComputeArea(const vector<PT> &p) {
	return fabs(ComputeSignedArea(p));
}
int main(){
	freopen("../data.in","r",stdin);
	freopen("../data.out","w",stdout);
	vector<PT> v;
	int NT;
	scanf("%d",&NT);
	double a,b,c,d;
	while(NT--){
		scanf("%lf %lf %lf %lf",&a,&b,&c,&d);
		v.push_back(PT(0,0));
		v.push_back(PT(a,b));
		v.push_back(PT(c,d));
		printf("%.1lf\n", ComputeArea(v));
		v.clear();
	}
	return 0;
}
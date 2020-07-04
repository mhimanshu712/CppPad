#include <bits/stdc++.h>
using namespace std;

struct Point {
	double x,y;
};

class Polygon {
public:
	Point* points;
	Polygon(int npoints){
		points = new Point[npoints];
	}
};

double areaPoly(Polygon p,int n){
	double fArea = 0;
	for(int i=1;i<n-1;i++){
		double x1 = p.points[i].x - p.points[0].x;
		double y1 = p.points[i].y - p.points[0].y;
		double x2 = p.points[i+1].x - p.points[0].x;
		double y2 = p.points[i+1].y - p.points[0].y;

		double cross_p = x1*y2 - y1*x2;
		fArea += cross_p;
	}

	return abs(fArea/2);
}

int main(){
	int n; cin>>n;
	Polygon p(n);
	for(int i=0;i<n;i++){
		cin>>p.points[i].x>>p.points[i].y;
	}

	cout<<areaPoly(p,n);
	return 0;
}
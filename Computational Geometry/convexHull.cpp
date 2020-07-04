#include <bits/stdc++.h>
using namespace std;

struct Point {
	int x,y;
};

bool toChange(Point p,Point q,Point r){
	int x1 = q.x - p.x;
	int y1 = q.y - p.y;
	int x2 = r.x - q.x;
	int y2 = r.y - q.y;

	int val = x1*y2 - x2*y1;
	// if val == 0 then lines are collinear, and no change will be made
	return val > 0;
}

void convexHull(Point* points,int n){
	vector<Point> hull;

	// Find leftmost point
	int left = 0;
	for(int i=1;i<n;i++){
		if(points[i].x < points[left].x) left = i;
	}

	int p = left;

	while(1){
		hull.push_back(points[p]);
		int q = (p+1)%n;

		for(int i=0;i<n;i++){
			if(toChange(points[p],points[q],points[i])) q = i;
		}
		p = q;
		if(p == left) break;
	}

	for(auto i : hull){
		cout<<i.x<<" "<<i.y<<endl;
	}
}

int main(){
	Point points[] = {{0,4},{1,1},{2,2},{4,0},{4,4},{0,0},{3,3}};
	convexHull(points,7);
	return 0;
}
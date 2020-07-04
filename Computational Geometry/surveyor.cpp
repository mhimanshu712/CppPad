#include<bits/stdc++.h>
using namespace std;

struct point {
    double x,y;
};

class polygon {
    public:
    point* points;
    int n;
    polygon(int na){
        n = na;
        points = new point[na];
    }
};

double Area(polygon p){
    double res = 0;
    for(int i=1;i<p.n-1;i++){
        double x1 = p.points[i].x - p.points[0].x;
        double y1 = p.points[i].y - p.points[0].y;
        double x2 = p.points[i+1].x - p.points[0].x;
        double y2 = p.points[i+1].y - p.points[0].y;
        
        double area = x1*y2 - x2*y1;
        res += area;
    }
    
    return abs(res/2);
}

int main() {
    string s; cin>>s;
    int n = s.length();
    int* arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    polygon poly(n);
    
    
    int x = 0,y=0;
    for(int i=0;i<n;i++){
        if(s[i] == 'N') y += arr[i];
        if(s[i] == 'S') y -= arr[i];
        if(s[i] == 'E') x += arr[i];
        if(s[i] == 'W') x -= arr[i];
        
        poly.points[i] = {x,y};
    }
    
    cout<<Area(poly);
}
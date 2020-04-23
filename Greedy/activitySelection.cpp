#include<bits/stdc++.h>
using namespace std;

typedef struct{
    int start;
    int end;
}interval;


bool ssort(interval a,interval b){
    if(b.end > a.end) return true;
    return false;
}

int main()
{
    int n;
    cin>>n;
    interval * sarr = new interval[n];
    
    for(int i=0;i<n;i++){
        cin>>sarr[i].start;
        cin>>sarr[i].end;
    }
    
    sort(sarr,sarr+n,ssort);
    
    int e=0,c=0;
    for(int i=0;i<n;i++){
        if(e <= sarr[i].start){ e=sarr[i].end; c++;}
    }
    
    cout<<c;
    
    return 0;
}
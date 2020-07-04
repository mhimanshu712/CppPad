#include<bits/stdc++.h>
using namespace std;

int grundy(int n){
    if(n == 0) return 0;
    
    int a = grundy(n/2);
    int b = grundy(n/3);
    int c = grundy(n/6);
    set<int> s{a,b,c};
    int mex = 0;
    while(s.find(mex) != s.end()) mex++;
    
    return mex;
}

int main() {
	int n; cin>>n;
	cout<<grundy(n);
}
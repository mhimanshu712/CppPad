#include<iostream>
using namespace std;

int gcd(int a,int b){
    if(b == 0) return a;
    return gcd(b,a%b);
}

int main(){
    int t; cin>>t;
    while(t--){
        string a;
        int b;
        cin>>b>>a;
        if(b == 0){
            cout<<0<<endl;
            continue;
        }
    
        int prev = 0,curr=0;
        for(int i=0;i<a.length();i++){
            curr = (10*prev + (a[i]-'0'))%b;
            prev = curr;
        }
        
        curr = curr%b;
        cout<<gcd(b,curr)<<endl;
    }
    
    return 0;
}
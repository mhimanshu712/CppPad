#include<bits/stdc++.h>
using namespace std;

typedef long long llong;

llong power(llong a,string b,llong mod){
    llong res = 1,x=a;
    for(int i=b.length()-1;i>=0;i--){
        if(b[i] == '1') res = (res*x)%mod;
        if(b[i] == '2') res = ((res*x)%mod*x)%mod;
        x = (((x*x)%mod)*x)%mod;
    }
    
    return res;
}

int main() {
    int t; cin>>t;
    while(t--){
        llong a,m;
        string b;
        cin>>a>>b>>m;
        cout<<power(a,b,m)<<endl;
    }
}
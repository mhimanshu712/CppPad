#include<bits/stdc++.h>
using namespace std;

typedef long long llong;

llong modPow(llong a,llong n,llong mod){
    if(n == 0) return 1;
    
    llong ans;
    if(n%2){
        llong t = modPow(a,n-1,mod);
        ans = a%mod;
        ans = (ans*t)%mod;
    }else{
        llong t = modPow(a,n/2,mod);
        ans = (t*t)%mod;
    }
    return (ans+mod)%mod;
}


int main() {

	int t; cin>>t;
    while(t--){
        llong n,p,ans=100;
        cin>>n>>p;
        if(n>=p) ans = 0;
        if(n<p){
            llong res = 1;
            for(llong i=n+1;i<p;i++){
                res = (res*modPow(i,p-2,p))%p;
            }
            ans = -res + p;
        }
        cout<<ans<<endl;
    }
}
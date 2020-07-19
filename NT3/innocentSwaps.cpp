#include<bits/stdc++.h>
using namespace std;

const int mod = pow(10,9)+7;
const int MAX = pow(10,6)+3;
typedef long long llong;

int* getFact(){
    int* fact = new int[MAX];
    fact[0] = 1;
    for(int i=1;i<MAX;i++){
        fact[i] = ((llong)fact[i-1]*i)%mod;
    }
    return fact;
}

llong power(int a,int n){
    llong res = 1;
    llong x = a;
    while(n > 0){
        if(n & 1) res = (res*x)%mod;
        x = (x*x)%mod;
        n /= 2;
    }
    return (res+mod)%mod;
}

int main() {
    int t; cin>>t;
    int* fact = getFact();

    while(t--){
        int n,k; 
        cin>>n>>k;
        llong res = (fact[n]/(fact[n-k]*fact[k]))*pow(2,k);
        llong arr[4];
        arr[0] = fact[n];
        arr[1] = power(fact[n-k],mod-2);
        arr[2] = power(fact[k],mod-2);
        arr[3] = power(2,k);
        
        llong ans = 1;
        for(int i=0;i<4;i++){
            ans = (ans*arr[i])%mod;
        }
        
        cout<<ans<<endl;
    }
}
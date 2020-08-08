#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool distribute(ll * arr,ll n, ll k,ll s){
    int i =0;
    ll t;
    
    if(s == 0) return true;
    while(i < n && k>0){
        t = (arr[i] / s);
        k -= t;
        i++;
    }
    
    if(k <= 0) return true;
    
    return false;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        ll k;
        cin>>n>>k;
        
        ll * arr = new ll[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        sort(arr,arr+n,greater<ll>());
        
        ll a = 0,b = arr[0], m, maxi;
        
        while(a<=b){
            m = (a+b)/2;
            if(distribute(arr,n,k,m)){
                maxi = m;
                a = m+1;
            }else{
                b = m-1;
            }
        }
        
        cout<<maxi<<endl;
    }
    
    return 0;
}

  
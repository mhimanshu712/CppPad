#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll balls(ll n,ll k){
    ll sharma = 0;
    
    while(n>0){
        if(n>=k){
            n = n-k;
            sharma = sharma + k;
            
            if(n<k){
                sharma += n;
                n = 0;
            }
            ll t = n /10;
            n = n - t;
             
        }else{
            sharma += n;
            n=0;
        }
    }
    
    return sharma;
}

int main()
{
    ll n;
    cin>>n;
    
    ll a = 1, b = n,k,mink=LLONG_MAX;
    
    while(a<=b){
        k = (a+b)/2;
        
        if(2*balls(n,k)<n) a = k+1;
        else{
            mink = min(mink,k);
            b = k-1;
        }
        
    }
    
    cout<<mink;
    
	return 0;
}
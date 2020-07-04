#include<bits/stdc++.h>
using namespace std;

typedef long long llong;

struct node {
    llong x,y,gcd;
};

node extEuclid(llong a,llong b){
    if(b == 0){
        node ans = {1,0,a};
        return ans;
    }
    
    node prev = extEuclid(b,a%b);
    node ans;
    ans.x = prev.y;
    ans.y = prev.x - (a/b)*prev.y;
    ans.gcd = prev.gcd;
    return ans;
}

llong mmInverse(llong a,llong m){
    llong ans = extEuclid(a,m).x;
    //if(ans<0) (ans += m);
    //return ans%m;
    return (ans%m +m)%m;
}

int main(){
    int t; cin>>t;
    while(t--){
        llong a,b,d;
        cin>>a>>b>>d;
        llong g = __gcd(a,b);
        if(d%g != 0){
            cout<<0<<endl;
            continue;
        }
        a /= g;
        b /= g;
        d /= g;
        if(d == 0){
            cout<<1<<endl;
            continue;
        }
        
        
        llong y1 = ((d%a) * mmInverse(b,a))%a;
        if(d/b < y1){
            cout<<0<<endl;
            continue;
        }
        llong n = ((d/b) - y1)/a;
        cout<<n+1<<endl;
    }
    return 0;
}
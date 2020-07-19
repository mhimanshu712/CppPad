#include<bits/stdc++.h>
using namespace std;

const int MAX = pow(10,6)+1;
typedef long long ll;

vector<int> getPrimes(){
    bool* primes = new bool[MAX]();
    vector<int> res;
    for(int i=2;i<MAX;i++){
        if(primes[i] == true) continue;
        res.push_back(i);
        for(int j=2*i;j<MAX;j+=i){
            primes[j] = true;
        }
    }
    return res;
}

int main() {
    int t; cin>>t;
    vector<int> primes = getPrimes();
    while(t--){
        ll l,r,k;
        cin>>l>>r>>k;
        ll* arr = new ll[r-l+1];
        ll* brr = new ll[r-l+1];
        for(ll i = 0;i<=(r-l);i++) arr[i] = brr[i] = i+l;
        
        for(auto prime : primes){
            ll base = prime*(l/prime);
            while(base<l) base+=prime;
            for(ll i=base;i<=r;i+=prime){
                arr[i-l] = (arr[i-l]*(prime-1))/prime;
                while(brr[i-l]%prime==0) brr[i-l] /= prime;
            }
        }
        for(ll i=l;i<=r;i++){
            if(brr[i-l]>1){
                arr[i-l] = (arr[i-l]*(brr[i-l]-1))/brr[i-l];
            }
        }
        
        int num=0;
        for(ll i=l;i<=r;i++){
            if(arr[i-l]%k==0) num++;
        }
        
        float res = (float)num/(r-l+1);
        //cout<<fixed<<setprecision(6)<<res<<endl;  //Why this crap
        printf("%f\n",res);
        
    }
    return 0;
}
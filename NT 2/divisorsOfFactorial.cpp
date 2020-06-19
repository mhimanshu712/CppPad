#include <bits/stdc++.h>
using namespace std;

const int mod = pow(10,9)+7;

long find(int n){
    long count;
    bool* sieve = new bool[n+1]();
    vector<long> res;
    for(int i=2;i*i<=n;i++){
        if(!sieve[i]){
            for(int j=i*i;j<=n;j+=i) sieve[j] = true;
        }
    }

    for(int i=2;i<=n;i++){
        if(!sieve[i]){
            count = 0;
            for(int k=1;pow(i,k)<=n;k++){
                long prev = count;
                count = ( count + ( n/(int)(pow(i,k) + 0.5) ) )%mod;
                cout<<"For "<<i<<" "<<k<<" "<<(int)(pow(i,k)+0.5)<<" "<<count-prev<<endl;
            }
            res.push_back(count);
        }
    }
    long ans = 1;
    for(i : res){
        ans = (ans * (i+1))%mod;
    }
    return ans;
}

int main(){
	int t; cin>>t;
    while(t--){
        int n; cin>>n;
        cout<<find(n)<<endl;
    }
	return 0;
}
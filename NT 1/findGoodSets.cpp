#include<bits/stdc++.h>
using namespace std;

const int mod = pow(10,9)+7;
const int MAX = pow(10,6);

long getSets(int* arr,int n){
    int* sieve = new int[MAX+1]();
    sort(arr,arr+n);
    for(int i=0;i<n;i++) sieve[arr[i]] = 1;
    
    for(int i=0;i<n;i++){
        int idx = arr[i];
        for(int j=2*idx;j<=MAX;j+=idx){
            if(sieve[j] > 0) sieve[j] = (sieve[j]+sieve[idx])%mod; 
        }
    }
    
    long count = 0;
    for(int i=0;i<n;i++){
        count = (count + sieve[arr[i]])%mod;
    }
    
    return count;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int* arr = new int[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        long ans = getSets(arr,n);
        cout<<ans<<endl;
    }
    return 0;
}
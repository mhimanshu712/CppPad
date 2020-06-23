#include <bits/stdc++.h>
using namespace std;

const int MAX = pow(10,6);

vector<long>* getPrimes(){
    bool* sieve = new bool[MAX]();
    vector<long>* res = new vector<long>;
    for(long i=2;i*i<MAX;i++){
        if(!sieve[i]){
            for(long j=i*i;j<MAX;j+=i) sieve[j] = true;
        }
    }
    
    for(long i=2;i<MAX;i++) 
        if(!sieve[i]) res->push_back(i);
    return res;
}

int main()
{
    int t; cin>>t;
    vector<long>* primes = getPrimes();
    while(t--){
        long long l,u;
        cin>>l>>u;
        
        bool* sieve = new bool[u-l+1]();
        for(long i=0;primes->at(i)*primes->at(i)<=u;i++){
            long long curr = primes->at(i);
            long long j = (l/curr)*curr;
            while(j-l < 0 || curr == j) j += curr;
            
            for(;j<=u;j+=curr) sieve[j-l] = true; 
            
        }
        
        for(long long i=0;i<=u-l;i++)
            if(!sieve[i]) cout<<i+l<<endl;
    }
    
    return 0;
}
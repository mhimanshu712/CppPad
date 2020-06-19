#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin>>n;
    bool* sieve = new bool[n+1]();
    
    for(int i=2;i*i<=n;i++){
        if(!sieve[i]){
            for(int j=i*i;j<=n;j+=i) sieve[j] = true;
        }
    }
    
    int total=0;
    for(int i=2;i<=n;i++) if(!sieve[i]) total++;
    cout<<total;
}
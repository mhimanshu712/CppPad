#include<bits/stdc++.h>
using namespace std;

const int MAX = pow(10,6);

int* getSieve(){
    int* sieve = new int[MAX+1]();
    sieve[1] = 0;
    for(int i=2;i<=MAX;i++){
        if(sieve[i] == 0){
            for(int j=i;j<=MAX;j+=i) sieve[j]++;
        }
    }
    return sieve;
}

int main(){
	int t; cin>>t;
    int* sieve = getSieve();
    while(t--){
        long a,b,n;
        cin>>a>>b>>n;
        
        int count=0;
        for(int i=a;i<=b;i++){
            if(sieve[i] == n) count++;
        }
        cout<<count<<endl;
    }
    
	return 0;
}
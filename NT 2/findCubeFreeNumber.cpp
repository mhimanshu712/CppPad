#include<bits/stdc++.h>
using namespace std;

const int MAX = pow(10,6);

int* getSieve(){
    int* res = new int[MAX+1]();
    for(int i=2;i*i*i<=MAX;i++){
        long num = i*i*i;
        for(long j=num;j<=MAX;j+=num){
            res[j] = -1;
        }
    }
    
    long curr = 1;
    for(long i=1;i<=MAX;i++){
        if(res[i] == 0) res[i] = curr++;
    }
    return res;
}

int main(){
	int t; cin>>t;
    int* sieve = getSieve();
    for(int c=1;c<=t;c++){
        long n; cin>>n;
        if(sieve[n] == -1)
        	cout<<"Case "<<c<<": Not Cube Free"<<endl;
        else
            cout<<"Case "<<c<<": "<<sieve[n]<<endl;
        
    }
	return 0;
}
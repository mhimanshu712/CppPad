#include<bits/stdc++.h>
using namespace std;

const int MAX = pow(10,6)+1;
typedef long long llong;
llong* phi = NULL;

llong* getPhi(){
    llong* phi = new llong[MAX];
    for(int i=1;i<MAX;i++) phi[i] = i;
    
    for(int i=2;i<MAX;i++){
        if(phi[i] == i){
            phi[i] = i-1;
            for(int j=2*i;j<MAX;j+=i){
                phi[j] = (phi[j]*(i-1))/i;
            }
        }
    }
    
    return phi;
}

llong* getGcdSum(){
    llong* res = new llong[MAX]();
    
    for(int i=1;i<MAX;i++){
        for(int j=2;i*j<MAX;j++){
            res[i*j] += i*(llong)phi[j];
        }
    }
    
    for(int i=2;i<MAX;i++) res[i] += res[i-1];
    return res;
}

int main() {
    phi = getPhi();
    llong* gcdSum = getGcdSum();
    while(1){
        int n; cin>>n;
        if(n == 0) break;
        cout<<gcdSum[n]<<endl;
    }
}
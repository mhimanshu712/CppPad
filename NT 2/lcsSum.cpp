#include <bits/stdc++.h>
typedef long long llong;
const llong MAX = pow(10,6)+1;

llong* getPhi(){
    llong* seive = new llong[MAX]();
    for(int i=1;i<MAX;i++) seive[i] = i;
    
    for(int i=2;i<MAX;i++){
        if(seive[i] == i){
            seive[i] = i-1;
            for(int j=2*i;j<MAX;j+=i){
                seive[j] = (seive[j]*(i-1))/i;
            }
        }
    }
    return seive;
}

void func(long long n)
{
	llong* phi = getPhi();
    llong sum = 0;
    for(llong i = 1;i<=n;i++){
        if(n%i == 0) sum += i*phi[i];
    }
    sum = (n*(sum+1))/2;
    cout<<sum;
}
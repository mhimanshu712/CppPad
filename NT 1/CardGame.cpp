#include <bits/stdc++.h>
using namespace std;

typedef long long llong;

map<llong,llong> getPrimeFactors(llong n){
    map<llong,llong> res;
    llong k = 0;
    while(n%2 == 0){
        k++; n /= 2;
    }
    if(k>0) res[2] = k;
    
    for(llong i=3;i*i<=n;i+=2){
        llong k = 0;
        while(n%i == 0){
            k++; n /= i;
        }
        if(k>0) res[i] = k;
    }
    
    if(n > 2) res[n] = 1;
    
    return res;
}

bool cmpMap(map<llong,llong> factk,map<llong,llong> curr){
    for(auto i : factk){
        if(curr[i.first] < i.second) return false;
    }
    return true;
}

int main(){
	llong n,k;
    cin>>n>>k;
    llong* arr = new llong[n];
    for(llong i=0;i<n;i++) cin>>arr[i];
    
    map<llong,llong> factk = getPrimeFactors(k);
    for(auto i : factk){
      cout<<i.first<<"  "<<i.second<<endl;
    }
    // llong count = 0;
    // for(llong i=0;i<n;i++){
    //     map<llong,llong> curr;
        
    //    for(llong j=i;j<n;j++){
    //        map<llong,llong> t = getPrimeFactors(arr[j]);
    //        for(auto i : t){
    //            curr[i.first] += i.second;
    //        }
           
    //        if(cmpMap(factk,curr)){
    //           cout<<"For "<<i<<" "<<j<<endl;
    //            count += n-j;
    //            break;
    //        }
    //    }
        
    // }
    
    //cout<<count;
	return 0;
}
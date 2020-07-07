#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> getPrimeFactors(int n){
    vector<pair<int,int>> res;
    if(n==0 || n==1) return res;
    
    int count=0;
    while(n%2 == 0){
        n /= 2; count++;
    }
    if(count > 0) res.push_back(make_pair(2,count));
    
    for(int i=3;i*i<=n;i+=2){
        count = 0;
        while(n%i == 0){
            n /= i; count++;
        }
        if(count > 0) res.push_back(make_pair(i,count));
    }
    
    if(n > 2) res.push_back(make_pair(n,1));
    return res;
}


int main() {
    int n; cin>>n;
    bool* arr = new bool[n+1]();
    vector<int> res;
   
    for(int i=n;i>1;i--){
        if(!arr[i]){
            vector<pair<int,int>> pf = getPrimeFactors(i);
            
            vector<int> ires;
            for(auto j : pf){
                int el = j.first;
                if(!arr[el]){
                    for(int k = el; k<=n;k+=el){
                        if(!arr[k]) ires.push_back(k);
                        arr[k] = true;
                    }
                }
            }
            sort(ires.begin(),ires.end(),greater<int>());
            for(auto z : ires) res.push_back(z);
        }
    }
    res.push_back(1);
    
    for(auto i : res) cout<<i<<" ";
    
    return 0;
}
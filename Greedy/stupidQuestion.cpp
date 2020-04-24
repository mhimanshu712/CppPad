#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k;
    cin>>n>>k;
    int * arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    int maxi = INT_MIN, mini = INT_MAX;
    for(int i=0;i<n;i++){
        if(arr[i]<mini) mini = arr[i];
        if(arr[i]>maxi) maxi = arr[i];
    }
    int res = maxi - mini - 2*k;
    if(res<0) cout<<maxi-mini;
    else cout<<res;
}
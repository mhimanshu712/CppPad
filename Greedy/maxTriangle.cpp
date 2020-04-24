#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

void work(ll * arr,int n){
    for(int i=0;i<n;i++){
        ll z = arr[i+1] + arr[i+2];
        if(arr[i]<z){
            cout<<arr[i+2]<<" "<<arr[i+1]<<" "<<arr[i];
            return;
        }
    }
    cout<<-1;
}

int main() {
    int n;
    cin>>n;
    ll * arr = new ll[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    sort(arr,arr+n,greater<ll>());
    work(arr,n);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,k,l;
    cin>>n>>k>>l;
    int * arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    int maxi=arr[0],mini=arr[0];
    for(int i=0;i<n;i++){
        if(maxi < arr[i]) maxi = arr[i];
        if(mini > arr[i]) mini = arr[i];
    }
    
    int val,minval=INT_MAX;
    for(int i=mini;i<=maxi;i++){
        int less=0,greater=0;
        for(int j=0;j<n;j++){
            if(arr[j]>i) greater += arr[j]-i;
            if(arr[j]<i) less += i-arr[j];
        }
        val = less-greater;
        if(val<0) continue;
        else{
            val = greater*k + (less-greater)*l;
            minval = min(minval,val);
        }
    }
    
    cout<<minval;
}
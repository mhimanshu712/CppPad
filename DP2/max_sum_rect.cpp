#include <bits/stdc++.h>
using namespace std;

int kadane(int * arr,int n){
    int maxi=INT_MIN,curr=0;
    
    for(int i=0;i<n;i++){
        curr = curr + arr[i];
        maxi = max(maxi,curr);
        if(curr<0) curr = 0;
    }
    
    return maxi;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int ** arr = new int*[n];
    int * dp = new int[n]();
    for(int i=0;i<n;i++) arr[i] = new int[m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) cin>>arr[i][j];
    
    int maxsum = INT_MIN;
    for(int i=0;i<m;i++){
        for(int j=i;j<m;j++){
            if(i==j)for(int k=0;k<n;k++) dp[k] = arr[k][i];
            else for(int k=0;k<n;k++) dp[k] += arr[k][j];
            int res = kadane(dp,n);
            maxsum = max(maxsum,res);
        }
        
        
    }
             
    cout<<maxsum;
    
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int MOD = pow(10,9) + 7;

int alpha(int * arr,int n,int * dp){
    if(n <= 1) return 1;
    if(dp[n] > -1) return dp[n];
    
    int p1 = 0,p2  = 0;
    if(arr[n] != 0) p1 = alpha(arr,n-1,dp);
    if(arr[n-1]*10+arr[n] <= 26 && arr[n-1]*10 + arr[n] >= 10) p2 = alpha(arr,n-2,dp);
    
    int res = (p1+p2)%MOD;
    dp[n] = res;
    return res;
}

int main(){
    string s;
    while(1){
        cin>>s;
        if(s == "0") break;
        
        int n = s.length()+1;
        int * arr = new int[n + 1];
        int * dp = new int[n + 1];
        for(int i=1;i<n;i++) arr[i] = s[i-1] - '0';
        for(int i=0;i<n;i++) dp[i] = -1;
        
        int res = alpha(arr,n-1,dp);
        cout<<res<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int harry(int ** arr,int r,int c,int a,int b,int ** dp){
    if(a == r-1 && b == c-1) return 1;
    if(a>=r || b>= c) return 99999;
    
    if(dp[a][b] > -1) return dp[a][b];
    
    int p1 = harry(arr,r,c,a+1,b,dp);
    int p2 = harry(arr,r,c,a,b+1,dp);
    
    int res = min(p1,p2) - arr[a][b];
    res = max(1,res);
    dp[a][b] = res;
    return res;
}

int main()
{
    int t;
    cin>>t;
    
    while(t--){
        int r,c;
        cin>>r>>c;
        int ** arr = new int*[r];
        int ** dp = new int*[r];
        for(int i=0;i<r;i++){
            arr[i] = new int[c];
            dp[i] = new int[c];
        }
        
        for(int i=0;i<r;i++) for(int j=0;j<c;j++){
            cin>>arr[i][j];
            dp[i][j] = -1;
        }
        
        
        int res = harry(arr,r,c,0,0,dp);
        cout<<res<<endl;
    }
    return 0;
}

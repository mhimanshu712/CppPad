#include <iostream>
using namespace std;

long long solve(int n,int mask,long long* dp){
    if(mask == (1<<n)-1) return 1;
    if(dp[mask] > -1) return dp[mask];
    
    long long count = 0;
    for(int i=0;i<n;i++){
        if(!(mask&(1<<i))){
            // Check if valid
            bool flag = true;
            for(int k=1;k<=n;k++){
                if((i+1&k) == (i+1)){
                    if((mask&(1<<(k-1)))) flag = false;
                }
                
                // What if (i+1&k) == k ?
                // It gets handled automatically by further calls
            }
            if(flag) count += solve(n,(mask|(1<<i)),dp);
        }
    }
    dp[mask] = count;
    return count;
}

int main()
{
    int n; cin>>n;
    int mask = 0;
    long long* dp = new long long[(1<<n)+1];
    for(int i=0;i<(1<<n)+1;i++) dp[i] = -1;
    long long res = solve(n,mask,dp);
    cout<<res;
    return 0;
}


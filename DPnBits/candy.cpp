long long count(int arr[][MAXN],int n,int mask,int p,long long* dp){
    if(p == n-1){
        for(int i=0;i<n;i++){
            if(!(mask&(1<<i))) if(arr[p][i] == 1) return 1;
        }
        return 0;
    }
    if(dp[mask] > -1) return dp[mask];
    
    long long val = 0;
    for(int i=0;i<n;i++){
        if(!(mask&(1<<i))){
            if(arr[p][i] == 1){
             val += count(arr,n,(mask|(1<<i)),p+1,dp);   
            }
        }
    }
    dp[mask] = val;
    return val;
}


long long solve(int like[][MAXN],int n)
{
	int n2 = (1<<n);
    long long* dp = new long long[n2];
    for(int i=0;i<n2;i++) dp[i] = -1;
    long long res = count(like,n,0,0,dp);
    return res;
}
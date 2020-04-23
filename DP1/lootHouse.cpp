#include <bits/stdc++.h>
using namespace std;

int loot(int *arr,int n,int * dp){
    if(n<0) return 0;
    if(n==0) return arr[n];
   
    if(dp[n]>-1) return dp[n];
    int p1 = loot(arr,n-1,dp);
    int p2 = arr[n] + loot(arr,n-2,dp);
    
    dp[n] = max(p1,p2);
    return max(p1,p2);
}

int getMaxMoney(int arr[], int n){
    int * dp = new int[n];
    for(int i=0;i<n;i++) dp[i] = -1;
    int res = loot(arr,n-1,dp);
    return res;
}

int getMaxMoneyR(int arr[], int n){
    int * dp = new int[n];
    
    dp[0] = arr[0];
    dp[1] = max(arr[0],arr[1]);
    for(int i=2;i<n;i++) dp[i] = max(dp[i-1],dp[i-2]+arr[i]);
    return dp[n-1];
}

int main(){
	int n;
	cin>>n;
	int * arr = new int[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	int res = getMaxMoney(arr,n);
	cout<<res;
}

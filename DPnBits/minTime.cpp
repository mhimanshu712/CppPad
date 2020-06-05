#include <bits/stdc++.h>
using namespace std;

int minCost(int cost[][4],int n,int p,int mask,int* dp){
	if(p>=n) return 0;
	if(dp[mask] > -1) return dp[mask];

	int mini = INT_MAX;
	for(int j=0;j<n;j++){
		if(!(mask&(1<<j))){
			int ans = cost[p][j] + minCost(cost,n,p+1,mask|(1<<j),dp);
			mini = min(mini,ans);
		}
	}
	dp[mask] = mini;
	return mini;
}

int main(){
	int cost[4][4] = {{10,2,6,5},{1,15,12,8},{7,8,9,3},{15,13,4,10}};
	int* dp = new int[1<<4];  // 2^4
	for(int i=0;i<(1<<4);i++) dp[i] = -1;
	int res = minCost(cost,4,0,0,dp);
	cout<<res<<endl;
	return 0;
}
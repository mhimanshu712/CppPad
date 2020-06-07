#include <bits/stdc++.h>
using namespace std;

// (1<<n)-1 gives 0001111 kind of thingy

int find_touches(int pos,int mask,vector<string>&v,int** dp){
	// For a number in 2^n form.   a&(a-1) = 0
	if((mask&(mask-1)) == 0) return 0;
	if(pos<0) return 10000;

	if(dp[pos][mask] > -1) return dp[pos][mask]; 

	int newmask1 = 0;
	int newmask2 = 0;
	int touches = 0;

	for(int i=0;i<v.size();i++){
		if(mask&(1<<i)){
			touches++;
			if(v[i][pos] == '0') newmask1 |= 1<<i;
			else newmask2 |= 1<<i;
		}
	}
	int ans1 = find_touches(pos-1,newmask1,v,dp) + find_touches(pos-1,newmask2,v,dp) + touches;
	int ans2 = find_touches(pos-1,mask,v,dp);
	int ans = min(ans1,ans2);
	dp[pos][mask] = ans;
	return ans;
}

int minTouchesRequired(int n,vector<string>v){

	int** dp = new int*[v[0].size()];
	for(int i=0;i<v[0].size();i++){
		dp[i] = new int[1<<(n+1)];
		for(int j=0;j<(1<<(n+1));j++) dp[i][j] = -1;
	}
	return find_touches(v[0].size()-1,(1<<n)-1,v,dp);
}

int main(){

}
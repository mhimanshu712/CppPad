#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll kadane(int * arr, int n){
	ll curr = 0, max = 0;
	for(int i=0;i<n;i++){
		curr = curr + arr[i];
		if(curr > max) max = curr;
		if(curr < 0) curr = 0;
	}

	return max;
}

ll k_concat(int * arr,int n,int k){
	ll ksum = kadane(arr,n);
	if(k==1) return ksum;

	ll precurr =0,  premax = INT_MIN;
	ll postcurr =0, postmax = INT_MIN;
	ll totalsum, ans;
	for(int i=0;i<n;i++){
		precurr += arr[i];
		premax = max(premax,precurr);
	}
	totalsum = precurr;

	for(int i=n-1;i>=0;i--){
		postcurr += arr[i];
		postmax = max(postmax,postcurr);
	}

	if(totalsum <= 0){
		ans = max(premax+postmax,ksum);
	}else{
		ans = max(premax+postmax+(k-2)*totalsum,ksum);
	}

	return ans;
}

int main(){
	int n,k;
	cin>>n>>k;
	int * arr = new int[n];
	for(int i=0;i<n;i++) cin>>arr[i];

	ll ans = k_concat(arr,n,k);
	cout<<"The ans is: "<<ans<<endl;
}
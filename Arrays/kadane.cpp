#include <bits/stdc++.h>

using namespace std;

int kadane(int * arr, int n){
	int curr = 0, max = 0;
	for(int i=0;i<n;i++){
		curr = curr + arr[i];
		if(curr > max) max = curr;
		if(curr < 0) curr = 0;
	}

	return max;
}

int main(){
	int n;
	cin>>n;
	int * arr = new int[n];
	for(int i=0;i<n;i++) cin>>arr[i];

	int ans = kadane(arr,n);
	cout<<"The ans is: "<<ans<<endl;
}
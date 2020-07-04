#include <bits/stdc++.h>
using namespace std;

int power(int x,int n,int mod){
	if(n == 0) return 1;

	if(n%2 == 0){
		long val = power(x,n/2,mod);
		long ans = (val*val)%mod;
	}else{
		long val = power(x,n-1,mod);
		long ans = x%mod;
		ans = (val*ans)%mod;
	}

	return (int)((ans + mod)%mod);
}

int main(){
	int x,n; cin>>x>>n;
	cout<<power(x,n,2000);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	// Using float here is a bad practice;
	// See EulerTotient Ext for a better approach
	float res = 1;
	bool* sieve = new bool[n+1]();
	for(int i=2;i*i<=n;i++){
		if(!sieve[i]){
			for(int j=i*i;j<=n;j+= i) sieve[j] = true;
		}
	}

	
	for(int i=2;i<=n;i++){
		if(!sieve[i] && n%i==0) res *= (1-1/(float)i);
	}
	cout<<n*res;
}
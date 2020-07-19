#include <bits/stdc++.h>
using namespace std;

int power(int a,int b,int mod){
	int res = 1;
	int x = a;
	while(b > 0){
		if(b & 1) res = (res*x)%mod;
		x = (x*x)%mod;
		b /= 2;
	}
	return res;
}

int main(){
	int a,b;
	cin>>a>>b;
	cout<<power(a,b,1000000);
	return 0;
}
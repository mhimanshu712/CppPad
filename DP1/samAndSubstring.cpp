#include <bits/stdc++.h>

using namespace std;

const int MOD = pow(10,9) + 7;

int som(string s,int n,int i,int * dp){
	if(n<0) return 0;
	int p1 = som(s,n-1,i,dp);
	int p2 = (s[n]-'0')*pow(10,i) + som(s,n-1,i+1,dp);
	//cout<<"n: "<<n<<" i: "<<i<<" Addin: "<<s[n]-'0'<<endl;
	p2 = p2%MOD;

	return (p1+p2)%MOD;
}


int subs(string s){
	int * dp = new int[s.length()];
	for(int i=0;i<s.length();i++) dp[i] = -1;
	int res = som(s,s.length()-1,0,dp);
	return res;
}

int main(){
	string s;
	cin>>s;
	int res = subs(s);
	cout<<res<<endl;
}
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> getPrimeFactors(int n){
	vector<pair<int,int>> res;
	int k=0;
	while(n%2 == 0){
		k++;
		n /= 2;
	}
	if(k > 0) res.push_back(make_pair(2,k));
	
	for(int i=3;i*i<=n;i+=2){
		int k=0;
		while(n%i == 0){
			k++;
			n /= i;
		}
		if(k > 0) res.push_back(make_pair(i,k));
	}
	
	if(n > 2) res.push_back(make_pair(n,1));
	
	return res;
}

int main(){
	int n; cin>>n;
	vector<pair<int,int>> res = getPrimeFactors(n);
	for(auto i : res){
		cout<<i.first<<" "<<i.second<<endl;
	}
	return 0;
}

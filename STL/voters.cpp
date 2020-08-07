#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b,c;
	cin>>a>>b>>c;
	int total = a+b+c;
	vector<int> arr(total);
	vector<int> res;
	for(int i=0;i<total;i++) cin>>arr[i];
	sort(arr.begin(),arr.end());
	int count=0;

	for(int i=0;i<total-1;i++){
		if(arr[i] == arr[i+1]){
			count++;
			res.push_back(arr[i]);
			if((i+2< total) && arr[i] == arr[i+2]) i++;
		}
	}

	cout<<count<<endl;
	for(auto a : res){
		cout<<a<<endl;
	}
	return 0;
}

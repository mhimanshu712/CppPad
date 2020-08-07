#include <bits/stdc++.h>
using namespace std;

typedef long long llong;

int main(){
	int n,m;
	cin>>n>>m;
	llong arr[n];
	for(int i=0;i<n;i++) cin>>arr[i];
	sort(arr,arr+n);
	queue<llong> q;
	int count = 0;
	int end = n-1;

	while(m--){
		int curr;
		cin>>curr;
		llong ans;
		for(; count < curr; count++){
			if(end >=0 && (q.empty() || (arr[end] >= q.front()))){
				ans = arr[end];
				end--;
			}else{
				ans = q.front();
				q.pop();
			}
			q.push(ans/2);
		}
		cout<< ans<<endl;
	}
	
	return 0;
}
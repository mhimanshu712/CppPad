#include <bits/stdc++.h>

using namespace std;

int main(){
	int in;
	cin>>in;
	n = in;
	if(in < 3) n = 3;
	long * arr = new long[n+1];
	arr[0] = arr[1] = 1, arr[2] = 2;
	for(int i=3;i<n+1;i++) arr[i] = arr[i-1]+arr[i-2]+arr[i-3];
	cout<<arr[n];
}
#include <bits/stdc++.h>

using namespace std;

void update(int index,int value,int* BIT,int n){
	for(;index <= n;index += index&(-index)){
		BIT[index] += value;
	}
}

int query(int index,int* BIT){
	int sum = 0;
	for(;index > 0;index -= index&(-index)){
		sum += BIT[index];
	}
	return sum;
}

int main(){
	int n; cin>>n;
	int* arr = new int[n+1]();
	int* bitree = new int[n+1]();

	for(int i=1;i<=n;i++){
		cin>>arr[i];
		update(i,arr[i],bitree,n);
	}
	cout<<"Built";

	cout<<"Sum of first 5 elements "<<query(5,bitree)<<endl;
	cout<<"Sum of elements from index 2 to index 6"<<query(6,bitree)-query(1,bitree)<<endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define MMAX 1000000

struct event{
	int first,second;
	int index;
};

bool comp(event a,event b){
	return a.second<b.second;
}

void update(int index,int val,int n,int* bit){
	for(;index<=n; index += (index&(-index))){
		bit[index] += val;
	}
}

int value(int index,int* bit){
	int count = 0;
	for(;index>0;index -= (index&(-index))){
		count += bit[index];
	}
	return count;
}

int main(){
	int n; cin>>n;
	int* arr = new int[n+1];
	for(int i=0;i<=n;i++) cin>>arr[i];
	int q; cin>>q;
	event* query = new event[q];
	for(int i=0;i<q;i++){
		cin>>query[i].first>>query[i].second;
		query[i].index = i;
	}
	sort(query,query+q,comp);

	int* bit = new int[n+1];
	int* ans = new int[q];

	int total = 0;
	int k = 0;
	int* last = new int[MMAX+1];
	for(int i=0;i<MMAX;i++) last[i] = -1;

	for(int i=1;i<=n;i++){
		if(last[arr[i]] != -1){
			update(last[arr[i]],-1,n,bit);
		}else{
			total++;
		}

		update(i,1,n,bit);
		last[arr[i]] = i;
		while(k<q && query[k].second == i){
			ans[query[k].index] = total - value(query[k].first-1,bit);
			k++;
		}
	}

	for(int i=0;i<q;i++) cout<<ans[i]<<endl;
	return 0;
}
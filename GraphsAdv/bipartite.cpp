#include <bits/stdc++.h>
using namespace std;

bool bipartite(vector<int>* edges,int n){
	if(n==0) return true;

	unordered_set<int> sets[2];
	vector<int> pending;
	sets[0].insert(0);
	pending.push_back(0);

	while(pending.size()>0){
		// Here order dosen't matter, and popping end of a vector is cheaper so..
		int curr = pending.back();
		pending.pop_back();
		int currSet = sets[0].count(curr) > 0?0:1;
		for(int i=0;i<edges[curr].size();i++){
			int mate = edges[curr][i];
			if(sets[0].count(mate) == 0 && sets[1].count(mate) == 0){
				sets[1-currSet].insert(mate);
				pending.push_back(mate);
			}else if(sets[currSet].count(mate) > 0){
				return false;
			}
		}
	}
	return true;
}

int main(){
	while(1){
		int n; cin>>n;
		if(n == 0) break;

		vector<int>* edges = new vector<int>[n];
		int m; cin>>m;
		for(int i=0;i<m;i++){
			int j,k;
			cin>>j>>k;
			edges[j].push_back(k);
			edges[k].push_back(j);
		}

		bool ans = bipartite(edges,n);
		if(ans) cout<<"BiColor"<<endl;
		else cout<<"Not a colorfull person"<<endl;
	}
	return 0;
}
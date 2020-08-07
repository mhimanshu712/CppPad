#include <bits/stdc++.h>
using namespace std;
int x,n,t;

vector<int> adj[300010];
bool visited[300010];

void dfs(int i){
	visited[i] = true;
	for(int j: adj[i]){
		if(!visited[j]){
			dfs(j);
		}
	}
}

int main(){
	memset(visited,false,sizeof visited);
	cin>>n>>t;
	for(int i=1;i<n;i++){
		cin>>x;
		adj[i].push_back(x+i);
	}
	dfs(1);
	if(visited[t]) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>* edges,bool* vis,int n,int a,unordered_set<int>* part){
    vis[a] = true;
    part->insert(a);
    for(int i=0;i<edges[a].size();i++){
        int ele = edges[a][i];
        if(!vis[ele]) dfs(edges,vis,n,ele,part);
    }
}

unordered_set<unordered_set<int>*>* getComp(vector<int>* edges,int n){
    unordered_set<unordered_set<int>*>* parts = new unordered_set<unordered_set<int>*>;
    bool* vis = new bool[n]();
    for(int i=0;i<n;i++){
        if(!vis[i]){
            unordered_set<int>* part = new unordered_set<int>;
            dfs(edges,vis,n,i,part);
            parts->insert(part);
        }
    }
    return parts;
}

int main()
{
	int t; cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>* edges = new vector<int>[n];
        while(m--){
            int x,y;
            cin>>x>>y;
            edges[--x].push_back(--y);
            edges[y].push_back(x);
        }
        int* items = new int[n];
        for(int i=0;i<n;i++) cin>>items[i];
        
        unordered_set<unordered_set<int>*>* res = getComp(edges,n);
        long long maxi = LLONG_MIN;
        for(auto i : *res){
            long long curr = 0;
            for(j : *i) curr += items[j];
            maxi = max(maxi,curr);
        }
        cout<<maxi<<endl;
    }
	return 0;
}

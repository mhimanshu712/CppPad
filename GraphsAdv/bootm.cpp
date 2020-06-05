#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>* edges,int n,int a,bool* vis,stack<int> &finstack){
    vis[a] = true;
    for(int i=0;i<edges[a].size();i++){
        int ele = edges[a][i];
        if(!vis[ele]){
            dfs(edges,n,ele,vis,finstack);
        }
    }
    finstack.push(a);
}

void dfsc(vector<int>* edges,int n,int a,bool* vis,unordered_set<int>* part,int* compmap,int compcount){
    vis[a] = true;
    compmap[a] = compcount;
    part->insert(a);
    for(int i=0;i<edges[a].size();i++){
        int ele = edges[a][i];
        if(!vis[ele]){
            dfsc(edges,n,ele,vis,part,compmap,compcount);
        }
    }
}

unordered_set<unordered_set<int>*>* bottom(vector<int>* edges,vector<int>* edgesT,int n){
    unordered_set<unordered_set<int>*>* res = new unordered_set<unordered_set<int>*>;
    stack<int> finstack;
    bool* vis = new bool[n]();
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(edges,n,i,vis,finstack);
        }
    }
    
    unordered_set<unordered_set<int>*>* parts = new unordered_set<unordered_set<int>*>;
    for(int i=0;i<n;i++) vis[i] = false;
    int* compmap = new int[n];
    int compcount = 0;
    while(!finstack.empty()){
        int top = finstack.top();
        if(!vis[top]){
            unordered_set<int>* part = new unordered_set<int>;
            dfsc(edgesT,n,top,vis,part,compmap,compcount);
            parts->insert(part);
            compcount++;
        }
        finstack.pop();
    }
  
    
    for(auto i : *parts){
        bool flag = true;
        for(auto j: *i){
            for(int k=0;k<edges[j].size();k++){
                if(compmap[edges[j][k]] != compmap[j]) flag = false;
            }
        }
        
        if(flag) res->insert(i);
    }
    
    return res;
}

int main()
{
    int n=1,e=1;
    while(1){
        cin>>n;
        if(n == 0) break;
        cin>>e;
        vector<int>* edges = new vector<int>[n]();
        vector<int>* edgesT = new vector<int>[n]();
        while(e--){
            int a,b;
            cin>>a>>b;
            edges[--a].push_back(--b);
            edgesT[b].push_back(a);
        }
        
        unordered_set<unordered_set<int>*>* res = bottom(edges,edgesT,n);
        set<int>ans;
        
        for(auto i : *res){
            for(auto j : *i){
                ans.insert(j+1);
            }
        }
        
        for(auto i : ans) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
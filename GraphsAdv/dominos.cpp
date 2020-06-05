#include<bits/stdc++.h>
using namespace std;

void dfs(vector<int>* adjlis,int n,int a,bool* vis,stack<int> &finstack){
    vis[a] = true;
    for(int i=0;i<adjlis[a].size();i++){
        int ele = adjlis[a][i];
        if(!vis[ele])
            dfs(adjlis,n,ele,vis,finstack);
    }
    finstack.push(a);
}

void dfsc(vector<int>* adjlisT,int n,int a,bool* vis,unordered_set<int>* component,int* compmap,int compcount){
    vis[a] = true;
    component->insert(a);
    compmap[a] = compcount;
    for(int i=0;i<adjlisT[a].size();i++){
        int ele = adjlisT[a][i];
        if(!vis[ele])
            dfsc(adjlisT,n,ele,vis,component,compmap,compcount);
    }
}

int sscomp(vector<int>* adjlis,vector<int>* adjlisT,int n){
    bool* vis = new bool[n]();
    unordered_set<unordered_set<int>*>* res = new unordered_set<unordered_set<int>*>;
    stack<int> finstack;
    int* compmap = new int[n]();
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(adjlis,n,i,vis,finstack);
        }
    }
    
    int compcount = 0;
    for(int i=0;i<n;i++) vis[i] = false;
    while(!finstack.empty()){
        int top = finstack.top();
        unordered_set<int>* component = new unordered_set<int>;
        if(!vis[top]){
            dfsc(adjlisT,n,top,vis,component,compmap,compcount);
            res->insert(component);
            compcount++;
        }
        finstack.pop();
    }

    int count = 0;
    for(auto i : *res){
        int cou = 0;
        for(auto j : *i){
            for(int k=0;k<adjlisT[j].size();k++){
                if(compmap[j] != compmap[adjlisT[j][k]]) cou = 1;
            }
        }
        count += cou;
    }
    return compcount-count;
}

int main()
{
    int t; cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>* adjlis = new vector<int>[n];
        vector<int>* adjlisT = new vector<int>[n];
        while(m--){
            int a,b;
            cin>>a>>b;
            adjlis[--a].push_back(--b);
            adjlisT[b].push_back(a);
        }
        
        int res = sscomp(adjlis,adjlisT,n);
        cout<<res<<endl;
    }
    return 0;
}

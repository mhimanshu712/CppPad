#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_set<int>* comp,vector<vector<int>> adjlis,int n,bool* vis,int a){
    vis[a] = true;
    comp->insert(a);  
    for(int i=0;i<adjlis[a].size();i++)
        if(!vis[adjlis[a][i]])
            dfs(comp,adjlis,n,vis,adjlis[a][i]);
}

vector<unordered_set<int>*> getComponents(vector<vector<int>> adjlis,int n){
    vector<unordered_set<int>*> res;
    bool* vis = new bool[n]();
    for(int i=0;i<n;i++){
        if(!vis[i]){
            unordered_set<int>* comp = new unordered_set<int>();
            dfs(comp,adjlis,n,vis,i);
            res.push_back(comp);
        }
        
    }
    return res;
}

int main()
{
    int t; cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        char * p = new char[n]();
        char * q = new char[n]();
        vector<vector<int>> adjlis(n);

        for(int i=0;i<n;i++) cin>>p[i];
        for(int i=0;i<n;i++) cin>>q[i];
        while(m--){
            int a,b;
            cin>>a>>b;
            adjlis[--a].push_back(--b);
            adjlis[b].push_back(a);
        }

        vector<unordered_set<int>*> compsmap;
        compsmap = getComponents(adjlis,n);

      

        vector<unordered_set<int>> comps;
        for(auto i : compsmap){
            unordered_set<int> temp;
            for(auto j : *i){
                temp.insert(p[j]);
            }
            comps.push_back(temp);
        }

       

        string out = "YES";
        for(int i=0;i<compsmap.size();i++){
            for(auto j : *compsmap[i]){
                if(comps[i].find(q[j]) == comps[i].end()){
                    out = "NO";
                }
            }
        }

        cout<<out<<endl;
    }
    return 0;
}


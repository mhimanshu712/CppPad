#include<bits/stdc++.h>
using namespace std;

void dfs(unordered_set<int>* comp,int** arr,int n,bool* vis,int a){
    vis[a] = true;
    comp->insert(a);  
    for(int i=0;i<n;i++)
        if(arr[a][i] == 1 && !vis[i])
            dfs(comp,arr,n,vis,i);
}

vector<unordered_set<int>*> getComponents(int** arr,int n){
    vector<unordered_set<int>*> res;
    bool* vis = new bool[n]();
    for(int i=0;i<n;i++){
        if(!vis[i]){
            unordered_set<int>* comp = new unordered_set<int>();
            dfs(comp,arr,n,vis,i);
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
        int** arr = new int*[n];
        for(int i=0;i<n;i++) arr[i] = new int[n];
        for(int i=0;i<n;i++) cin>>p[i];
        for(int i=0;i<n;i++) cin>>q[i];
        while(m--){
            int a,b;
            cin>>a>>b;
            arr[--a][--b] = 1;
            arr[--b][--a] = 1;
        }

        vector<unordered_set<int>*> compsmap;
        compsmap = getComponents(arr,n);

        // for(auto i : compsmap){
        //     for(auto j : *i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }

        vector<unordered_set<int>> comps;
        for(auto i : compsmap){
            unordered_set<int> temp;
            for(auto j : *i){
                temp.insert(p[j]);
            }
            comps.push_back(temp);
        }

        // for(auto i : comps){
        //     for(auto j : i){
        //         cout<<j-'0'<<" "; 
        //     }
        //     cout<<endl;
        // }

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

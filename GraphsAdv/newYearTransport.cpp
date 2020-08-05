#include<bits/stdc++.h>
using namespace std;

bool dfs(vector<vector<int>> mat,bool* vis,int s,int f){
    if(s == f) return true;
    
    vis[s] = true;
    for(int i=0;i<mat[s].size();i++){
    	int ele = mat[s][i];
        if(!vis[ele]){
            bool res = dfs(mat,vis,ele,f);
            if(res == true) return true;
        }
    }
    
    return false;
}

int main()
{
	int n,t;
    cin>>n>>t;
    vector<vector<int>> mat(n+1);
    for(int i=1;i<=n-1;i++){
        int a; cin>>a;
        mat[i].push_back(i+a);
    }
    bool* vis = new bool[n+1]();
    bool res = dfs(mat,vis,1,t);
    
    if(res) cout<<"YES";
    else cout<<"NO";
	return 0;
}

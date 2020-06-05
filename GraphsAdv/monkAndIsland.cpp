#include<bits/stdc++.h>
using namespace std;

int bfs(vector<int>* edges,int n){
    deque<int> dq;
    bool* vis = new bool[n]();
    int* level = new int[n]();
    dq.push_back(0);
    vis[0] = true;
    
    while(!dq.empty()){
        int top = dq.front();
        dq.pop_front();
        for(int i=0;i<edges[top].size();i++){
            int ele = edges[top][i];
            if(!vis[ele]){
                level[ele] = level[top]+1;
                dq.push_back(ele);
                vis[ele] = true;
                if(ele == n-1) return level[ele];
            }
        }
    }
    return 59;
}

int main()
{
    int t; cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int** arr = new int*[n];
        // Uncommenting this will cause Runtime error
        // Cause you are allocating 10^4*10^4 * 4 bytes
        // Max should be 10^7
        //for(int i=0;i<n;i++) arr[i] = new int[n]();
        vector<int>* edges = new vector<int>[n];
        
        while(m--){
            int x,y;
            cin>>x>>y;
            edges[--x].push_back(--y);
            edges[y].push_back(x);
        }
        
        int res = bfs(edges,n);
        cout<<res<<endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

bool hasPath(int** arr,bool* vis,int n,int a,int b){
    deque <int> dq;
    dq.push_back(a);
    vis[a] = true;
    
    while(!dq.empty()){
        int curr = dq.front();
        if(curr == b) return true;
        dq.pop_front();
        for(int i=0;i<n;i++)
            if(arr[curr][i] == 1 && !vis[i]){
                dq.push_back(i);
                vis[i] = true;
            }
    }
    
    return false;
}

int main() {
    int V, E;
    cin >> V >> E;
    
    int** arr = new int*[V];
    for(int i=0;i<V;i++) arr[i] = new int[V]();
    bool * vis = new bool[V]();
    
    while(E--){
        int a,b;
        cin>>a>>b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    
    int a,b;
    cin>>a>>b;
    
    bool res = hasPath(arr,vis,V,a,b);
    if(res) cout<<"true";
    else cout<<"false";
    
    return 0;
}

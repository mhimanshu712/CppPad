#include <iostream>
using namespace std;

void dfs(int** arr,bool* vis,int n,int s){
    vis[s] = true;
    for(int i=0;i<n;i++)
        if(arr[s][i] == 1 && !vis[i])
            dfs(arr,vis,n,i);
}

bool checkConnection(int** arr,int n){
    bool* vis = new bool[n]();
    dfs(arr,vis,n,0);
    for(int i=0;i<n;i++){
        if(!vis[i]) return false;
    }
    return true;
}

int main() {
    int V, E;
    cin >> V >> E;
    int** arr = new int*[V];
    for(int i=0;i<V;i++) arr[i] = new int[V]();
    while(E--){
        int a,b;
        cin>>a>>b;
        arr[a][b] = 1;
        arr[b][a] = 1;
    }

    int a,b;
    cin>>a>>b;
    
    bool res = checkConnection(arr,V);
    if(res) cout<<"true";
    else cout<<"false";
    
    return 0;
}
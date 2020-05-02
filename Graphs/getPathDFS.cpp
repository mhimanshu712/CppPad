#include <iostream>
using namespace std;


bool pathDFS(int** arr,bool* vis,int n,int a,int b){
    if(a == b){
        cout<<b<<" ";
        return true;
    }
    vis[a] = true;
    for(int i=0;i<n;i++){
        if(arr[a][i] == 1 && !vis[i]){
            bool res = pathDFS(arr,vis,n,i,b);
            if(res){
                cout<<a<<" ";
                return true;
            }
        }
    }
    return false;
}

int main()
{
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
    
    pathDFS(arr,vis,V,a,b);
    
    return 0;
}
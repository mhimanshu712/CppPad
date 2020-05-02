#include <bits/stdc++.h>
using namespace std;

void pathBFS(int** arr,bool* vis,int n,int a,int b){
    int* parent = new int[n];
    for(int i=0;i<n;i++) parent[i] = -1;
    deque <int> dq;
    
    dq.push_back(a);
    vis[a] = true;
    while(!dq.empty()){
        int curr = dq.front();
        if(curr == b) break;
        dq.pop_front();
        for(int i=0;i<n;i++){
            if(arr[curr][i] == 1 && !vis[i]){
                dq.push_back(i);
                vis[i] = true;
                parent[i] = curr;
            }
        }
    }
    
    int t = b;
    // t == a :: because parent[a]= -1 but still should be printed
    while(t != -1 || t == a){
        cout<<t<<" ";
        if(t == a) break;
        t = parent[t];
    }
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
    
    pathBFS(arr,vis,V,a,b);

  return 0;
}

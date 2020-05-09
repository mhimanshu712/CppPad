#include <bits/stdc++.h>
using namespace std;

void dfsc(int** arr,bool* vis,int n,int s,vector<int> &vec){
    vis[s] = true;
    vec.push_back(s);
    for(int i=0;i<n;i++)
        if(arr[s][i] == 1 && !vis[i])
            dfsc(arr,vis,n,i,vec);
}

void listCompo(int** arr,int n){
    bool* vis = new bool[n]();
    vector <int> vec;
    
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfsc(arr,vis,n,i,vec);
            sort(vec.begin(),vec.end());
            for(auto j : vec) cout<<j<<" ";
            cout<<endl;
            vec.resize(0);
        }
    }
}

int main()
{
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
    
    listCompo(arr,V);

  return 0;
}

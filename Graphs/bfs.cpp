//Notes: Set visited just after adding the node to the stack

#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, E;
    cin >> V >> E;
    deque<int> dq;
    bool * vis = new bool[V]();
    vector <vector<int>> mat(V,vector<int>(V,0));
    for(int i=0;i<E;i++){
        int a,b;
        cin>>a>>b;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }
    
    for(int k=0;k<V;k++){
        if(!vis[k]){
            dq.push_back(k);
            vis[k] = 1;
            while(!dq.empty()){
                int t = dq.front();
                dq.pop_front();
                cout<<t<<" ";
                for(int i=0;i<V;i++){
                    if(mat[t][i] == 1 && !vis[i]){
                        dq.push_back(i);
                        vis[i] = 1;
                    }
                }
            }
        }
    }
    
  return 0;
}
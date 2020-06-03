#include<bits/stdc++.h>
using namespace std;

const int mod = pow(10,9)+7;

long long factorial(int n){
    long long total = 1;
    for(int i=1;i<=n;i++){
        // How this works?
        // Well we are solving this  (1+4+6+9)%m
        // ((1+4+6)%m + 9%m)%m
        // ((1+4+6)%m + 9)%m
        total = (total*i)%mod;
    }
    return total;
}

void dfs(int** arr,int n,int m,int* component,bool** vis,int a,int b){
    if(a>=n || b>=m || a<0 || b<0) return;

    if(!vis[a][b] && arr[a][b]==1){
        vis[a][b] = true;
        *component += 1;

        dfs(arr,n,m,component,vis,a+2,b+1);
        dfs(arr,n,m,component,vis,a+2,b-1);
        dfs(arr,n,m,component,vis,a-2,b+1);
        dfs(arr,n,m,component,vis,a-2,b-1);
        dfs(arr,n,m,component,vis,a+1,b+2);
        dfs(arr,n,m,component,vis,a+1,b-2);
        dfs(arr,n,m,component,vis,a-1,b+2);
        dfs(arr,n,m,component,vis,a-1,b-2);
    }
    
}

vector<int> getComponent(int** arr,int n,int m){
    vector<int> components;
    bool** vis = new bool*[n];
    for(int i=0;i<n;i++) vis[i] = new bool[m]();

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j] == 1 && !vis[i][j]){
                int* component = new int;
                *component = 0;
                dfs(arr,n,m,component,vis,i,j);
                if(*component>0) components.push_back(*component);
            }
        }
    }
    return components;
}

int main()
{
    int t; cin>>t;
    while(t--){
        int n,m,q;
        cin>>n>>m>>q;
        int** arr = new int*[n];
        for(int i=0;i<n;i++) arr[i] = new int[m]();
        
        while(q--){
            int a,b;
            cin>>a>>b;
            arr[--a][--b] = 1;
        }


        vector<int> res = getComponent(arr,n,m);

        long long total=1;
        for(auto i : res){
            total = (total*factorial(i))%mod;
        }
        cout<<total<<endl;
    }
    return 0;
}

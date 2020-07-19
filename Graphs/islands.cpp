void dfs(int** arr,bool* vis,int n,int s){
    vis[s] = true;
    for(int i=0;i<n;i++)
        if(arr[s][i]==1 && !vis[i])
            dfs(arr,vis,n,i);
}

int solve(int n,int m,vector<int>u,vector<int>v)
{
    int** arr = new int*[n];
    for(int i=0;i<n;i++) arr[i] = new int[n]();
    
    for(int i=0;i<m;i++){					
        arr[u.at(i)-1][v.at(i)-1] = 1;		
        arr[v.at(i)-1][u.at(i)-1] = 1;		
    }
    bool* vis = new bool[n]();
    
    int count=0;
    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(arr,vis,n,i);
            count++;
        }
    }
    
    return count;
}
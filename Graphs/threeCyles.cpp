int solve(int n,int m,vector<int>u,vector<int>v)
{
	int** arr = new int*[n];
    for(int i=0;i<n;i++) arr[i] = new int[n]();
    
    for(int i=0;i<m;i++){
        arr[u[i]-1][v[i]-1] = 1;
        arr[v[i]-1][u[i]-1] = 1;
    }
    
    int count = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(i == j) continue;
            if(arr[i][j] == 1){
                for(int k=0;k<n;k++){
                    if(k==j || k==i) continue;
                    if(arr[j][k] == 1){
                        if(arr[k][i] == 1) count++;
                    }
                }
            }
        }
    
    return count/6;
}
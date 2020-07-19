
bool getString(char graph[][MAXN],bool** vis,int n,int m,int a,int b,char * str,int len){
    // Bound check
    if(a<0 || a>=n || b<0 || b>=m) return false;
    // Base Case
    if(len == 1 && str[0] == graph[a][b] && !vis[a][b]) return true;
    if(str[0] == graph[a][b] && !vis[a][b]){
        // Check all directions
        vis[a][b] = true;
        bool p1 = getString(graph,vis,n,m,a+1,b,str+1,len-1);
        bool p2 = getString(graph,vis,n,m,a,b+1,str+1,len-1);
        bool p3 = getString(graph,vis,n,m,a+1,b+1,str+1,len-1);
        bool p4 = getString(graph,vis,n,m,a-1,b,str+1,len-1);
        bool p5 = getString(graph,vis,n,m,a,b-1,str+1,len-1);
        bool p6 = getString(graph,vis,n,m,a-1,b-1,str+1,len-1);
        bool p7 = getString(graph,vis,n,m,a+1,b-1,str+1,len-1);
        bool p8 = getString(graph,vis,n,m,a-1,b+1,str+1,len-1);
        
        vis[a][b] = false;
        
        if(p1 || p2 || p3 || p4 || p5 || p6 || p7 || p8) return true;
    }
    
    return false;
}

int solve(char graph[][MAXN],int n, int m)
{
	char str[] = "CODINGNINJA";
    int len = strlen(str);
    bool** vis = new bool*[n];
    for(int i=0;i<n;i++) vis[i] = new bool[m]();
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(graph[i][j] == str[0]){
            	bool res = getString(graph,vis,n,m,i,j,str,len);
            	if(res) return 1;
            }
        }
    }
    
    return 0;
}
int getSlice(char cake[][NMAX],int n,int a,int b){
    //Bound check
    if(a<0 || a>=n || b<0 || b>=n) return 0;
    
    if(cake[a][b] == '1'){
        cake[a][b] = '0';
        int p1 = getSlice(cake,n,a+1,b);
        int p2 = getSlice(cake,n,a,b+1);
        int p3 = getSlice(cake,n,a-1,b);
        int p4 = getSlice(cake,n,a,b-1);
        
        return 1+p1+p2+p3+p4;
    }
    return 0;
}

int solve(int n,char cake[NMAX][NMAX])
{
	int maxi = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cake[i][j] == '1'){
                int curr = getSlice(cake,n,i,j);
                maxi = max(curr,maxi);
            }
        }
    }
    return maxi;
}
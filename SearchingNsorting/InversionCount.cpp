typedef long long ll;

ll merge(int arr[],int a[],int b[],int n,int m,ll x,ll y){
    int i =0,j = 0,k=0;
    ll count = 0;
    
    while(i<n && j<m){
        if(a[i]<=b[j])
            arr[k++] = a[i++];
        else{
            count += (n-i);
            arr[k++] = b[j++];
        }
    }
    
    while(i<n) arr[k++] = a[i++];
    while(j<m) arr[k++] = b[j++];
    
    return(x+y+count);
}

ll sort(int arr[],int n){
    if(n <= 1) return 0;
    
    int m = n/2;
    int * a = new int[m];
    int * b = new int[n-m];
    for(int i=0;i<m;i++) a[i] = arr[i];
    for(int i=0,j=m;i<n-m;i++,j++) b[i] = arr[j];
    
    ll x = sort(a,m);
    ll y = sort(b,n-m);
    
    ll f = merge(arr,a,b,m,n-m,x,y);
    
    return f;
}


long long solve(int arr[], int n)
{
    long long res = sort(arr,n);
    return res;
}
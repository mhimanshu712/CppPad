#include<bits/stdc++.h>
using namespace std;

bool cows(int * arr,int n,int c,int k){
    int i =0, j =1;
    
    c--;
    while(j<n && c){
        if(arr[j]-arr[i] >= k){
            i = j++;
            c--;
        }else{
            j++;
        }
    }
    
    if(c <= 0) return true;
    return false;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,c;
        cin>>n>>c;
        
        int * arr = new int[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        
        sort(arr,arr+n);
        
        int a = 0,b = arr[n-1]-arr[0],m,maxi=0;
        
        while(a<=b){
            m = (a+b)/2;
            
            if(cows(arr,n,c,m)){
                maxi = max(m,maxi);
                a = m+1;
            }else{
                b = m-1;
            }
        }
        
        cout<<maxi<<endl;
    }
    
    return 0;
}
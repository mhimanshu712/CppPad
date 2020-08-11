#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    int * arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    int cost = 0, groups = 0;
    for(int i=0;i<n-1;i++)
        if(arr[i]==0 && arr[i]==1) groups++;
    
    while(groups--){
        int a=0,b=0,c=n-1;
        int i=0
        for(;i<n-1;i++){
            if(arr[i]==0 && arr[i+1]==1) b = i;
        }
        
        for(;i<n-1;i++){
            if(arr[i]==0 && arr[i+1] == 1) c=i;
        }
    }
    
    
	return 0;
}

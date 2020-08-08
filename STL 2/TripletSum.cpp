#include <bits/stdc++.h>

int mid(int a,int b,int c){
    int x = a - b; 
    int y = b - c;  
    int z = a - c;  
  
    if (x * y > 0) 
        return b; 
  
    else if (x * z > 0) 
        return c; 
    else
        return a; 
}

void FindTriplet(int arr[], int n, int x) {   
    
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            for(int k=j+1;k<n;k++)
                    if(arr[i] + arr[j] + arr[k] == x){
                        int mini = min(min(arr[i],arr[j]),arr[k]);
                        int maxi = max(max(arr[i],arr[j]),arr[k]);
                    
                        int midi = mid(arr[i],arr[j],arr[k]);
                    
                        cout<<mini<<" "<<midi<<" "<<maxi<<endl;
                    }
}

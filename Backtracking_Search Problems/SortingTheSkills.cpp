#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    for(int k=0;k<t;k++){
        int n;
        cin>>n;
        int * arr = new int[n];
        
        for(int j=0;j<n;j++) cin>>arr[j];
        
        for(int i=0;i<n;i++){
            bool sorted = true,swapped = false;
            for(int j=0;j<n-1;j++){
                if(arr[j]>arr[j+1]){
                    sorted = false;
                    if(arr[j] == arr[j+1]+1){
                        swapped = true;
                        int t = arr[j+1];
                        arr[j+1] = arr[j];
                        arr[j] = t;
                    }
                }
            }
            if(sorted){
                cout<<"Yes"<<endl;
                break;
            }
            
            if(!sorted && !swapped){
                cout<<"No"<<endl;
                break;
            }
        }
      
        
        
    }
    
	return 0;
}

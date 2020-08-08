#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    
    int * arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int q;
    cin>>q;
    int * x = new int[q];
    for(int i=0;i<q;i++) cin>>x[i];
    
    for(int i=0;i<q;i++){
        int m = x[i];
        int momo=0,j=0;
        
        while(arr[j]<=m){
            momo++;
            m -= arr[j++];
        }
        cout<<momo<<" "<<m<<endl;
    }
    
	return 0;
}

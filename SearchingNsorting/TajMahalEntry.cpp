#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    
    int * arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    for(int i=0;1;i++){
        if(arr[i%n] - i <= 0){
            cout<<(i%n)+1;
            break;
        }
    }
    
	return 0;
}

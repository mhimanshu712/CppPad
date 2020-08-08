#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        long long x,sum=0;
        cin>>x;
        
        while(x>0){
            sum = sum + (x%10);
            x /= 10;
        }
        cout<<sum<<endl;
    }
}
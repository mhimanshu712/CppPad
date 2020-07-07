#include<bits/stdc++.h>
using namespace std;

const int MAX = pow(10,6);

int* getSeive(){
    int* seive = new int[MAX]();
    for(int i=2;i<MAX;i++){
        if(seive[i] == 0){
            for(int j=i;j<MAX;j+=i) seive[j] += 1;
        }
    }
    return seive;
}

int main(){
	int t; cin>>t;
    int* seive = getSeive();
    int** arr = new int*[11];
    for(int i=0;i<=10;i++) arr[i] = new int[MAX]();
    
    for(int i=0;i<=10;i++){
        if(seive[0] == i) arr[i][0] += 1;
        for(int j=1;j<MAX;j++){
            if(seive[j] == i) arr[i][j] += 1;
            arr[i][j] += arr[i][j-1];
        }
    }
    while(t--){
        int a,b,n;
        cin>>a>>b>>n;
        // Try running without subrtacting 1 from a
        cout<<(arr[n][b] - arr[n][a-1])<<endl;
    }
	return 0;
}
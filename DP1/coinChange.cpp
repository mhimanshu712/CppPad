#include <bits/stdc++.h>

using namespace std;

int solve(int den[],int n,int val,int ** arr){
    if(n == 0 || val<0 ) return 0;
    if(val == 0) return 1;
    if(arr[n][val] > -1) {return arr[n][val];}
    
    int p1 = solve(den,n,val-den[0],arr);
    int p2 = solve(den+1,n-1,val,arr);
    arr[n][val] = p1+p2;
    
    return p1+p2;
}

int countWaysToMakeChange(int den[], int numDen, int val){
    int ** arr = new int*[numDen+1];
    for(int i=0;i<=numDen+1;i++) arr[i] = new int[val+1];
    for(int i=0;i<numDen+1;i++)for(int j=0;j<val+1;j++) arr[i][j] = -1;
    int res = solve(den,numDen,val,arr);
    return res;
}

int main(){
    int n;
    cin>>n;
    int * arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int val;
    cin>>val;
    int res = countWaysToMakeChange(arr,n,val);
    cout<<res;
}
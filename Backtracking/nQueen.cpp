#include <bits/stdc++.h>

bool checker(int ** arr,int n,int r,int c){
    for(int i=r,j=c;i>=0;i--) if(arr[i][j] == 1) return false;
    for(int i=r,j=c;i>=0 && j<n;i--,j++) if(arr[i][j] == 1) return false;
    for(int i=r,j=c;i>=0 && j>=0;i--,j--) if(arr[i][j] == 1) return false;
    return true;
}

void nqueen(int ** arr,int n,int r){
    if(r == n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<arr[i][j]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    
	for(int j=0;j<n;j++){
        if(checker(arr,n,r,j)){
            arr[r][j] = 1;
            nqueen(arr,n,r+1);
        }
        arr[r][j] = 0;
    }
}


void placeNQueens(int n){
    int ** arr = new int*[n];
    for(int i=0;i<n;i++) arr[i] = new int[n]();
 	nqueen(arr,n,0);
}

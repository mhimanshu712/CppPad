#include <bits/stdc++.h>

bool checker(int maze[][20],int n,int ** arr,int a,int b){
    //Bound Check first
    if(a>=n || b>=n || a<0 || b<0) return false;
    if(maze[a][b] == 0 || arr[a][b] == 1) return false;
    return true;
}

void domaze(int maze[][20],int n,int ** arr,int a,int b){
    if(a == n-1 && b == n-1){
        arr[n-1][n-1] = 1;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cout<<arr[i][j]<<" ";
        cout<<endl;
        arr[n-1][n-1] = 0;
        return;
    }
    
    arr[a][b] = 1;
    if(checker(maze,n,arr,a+1,b)) domaze(maze,n,arr,a+1,b);
    if(checker(maze,n,arr,a-1,b)) domaze(maze,n,arr,a-1,b);
    if(checker(maze,n,arr,a,b+1)) domaze(maze,n,arr,a,b+1);
    if(checker(maze,n,arr,a,b-1)) domaze(maze,n,arr,a,b-1);
    arr[a][b] = 0;
    return ;
}

void ratInAMaze(int maze[][20], int n){
    int * * arr = new int*[n];
    for(int i=0;i<n;i++) arr[i] = new int[n]();
    
    domaze(maze,n,arr,0,0);
}

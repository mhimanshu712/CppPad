#include <bits/stdc++.h>
using namespace std;

const int N = 9;

bool checker(int arr[N][N],int row,int col,int val){
    for(int i=0;i<N;i++)
        if(arr[i][col] == val) return false;
    
    for(int j=0;j<N;j++)
        if(arr[row][j] == val) return false;
    
    int grow = (row/3)*3, gcol = (col/3)*3;
    for(int i=grow;i<grow+3;i++){
        for(int j=gcol;j<gcol+3;j++){
            if(arr[i][j] == val) return false;
        }
    }
    
    return true;
}

bool findEmpty(int arr[N][N],int &row,int &col){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++)
            if(arr[i][j] == 0){
                row = i; col = j;
                return true;
            }
    }
    return false;
}

bool sudokuSolver(int arr[N][N]){
    int row,col;
    if(!findEmpty(arr,row,col)) return true;
    
    for(int i=1;i<=N;i++){
        if(checker(arr,row,col,i)){
            arr[row][col] = i;
            bool res = sudokuSolver(arr);
            if(res) return true;
        }
        arr[row][col] = 0;
    }
    
    return false;
}


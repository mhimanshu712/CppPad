#include <bits/stdc++.h>
using namespace std;

int findMaxSquareWithAllZeros(int** arr, int row, int col){
    int ** dp = new int*[row];
    for(int i=0;i<row;i++) dp[i] = new int[col]();
    
    for(int i=0;i<row;i++) dp[i][0] = (arr[i][0]==1)?0:1;
    for(int j=0;j<col;j++) dp[0][j] = (arr[0][j]==1)?0:1;
    
    int maxi = 0;
    for(int i=1;i<row;i++)
        for(int j=1;j<col;j++){
            if(arr[i][j] == 1) dp[i][j] == 0;
            else{
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1])) + 1;
                maxi = max(maxi,dp[i][j]);
            }
        }
    return maxi;
}
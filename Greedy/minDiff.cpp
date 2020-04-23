#include <bits/stdc++.h>

using namespace std;

int minAbsoluteDiff(int arr[], int n) {
    sort(arr,arr+n);
    int mini = INT_MAX;
    
    for(int i=1;i<n;i++)
        if(arr[i]-arr[i-1] < mini) mini = arr[i] - arr[i-1];
    return mini;

}
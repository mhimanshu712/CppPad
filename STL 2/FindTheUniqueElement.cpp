#include <bits/stdc++.h>

using namespace std;

int FindUnique(int arr[], int size){
    unordered_map <int,int> m;
    for(int i=0;i<size;i++)
        m[arr[i]]++;
    for(int i=0;i<size;i++){
        if(m[arr[i]]==1) 
        return arr[i];
    }
    
}
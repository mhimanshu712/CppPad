#include <bits/stdc++.h> 
using namespace std; 

// arr - input array // size - size of array 
int MissingNumber(int arr[], int size)
{
    map<int,int>mp; 
    int i; 
    
    for (int i=0; i<size; i++)
    {
        mp[arr[i]]++;
    }
    
    
    for(auto i = mp.begin(); i != mp.end(); i++)
    {
        if (i->second==2)
            return i->first;
    }
}
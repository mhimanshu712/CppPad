#include <bits/stdc++.h>
using namespace std;

struct node{
    char token;
    int x;
    int index;
};

bool comp(node a,node b){
    return a.x < b.x;
}

void insert(int v,int n,int* bit){
    for(;v<n;v += (v&(-v))) bit[v]++;
}

long query(int v,int* bit){
    int total = 0;
    for(;v>=0; v -= (v&(-v))) total += bit[v];
    return total;
}

int main()
{
    int n; cin>>n;
    node* arr = new node[n];
    for(int i=0;i<n;i++){
        cin>>arr[i].token>>arr[i].x;
        arr[i].index = i;
    }
    sort(arr,arr+n,comp);
    unordered_map<int,int> um;
    for(int i=0;i<n;i++){
        um[arr[i].x] = i+1;
    }
    int maxi = um[arr[n-1].x]+1;
    int* bit = new int[maxi]();
    int* ans = new int[n];
    
    for(int i=0;i<n;i++){
        char op = arr[i].token;
        
        if(op == 'I'){
            int index = um[arr[i].x];
            // Suppose the query is made for index 1 and 0
            if(query(index,bit) == query(index-1,bit)){
                insert(index,maxi,bit);
            }
        }
        
        if(op == 'D'){
            
        }
        
        if(op == 'K'){
            
        }
        
        if(op == 'C'){
            
        }
    }
    
    return 0;
}


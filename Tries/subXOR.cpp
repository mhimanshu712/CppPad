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

void insert(int v,int n,int val,int* bit){
    for(;v<=n;v += (v&(-v))){
        bit[v] += val;
    }
}

long query(int v,int* bit){
    long total = 0;
    for(int i=v;i > 0;i -= (i&(-i))){
        total += bit[i];
    }
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
    
    // Copying so that original order of operations dosen't change
    node* brr = new node[n];
    copy(arr,arr+n,brr);
    sort(brr,brr+n,comp);
    unordered_map<int,int> um;
    for(int i=0;i<n;i++){
        um[brr[i].x] = i+1;
    }
    
    int* bit = new int[n+1]();
    
    for(int i=0;i<n;i++){
        char op = arr[i].token;
        int index = um[arr[i].x];
        
        if(op == 'I'){
            // Suppose the query is made for index 1 and 0
            if(query(index,bit) == query(index-1,bit)){
                insert(index,n,1,bit);
            }
        }
        
        if(op == 'D'){
            if(query(index,bit) != query(index-1,bit)){
                insert(index,n,-1,bit);
            }
        }
        
        if(op == 'K'){
            int a = 1,b = n;
            int mid = (a+b)/2;
            long val = arr[i].x;
            
            while(query(mid,bit) != val && (a<=b)){
                long res = query(mid,bit);
                if(res > val) b = mid-1;
                else if(res < val) a = mid+1;
                mid = (a+b)/2;
            }
            cout<<mid<<endl;
        }
        
        if(op == 'C'){
            
        }
    }
    
    return 0;
}
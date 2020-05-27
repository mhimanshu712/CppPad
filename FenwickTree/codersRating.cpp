#include <bits/stdc++.h>
using namespace std;

#define MMAX 100000

struct node {
    int x, y;
    int index;
};

bool comp(node a,node b){
    if(a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

void update(int val,int* fen){
    for(;val<=MMAX;val += (val&(-val))){
        fen[val]++;
    }
}

int query(int a,int* fen){
    int count = 0;
    for(;a>0;a -= (a&(-a))){
        count += fen[a];
    }
    return count;
}


int main()
{
    int n; cin>>n;
    node* arr = new node[n]();
    int* fen = new int[MMAX+1]();
    int* ans = new int[n]();
    for(int i=0;i<n;i++){
        cin>>arr[i].x;
        cin>>arr[i].y;
        arr[i].index = i;
    }
    sort(arr,arr+n,comp);
    
    for(int i=0;i<n;){
        int end = i;
        while(end<n && arr[i].x == arr[end].x && arr[i].y == arr[end].y) end++;
        
        for(int j=i;j<end;j++) ans[arr[j].index] = query(arr[j].y,fen);
        for(int j=i;j<end;j++) update(arr[j].y,fen);
        
        i = end;
    }
    
    for(int i=0;i<n;i++) cout<<ans[i]<<endl;
    
    return 0;
}

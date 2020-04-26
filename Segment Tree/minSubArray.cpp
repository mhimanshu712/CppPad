#include<bits/stdc++.h>
using namespace std;

void buildTree(int * arr,int * tree,int start,int end,int index=1){
    if(start == end){
        tree[index] = arr[start];
        return;
    }
    int mid = (start+end)/2;
    buildTree(arr,tree,start,mid,2*index);
    buildTree(arr,tree,mid+1,end,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
}

void updateTree(int* arr,int* tree,int start,int end,int pos,int val,int index=1){
    if(start == end){
        tree[index] = val;
        return;
    }
    
    int mid = (start+end)/2;
    if(pos <= mid) updateTree(arr,tree,start,mid,pos,val,2*index);
    if(pos > mid) updateTree(arr,tree,mid+1,end,pos,val,2*index+1);
    tree[index] = min(tree[2*index],tree[2*index+1]);
}

int queryTree(int*  tree,int start,int end,int left,int right,int index=1){
    if(left>end || right<start) return INT_MAX;
    
    if(left<=start && right>=end) return tree[index];
    
    int mid = (start+end)/2;
    int ans1 = queryTree(tree,start,mid,left,right,2*index);
    int ans2 = queryTree(tree,mid+1,end,left,right,2*index+1);
    
    return min(ans1,ans2);
}

int main() {
        int n,q;
        cin>>n>>q;
        int * arr = new int[n];
        int * tree = new int[4*n]();
        for(int i=0;i<n;i++) cin>>arr[i];
        buildTree(arr,tree,0,n);
        
        while(q--){
            char a; int b,c;
            cin>>a>>b>>c;
            switch(a){
                case 'q':
                    {
                        int res = queryTree(tree,0,n,b,c);
                        cout<<res<<endl;
                        break;
                    }
                
                case 'u':
                    updateTree(arr,tree,0,n,b,c);
                    break;
                    
            }
        }
    
}
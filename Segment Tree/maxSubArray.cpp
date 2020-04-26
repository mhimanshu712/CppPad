#include<bits/stdc++.h>
using namespace std;

struct node{
    int sum;
    int msum;
    int bps;
    int bss;
};

void buildTree(int * arr,node * tree,int start,int end,int index=1){
    if(start == end){
        tree[index].sum = arr[start];
        tree[index].msum = arr[start];
        tree[index].bps = arr[start];
        tree[index].bss = arr[start];
        return;
    }
    int mid = (start+end)/2;
    int i = 2*index; int j=i+1;
    
    buildTree(arr,tree,start,mid,2*index);
    buildTree(arr,tree,mid+1,end,2*index+1);
    
    tree[index].sum = tree[i].sum + tree[j].sum;
    tree[index].bps = max(tree[i].bps,tree[i].sum + tree[j].bps);
    tree[index].bss = max(tree[i].bss + tree[j].sum, tree[j].bss);
    
    int t[5] = {tree[i].msum,
                tree[j].msum,
                tree[i].bss+tree[j].sum,
                tree[i].sum + tree[j].bps,
                tree[i].bss + tree[j].bps
               };
    tree[index].msum = *max_element(t,t+5);    
}


node queryTree(node*  tree,int start,int end,int left,int right,int index=1){
    if(left>end || right<start){
        int mini = -1000000;
        node temp = {mini,mini,mini,mini};
        return temp;
    }
    
    if(left<=start && right>=end) return tree[index];
    
    int mid = (start+end)/2;
    node ans1 = queryTree(tree,start,mid,left,right,2*index);
    node ans2 = queryTree(tree,mid+1,end,left,right,2*index+1);
    
    node temp;
    temp.sum = ans1.sum + ans2.sum;
    temp.bps = max(ans1.bps,ans1.sum + ans2.bps);
    temp.bss = max(ans1.bss + ans2.sum, ans2.bss);
    
    int t[5] = {ans1.msum,
                ans2.msum,
                ans1.bss+ans2.sum,
                ans1.sum + ans2.bps,
            	ans1.bss + ans2.bps
               };
    temp.msum = *max_element(t,t+5);
    return temp;
}

int main() {
        int n; cin>>n;
        int * arr = new int[n];
        node * tree = new node[4*n]();
        for(int i=0;i<n;i++) cin>>arr[i];
        buildTree(arr,tree,0,n-1);
    
    	int m; cin>>m;
        
        while(m--){
            int a,b;
            cin>>a>>b;
            node res = queryTree(tree,0,n-1,--a,--b);
            cout<<res.msum<<endl;
        }
}
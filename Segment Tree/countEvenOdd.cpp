#include<bits/stdc++.h>
using namespace std;

struct node {
    int e;
    int o;
};

void buildTree(int * arr,node * tree,int start,int end,int idx=1){
    if(start == end){
        if(arr[start]%2 == 0){
            tree[idx] = {1,0};
            return;
        }else{
            tree[idx] = {0,1};
            return;
        }
    }
    
    int mid = (start+end)/2;
    int i = 2*idx, j = i+1;
    buildTree(arr,tree,start,mid,i);
    buildTree(arr,tree,mid+1,end,j);
    tree[idx].e = tree[i].e + tree[j].e;
    tree[idx].o = tree[i].o + tree[j].o;
}

void updateTree(node * tree,int start,int end,int pos,int val,int idx=1){
    if(start == end){
        if(val%2 == 0){
            tree[idx] = {1,0};
            return;
        }else{
            tree[idx] = {0,1};
            return;
        }
    }

    int mid = (start+end)/2;
    int i = 2*idx, j = i+1;
    if(pos <= mid) updateTree(tree,start,mid,pos,val,i);
    else updateTree(tree,mid+1,end,pos,val,j);
    tree[idx].e = tree[i].e + tree[j].e;
    tree[idx].o = tree[i].o + tree[j].o;
}

node queryTree(node * tree,int start,int end,int l,int r,int idx=1){
    if(r<start || l>end){
        node temp = {0,0};
        return temp;
    }

    if(l<=start && r>=end) return tree[idx];

    int mid = (start+end)/2;
    int i = 2*idx, j = i+1;
    node p1 = queryTree(tree,start,mid,l,r,i);
    node p2 = queryTree(tree,mid+1,end,l,r,j);

    node temp = {p1.e+p2.e, p1.o+p2.o};
    return temp;
}

int main() {
    int n; cin>>n;
    int * arr = new int[n];
    node * tree = new node[4*n]();
    for(int i=0;i<n;i++) cin>>arr[i];
    buildTree(arr,tree,0,n-1);

    int q; cin>>q;
    while(q--){
        int a,b,c;
        cin>>a>>b>>c;

        if(a == 0){
            updateTree(tree,0,n-1,--b,c);
        }else if(a == 1){
            node res = queryTree(tree,0,n-1,--b,--c);
            cout<<res.e<<endl;
        }else if(a == 2){
            node res = queryTree(tree,0,n-1,--b,--c);
            cout<<res.o<<endl;
        }
    }

    return 0;
}
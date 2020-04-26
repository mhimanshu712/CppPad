#include <bits/stdc++.h>

using namespace std;

void buildTree(int * arr,int * tree,int end,int start=0,int treeNode=1){
	if(start == end){
		tree[treeNode] = arr[start];
		return;
	}

	int mid = (start + end)/2;
	buildTree(arr,tree,mid,start,2*treeNode);
	buildTree(arr,tree,end,mid+1,2*treeNode+1);
	tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1]; 
}

void updateTree(int* arr,int* tree,int start,int end,int treeNode,int idx,int value){
	if(start == end){
		arr[idx] = value;
		tree[treeNode] = value;
		return;
	}

	int mid = (start+end)/2;
	if(idx > mid){
		updateTree(arr,tree,mid+1,end,2*treeNode+1,idx,value);
	}else{
		updateTree(arr,tree,start,mid,2*treeNode,idx,value);
	}
	tree[treeNode] = tree[2*treeNode] + tree[2*treeNode+1];
}

int queryTree(int* tree,int start,int end,int treeNode,int left,int right){

	//copletely outside
	if(right<start || left>end) return 0;

	//completly inside
	// Analyse this part
	if(left<=start && right>=end) return tree[treeNode];

	//partially
	int mid = (start+end)/2;
	int ans1 = queryTree(tree,start,mid,2*treeNode,left,right);
	int ans2 = queryTree(tree,mid+1,end,2*treeNode+1,left,right);
	return ans1 + ans2;
}

int main(){
	int arr[] = {1,2,3,4,5};
	int * tree = new int[4*5]();

	buildTree(arr,tree,4);
	updateTree(arr,tree,0,4,1,2,10);
	for(int i=1;i<20;i++) cout<<tree[i]<<" ";
	int ans = queryTree(tree,0,4,1,2,4);
	cout<<endl<<ans;
}
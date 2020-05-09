#include <bits/stdc++.h>

using namespace std;

// Find min in an array

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

void updateTreeSeg(int* tree,int* lazy,int start,int end,int l,int r,int inc,int index=1){
	if(l>r) return;

	//Before doing anything first check and update the lazy tree
	if(lazy[index] != 0){
		if(start != end){
			lazy[2*index] += lazy[index];
			lazy[2*index + 1] += lazy[index];
		}
		tree[index] += lazy[index];
		lazy[index] = 0;
	}

	//no overlap
	if(r<start || l>end){
		return;
	}

	//complete overlap
	if(l<=start && r>=end){
		tree[index] += inc;
		if(start != end){
			lazy[2*index] += inc;
			lazy[2*index+1] += inc;
		}
		return;
	}

	//partial
	int mid = (start+end)/2;
	updateTreeSeg(tree,lazy,start,mid,l,r,inc,2*index);
	updateTreeSeg(tree,lazy,mid+1,end,l,r,inc,2*index+1);

	tree[index] = min(tree[2*index],tree[2*index+1]);
}

int queryTree(int* tree,int* lazy,int start,int end,int l,int r,int index=1){
	if(l>r) return INT_MAX/2;

	//Check lazy first
	if(lazy[index] != 0){
		if(start != end){
			lazy[2*index] += lazy[index];
			lazy[2*index+1] += lazy[index];
		}
		tree[index] += lazy[index];
		lazy[index] = 0;
	}

	//no overlap
	if(l>end || r<start) return INT_MAX/2;

	//total overlap
	if(l<=start && r>=end) return tree[index];

	int mid = (start+end)/2;
	int i = 2*index,j = 2*index+1;
	int p1 = queryTree(tree,lazy,start,mid,l,r,i);
	int p2 = queryTree(tree,lazy,mid+1,end,l,r,j);

	tree[index] = min(tree[i],tree[j]);
	return min(p1,p2);
}

int main(){
	int arr[] = {1,3,-2,4};
	int* tree = new int[4*4]();
	int* lazy = new int[4*4]();

	buildTree(arr,tree,0,3,1);
	updateTreeSeg(tree,lazy,0,3,0,0,3);
	updateTreeSeg(tree,lazy,0,3,0,1,2);
	updateTreeSeg(tree,lazy,0,3,1,2,1);

	queryTree(tree,lazy,0,3,0,2);
	updateTreeSeg(tree,lazy,0,3,0,3,2);
	updateTreeSeg(tree,lazy,0,3,1,2,1);
	int res = queryTree(tree,lazy,0,3,1,2);
	cout<<"Query: "<<res<<endl;

	for(int i=1;i<12;i++) cout<<tree[i]<<" ";
	cout<<endl;
	for(int i=1;i<12;i++) cout<<lazy[i]<<" ";
	return 0;
}
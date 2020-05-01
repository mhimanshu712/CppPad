#include <bits/stdc++.h>

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

void updateTreeSeg(int* tree,int* lazy,int start,int end,int l,int r,int inc,int index=1){
	if(l>r) return;

	if(lazy[index] != 0){
		if(start != end){
			lazy[2*index] = lazy[2*index+1] = lazy[index];
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

int main(){
	int arr[] = {1,3,-2,4};
	int* tree = new int[4*4]();
	int* lazy = new int[4*4]();

	buildTree(arr,tree,0,3,1);
	updateTreeSeg(tree,lazy,0,3,0,3,3);
	updateTreeSeg(tree,lazy,0,3,0,1,2);

	for(int i=1;i<12;i++) cout<<tree[i]<<" ";
	cout<<endl;
	for(int i=1;i<12;i++) cout<<lazy[i]<<" ";
	return 0;
}
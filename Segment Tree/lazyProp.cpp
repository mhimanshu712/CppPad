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
	tree[index] = tree[2*index] + tree[2*index+1];
}

void updateTree(int* arr,int* tree,int* lazy,int start,int end,int pos,int val,int index=1){
	if(start == end){
		tree[index] = val;
	}

	if(lazy[index] != 0){
		if(start != end){
			lazy[2*index] = lazy[2*index+1] = lazy[index];
		}
		tree[index] += lazy[index];
		lazy[index] = 0;
	}
}
#include <bits/stdc++.h>

using namespace std;

struct node {
	int sum;
	int sq;
};

struct lnode{
	int val;
	int state;  // 0 nothing 1 - set 2-inc
};

void buildTree(int* arr,node* tree,int start,int end,int index=1){
	if(start == end){
		tree[index].sum = arr[start];
		tree[index].sq = pow(arr[start],2);
		return;
	}

	int mid = (start+end)/2;
	int i = 2*index,j=2*index+1;
	buildTree(arr,tree,start,mid,i);
	buildTree(arr,tree,mid+1,end,j);

	tree[index].sum = tree[i].sum + tree[j].sum;
	tree[index].sq = tree[i].sq + tree[j].sq;
}

void updateTreeI(node* tree,lnode* lazy,int start,int end,int l,int r,int inc,int index=1){
	if(l>r) return;
	int i = 2*index,j = 2*index+1;

	if(lazy[index].state != 0){
		if(lazy[index].state == 1){
			if(start != end){
				lazy[i] = {lazy[index].val,1};
				lazy[j] = {lazy[index].val,1}; 
			}
			tree[index].sum = (end-start+1)*(lazy[index].val);
			tree[index].sq = (end-start+1)*pow(lazy[index].val,2);
			lazy[index] = {0,0};
		}else{
			if(start != end){
				lazy[i].val += lazy[index].val;
				lazy[j].val += lazy[index].val;
				if(lazy[i].state == 0) lazy[i].state = 2;
				if(lazy[j].state == 0) lazy[j].state = 2;
			}
			tree[index].sum += (end-start+1)*(lazy[index].val);
			tree[index].sq += (end-start+1)*pow(lazy[index].val,2) + 2*lazy[index].val*tree[index].sum;
			lazy[index] = {0,0};
		}
	}

	if(l>end || r<start) return;

	if(l<=start && r>=end){
		tree[index].sq += (end-start+1)*pow(inc,2) + 2*inc*tree[index].sum;
		tree[index].sum += (end-start+1)*inc;

		if(start != end){
			lazy[i].val += inc;
			lazy[j].val += inc;
			if(lazy[i].state == 0) lazy[i].state = 2;
			if(lazy[j].state == 0) lazy[j].state = 2;
		}
		return;
	}

	int mid = (start+end)/2;
	updateTreeI(tree,lazy,start,mid,l,r,inc,i);
	updateTreeI(tree,lazy,mid+1,end,l,r,inc,j);

	tree[index].sum = tree[i].sum + tree[j].sum;
	tree[index].sq = tree[i].sq + tree[j].sq;
}

void updateTreeS(node* tree,lnode* lazy,int start,int end,int l,int r,int v,int index=1){
	if(l>r) return;
	int i = 2*index,j = 2*index+1;

	if(lazy[index].state != 0){
		if(lazy[index].state == 1){
			if(start != end){
				lazy[i] = {lazy[index].val,1};
				lazy[j] = {lazy[index].val,1}; 
			}
			tree[index].sum = (end-start+1)*(lazy[index].val);
			tree[index].sq = (end-start+1)*pow(lazy[index].val,2);
			lazy[index] = {0,0};
		}else{
			if(start != end){
				lazy[i].val += lazy[index].val;
				lazy[j].val += lazy[index].val;
				if(lazy[i].state == 0) lazy[i].state = 2;
				if(lazy[j].state == 0) lazy[j].state = 2;
			}
			tree[index].sum += (end-start+1)*(lazy[index].val);
			tree[index].sq += (end-start+1)*pow(lazy[index].val,2) + 2*lazy[index].val*tree[index].sum;
			lazy[index] = {0,0};
		}
	}

	if(l>end || r<start) return;

	if(l<=start && r>=end){
		tree[index].sq = (end-start+1)*pow(v,2);
		tree[index].sum = (end-start+1)*v;

		if(start != end){
			lazy[i] = {v,1};
			lazy[j] = {v,1};
		}
		return;
	}

	int mid = (start+end)/2;
	updateTreeS(tree,lazy,start,mid,l,r,v,i);
	updateTreeS(tree,lazy,mid+1,end,l,r,v,j);

	tree[index].sum = tree[i].sum + tree[j].sum;
	tree[index].sq = tree[i].sq + tree[j].sq;
}

node queryTree(node* tree,lnode* lazy,int start,int end,int l,int r,int index=1){
	if(l>r){
		node temp = {0,0};
		return temp;
	}
	int i = 2*index,j = 2*index+1;

	if(lazy[index].state != 0){
		if(lazy[index].state == 1){
			if(start != end){
				lazy[i] = {lazy[index].val,1};
				lazy[j] = {lazy[index].val,1}; 
			}
			tree[index].sum = (end-start+1)*(lazy[index].val);
			tree[index].sq = (end-start+1)*pow(lazy[index].val,2);
			lazy[index] = {0,0};
		}else{
			if(start != end){
				lazy[i].val += lazy[index].val;
				lazy[j].val += lazy[index].val;
				if(lazy[i].state == 0) lazy[i].state = 2;
				if(lazy[j].state == 0) lazy[j].state = 2;
			}
			tree[index].sum += (end-start+1)*(lazy[index].val);
			tree[index].sq += (end-start+1)*pow(lazy[index].val,2) + 2*lazy[index].val*tree[index].sum;
			lazy[index] = {0,0};
		}
	}

	if(l>end || r<start){
		node temp = {0,0};
		return temp;
	}

	if(l<=start && r>=end){
		return tree[index];
	}

	int mid = (start+end)/2;
	node p1 = queryTree(tree,lazy,start,mid,l,r,i);
	node p2 = queryTree(tree,lazy,mid+1,end,l,r,j);

	tree[index].sum = tree[i].sum + tree[j].sum;
	tree[index].sq = tree[i].sq + tree[j].sq;

	node temp = {p1.sum+p2.sum,p1.sq+p2.sq};
	return temp;
}

int main(){
	int t; cin>>t;
	int count = 1;

	while(t--){
		int n,q;
		cin>>n>>q;
		int* arr = new int[n];
		node* tree = new node[4*n]();
		lnode* lazy = new lnode[4*n]();
		for(int i=0;i<n;i++) cin>>arr[i];
		buildTree(arr,tree,0,n-1);

		cout<<"Case "<<count++<<":"<<endl;
		while(q--){
			int a,b,c;
			cin>>a>>b>>c;

			if(a == 0){
				int x; cin>>x;
				updateTreeS(tree,lazy,0,n-1,--b,--c,x);
			}

			if(a == 1){
				int x; cin>>x;
				updateTreeI(tree,lazy,0,n-1,--b,--c,x);
			}

			if(a == 2){
				node temp;
				temp = queryTree(tree,lazy,0,n-1,--b,--c);
				cout<<temp.sq<<endl;
			}
		}
	}
}
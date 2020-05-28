#include <bits/stdc++.h>
using namespace std;

struct node{
	node* left = NULL;
	node* right = NULL;
	int leaf = 0;
};

void insert(int val,node* head){
	node* curr = head;
	for(int i=31;i>=0;i--){
        curr->leaf++;
		int cbit = (val>>i)&1;
		if(cbit == 0){
			if(!curr->left) curr->left = new node;
			curr = curr->left;
		}else{
			if(!curr->right) curr->right = new node;
			curr = curr->right;
		}
	}
    // Why this?
    // Draw tree
    curr->leaf++;
}

long query(int val,int b,node* head){
	long count = 0;
	node* curr = head;
	for(int i=31;i>=0;i--){
		int cbit = (val>>i)&1;
		int cmax = (b>>i)&1;

		if(cmax==1 && cbit==0){
			if(curr->left) count += curr->left->leaf;
			if(curr->right) curr = curr->right;
			else break;
		}else if(cmax==1 && cbit==1){
			if(curr->right) count += curr->right->leaf;
			if(curr->left) curr = curr->left;
			else break;
		}else if(cmax==0 && cbit==0){
			if(curr->left) curr = curr->left;
			else break;
		}else if(cmax==0 && cbit==1){
			if(curr->right) curr = curr->right;
			else break;
		}
	}
	return count;
}


int main(){
	int t; cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int* arr = new int[n];
		node* head = new node;
		for(int i=0;i<n;i++) cin>>arr[i];

		
		long count = 0;
		int val = 0;
        // Why this?
        insert(val,head);
		for(int i=0;i<n;i++){
			val = (val^arr[i]);
			count += query(val,k,head);
			insert(val,head);
		}
		cout<<count<<endl;
	}
}
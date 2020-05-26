#include<bits/stdc++.h>
using namespace std;

struct node{
    node* left=NULL;
    node* right=NULL;
};

void insert(node* head,int val){
    node* curr = head;
    for(int i=31;i>=0;i--){
        int currbit = (val>>i)&1;
        if(currbit == 0){
            if(!curr->left) curr->left = new node;
            curr = curr->left;
        }else{
            if(!curr->right) curr->right = new node;
            curr = curr->right;
        }
    }
}

int findMaxXor(node* head,int val,int n){
    node* currNode = head;
    int currVal = 0;
    for(int j=31;j>=0;j--){
        int currbit = (val>>j)&1;
        if(currbit == 0){
            if(currNode->right){
                currVal += pow(2,j);
                currNode = currNode->right;
            }else
                currNode = currNode->left;
                
        }else if(currbit == 1){
            if(currNode->left){
                currVal += pow(2,j);
                currNode = currNode->left;
            }else
                currNode = currNode->right;
        }
    }
    return currVal;
}

int main() {
    int n; cin>>n;
    int* arr = new int[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    node* head = new node;
    
    int maxi = INT_MIN;
    int xors = 0;
    insert(head,0);
    for(int i=0;i<n;i++){
        xors = xors^arr[i];
        int res = findMaxXor(head,xors,1);
        insert(head,xors);
        maxi = max(maxi,res);
    }
    cout<<maxi;
    return 0;
}
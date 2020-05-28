#include <bits/stdc++.h>
using namespace std;

struct node{
	node* children[26]={NULL};
	int weight;
};

void insert(string s,int weight,node* head){
	node* curr = head;
	for(int i=0;i<s.length();i++){
		int index = s[i]-'a';
		if(!curr->children[index]) curr->children[index] = new node();
		curr->children[index]->weight = max(curr->children[index]->weight,weight);
		curr = curr->children[index];
	}
}

int query(string s,node* head){
	node* curr = head;
	for(int i=0;i<s.length();i++){
		int index = s[i]-'a';
		if(!curr->children[index]) return -1;
		curr = curr->children[index];
	}
	return curr->weight;
}

int main(){
	int n,q;
	cin>>n>>q;
	node* head = new node();
	for(int i=0;i<n;i++){
		string s;
		int w;
		cin>>s>>w;
		insert(s,w,head);
	}

	while(q--){
		string s;
		cin>>s;
		int res = query(s,head);
		cout<<res<<endl;
	}
}
#include <bits/stdc++.h>
using namespace std;

struct node{
    node* children[26]={NULL};
    bool word = false;
};

void insert(string s,node* head){
    node* curr = head;
    for(int i=0;i<s.length();i++){
        int index = s[i]-'a';
        if(!curr->children[index]) curr->children[index] = new node();
        curr = curr->children[index];
    }
    curr->word = true;
}

bool checkLeaf(node* head){
    for(int i=0;i<26;i++){
        if(head->children[i]) return false;
    }
    return true;
}

void dfs(node* head,string* prefix,vector<string*>* res){
    if(head->word){
        string* resstr = new string;
        *resstr = *prefix;
        res->push_back(resstr);
        if(checkLeaf(head)) return;
    }
    for(int i=0;i<26;i++){
        if(head->children[i]){
            prefix->push_back(i+'a');
            dfs(head->children[i],prefix,res);
            prefix->pop_back();
        }
    }
}

vector<string*>* query(string s,node* head){
	vector<string*>* res = new vector<string*>;
    vector<string*>* error = new vector<string*>;
    string* errormsg = new string;
    *errormsg = "No suggestions";
    error->push_back(errormsg);

    string* prefix = new string;
    node* curr = head;
    for(int i=0;i<s.length();i++){
        int index = s[i] - 'a';
        if(!curr->children[index]){
            insert(s,head);
            return error;
        }
        prefix->push_back(s[i]);
        curr = curr->children[index];
    }
    dfs(curr,prefix,res);

    return res;
}

int main()
{
    int n; cin>>n;
    node* head = new node();
    for(int i=0;i<n;i++){
        string s; cin>>s;
        insert(s,head);
    }
    int q; cin>>q;
    while(q--){
       string s; cin>>s;

       vector<string*>* res = query(s,head);
       for(auto i : *res){
        cout<<*i<<endl;
       }
    }
    return 0;
}

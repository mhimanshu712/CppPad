#include <bits/stdc++.h>
using namespace std;

struct node{
	int x,y,w;
};

bool cmp(node a,node b){
	return a.w < b.w;
}

int getParent(int a,int* parent){
	while(parent[a] != a) a = parent[a];
	return a;
}

int main(){
	int n,e;
	cin>>n>>e;
	node* edges = new node[e];
	for(int i=0;i<e;i++){
        cin>>edges[i].x>>edges[i].y>>edges[i].w;
    }
	sort(edges,edges+e,cmp);

	int* parent = new int[n];
	for(int i=0;i<n;i++) parent[i] = i;
	vector<node> res;
	
	int count = 0,index=0;
	while(count < n-1){
		int pa = getParent(edges[index].x,parent);
		int pb = getParent(edges[index].y,parent);

		if(pa != pb){
			res.push_back(edges[index]);
			parent[pb] = parent[pa];
			count++;
		}
		index++;
	}

	for(auto i : res){
		cout<<min(i.x,i.y)<<" "<<max(i.x,i.y)<<" "<<i.w<<endl;
	}
	return 0;
}
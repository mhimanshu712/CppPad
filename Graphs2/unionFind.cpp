#include <bits/stdc++.h>
using namespace std;

int getParent(int a,int* parent){
	while(parent[a] != a) a = parent[a];
	return a;
}

int main(){
	cout<<"Enter number of Vertices: ";
	int n; cin>>n;
	cout<<"Enter number of edges: ";
	int e; cin>>e;
	cout<<"Enter the edge pairs: "<<endl;

	int* parent = new int[n];
	for(int i=0;i<n;i++) parent[i] = i;

	while(e--){
		int a,b;
		cin>>a>>b;
		int pa = getParent(a,parent);
		int pb = getParent(b,parent);
		if(pa == pb){
			cout<<"Cycle Detected!";
			break;
		}

		parent[pb] = parent[pa];
	}
}
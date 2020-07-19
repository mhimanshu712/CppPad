#include <bits/stdc++.h>
using namespace std;

int getMinVertex(bool* visited,int* weight,int n){
	// Not initi by 0, cuz...
	// Consider 0 is visited and has minimum weight
	int minVertex = -1;
	for(int i=0;i<n;i++){
		if(!visited[i] && ( (minVertex == -1) || (weight[minVertex] > weight[i]) )  ){
			minVertex = i;
		}
	}
	return minVertex;
}

void prims(int** edges,int n){
	// Here visited means "Taken in MST"
	bool* visited = new bool[n]();
	int* parent = new int[n];
	int* weight = new int[n];
	for(int i=0;i<n;i++) weight[i] = INT_MAX;

	parent[0] = -1;
	weight[0] = 0;

	for(int i=0;i<n-1;i++){

		int minVertex = getMinVertex(visited,weight,n);
		visited[minVertex] = true;

		
		for(int j=0;j<n;j++){
			if(edges[minVertex][j] != 0 && !visited[j]){
				if(weight[j] > edges[minVertex][j]){
					weight[j] = edges[minVertex][j];
					parent[j] = minVertex;
				}
			}
		}

	}

	for(int i=1;i<n;i++){
		cout<<min(parent[i],i)<<" "<<max(parent[i],i)<<" "<<weight[i]<<endl;
	}
}

int main(){
	int n,e;
	cin>>n>>e;
	int** edges = new int*[n];
	for(int i=0;i<n;i++) edges[i] = new int[n]();

	for(int i=0;i<e;i++){
		int f,s,weight;
		cin>>f>>s>>weight;
		edges[f][s] = edges[s][f] = weight;
	}
	
	prims(edges,n);
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int getMinVertex(bool* visited,int* distance,int n){
	int minVertex = -1;
	for(int i=0;i<n;i++){
		if( !visited[i] && ( (minVertex==-1) || (distance[i]<distance[minVertex]) )  ){
			minVertex = i;
		}
	}
	return minVertex;
}

void dijkstra(int** edges,int n){
	bool* visited = new bool[n]();
	int* distance = new int[n]();
	for(int i=1;i<n;i++) distance[i] = INT_MAX;

	for(int i=0;i<n-1;i++){
		int minVertex = getMinVertex(visited,distance,n);
		visited[minVertex] = true;
		for(int j=0;j<n;j++){
			if(!visited[j] && (edges[minVertex][j]))
				if( distance[j] > (edges[minVertex][j]+distance[minVertex]) ){
					distance[j] = edges[minVertex][j] + distance[minVertex];
				}
		}

	}

	for(int i=0;i<n;i++){
		cout<<i<<" "<<distance[i]<<endl;
	}

}

int main(){
	int n,e;
	cin>>n>>e;
	int** edges = new int*[n];
	for(int i=0;i<n;i++) edges[i] = new int[n]();

	for(int i=0;i<e;i++){
		int a,b,w;
		cin>>a>>b>>w;
		edges[a][b] = edges[b][a] = w;
	}

	dijkstra(edges,n);

	return 0;
}


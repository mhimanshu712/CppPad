#include <bits/stdc++.h>

using namespace std;

// void cdfs(int** arr,bool* v,int n,int s){
// 	cout<<s<<" ";
// 	v[s] = true;
// 	for(int i=0;i<n;i++){
// 		if(i == s) continue;
// 		if(arr[s][i] == 1){
// 			if(v[i]) continue;
// 			cdfs(arr,v,n,i);
// 		}
// 	}
// }


// void cbfs(int** arr,int* v,int n,int s){
// 	deque <int> dq;
// 	dq.push_back(s);
// 	v[s] = true;

// 	while(!dq.empty()){
// 		int curr = dq.front();
// 		dq.pop_front();
// 		cout<<curr<<" ";
// 		for(int i=0;i<n;i++){
// 			if(i == curr) continue;

// 			if(arr[curr][i] == 1 && !v[i]){
// 				dq.push_back(i);
// 				v[i] = true;
// 			}
// 		}
// 	}
// }

void dfs(int** arr,bool* v,int n,int s){
		cout<<s<<" ";
		v[s] = true;
		for(int i=0;i<n;i++)
			if(arr[s][i] == 1 && v[i] == false)
				dfs(arr,v,n,i);
}

void dfsFull(int** arr,int n){
	bool * v = new bool[n]();
	for(int i=0;i<n;i++)
		if(!v[i]) dfs(arr,v,n,i);
}

void bfs(int** arr,bool* v,int n,int s){
	deque <int> dq;

	dq.push_back(s);
	v[s] = true;

	while(!dq.empty()){
		int t = dq.front();
		dq.pop_front();
		cout<<t<<" ";
		for(int i=0;i<n;i++){

			if(arr[t][i] == 1 && !v[i]){
				dq.push_back(i);
				v[i] = true;
			}
		}
	}
}

void bfsFull(int** arr,int n){
	bool* v = new bool[n]();
	for(int i=0;i<n;i++)
		if(!v[i]) bfs(arr,v,n,i);

}

int main(){
	int V, E;
    cin >> V >> E;
    bool * vis = new bool[V]();
    int** mat = new int*[V];
    for(int i=0;i<V;i++) mat[i] = new int[V]();

    for(int i=0;i<E;i++){
        int a,b;
        cin>>a>>b;
        mat[a][b] = 1;
        mat[b][a] = 1;
    }

    bfsFull(mat,V);
}
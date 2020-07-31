#include<bits/stdc++.h>
using namespace std;

struct node {
    int x,y,w;
};

bool comp(node a,node b){
    return a.w < b.w;
}

int getParent(int a,int* parent){
    while(parent[a] != a){
        a = parent[a];
    }
    return a;
}

int main()
{
	int t; cin>>t;
    int s = t;
    while(t--){
        int n,m,a;
        cin>>n>>m>>a;
        node* edges = new node[m];
        int* parent = new int[n];
        for(int i=0;i<n;i++) parent[i] = i;
        
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y>>edges[i].w;
            edges[i].x = x-1;
            edges[i].y = y-1;
        }
        sort(edges,edges+m,comp);
        
        int index = 0;
        int totalWeight = 0;
        while(edges[index].w < a && index < m){
            int p1 = getParent(edges[index].x,parent);
            int p2 = getParent(edges[index].y,parent);
            
            if(p1 != p2){
                parent[p2] = parent[p1];
                totalWeight += edges[index].w;
            }
            index++;
        }
        
        bool* check = new bool[n]();
        int airports = 0;
        for(int i=0;i<n;i++){
            parent[i] = getParent(parent[i],parent);
            if(!check[parent[i]]) airports++;
            check[parent[i]] = true;
        }
  
        long long total = (long long)a*airports + totalWeight;
        cout<<"Case #"<<s-t<<": "<<total<<" "<<airports<<endl;
    }
	return 0;
}

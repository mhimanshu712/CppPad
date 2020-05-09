#include <bits/stdc++.h>
using namespace std;

struct node {
    int start;
    int end;
    int weight;
};

bool compare(node a,node b){
    return (a.weight<b.weight);
}

int getParent(int a,int* arr){
    if(arr[a] == a) return a;
    return getParent(arr[a],arr);
}

node* kruskal(node* arr,int n,int e){
    node* output = new node[n-1];
    int* parent = new int[n];
    for(int i=0;i<n;i++) parent[i] = i;
    sort(arr,arr+e,compare);
    
    int count = 0, i = 0;
    
    while(count < n-1){
        node curr = arr[i];
        int startPar = getParent(arr[i].start,parent);
        int endPar = getParent(arr[i].end,parent);

        if(startPar != endPar){
            output[count] = curr;
            count++;
            parent[endPar] = startPar;
        }
        i++;
    }

    return output;
}

int main()
{
    int n, E;
    cin >> n >> E;
    node * arr = new node[E];
    for(int i=0;i<E;i++){
        cin>>arr[i].start;
        cin>>arr[i].end;
        cin>>arr[i].weight;
    }
    
    node* res = kruskal(arr,n,E);
    for(int i=0;i<n-1;i++){
        cout<<min(res[i].start,res[i].end)<<" "<<max(res[i].start,res[i].end);
        cout<<" "<<res[i].weight<<endl;
    }

    return 0;
}


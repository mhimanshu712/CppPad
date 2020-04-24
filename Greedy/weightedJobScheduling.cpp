#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int start,end,profit;
}item;

bool comp(item a, item b){
    return a.end < b.end;
}

int main(){
    int n;
    cin>>n;
    item * sarr = new item[n];
    for(int i=0;i<n;i++){
        cin>>sarr[i].start;
        cin>>sarr[i].end;
        cin>>sarr[i].profit;
    }
    
    sort(sarr,sarr+n,comp);
    
    int * dp = new int[n];
    
    dp[0] = sarr[0].profit;
    
    for(int i=1;i<n;i++){
        int inc = sarr[i].profit;
        int index = -1;
        int a = 0, b = i-1,m;
        while(a<=b){
            m = (a+b)/2;
            if(sarr[m].end <= sarr[i].start){
                index = max(index,m);
                a = m+1;
            }else{
                b = m-1;
            }
        }
        // for(int j=i-1;j>=0;j--){
        //     if(sarr[j].end <= sarr[i].start){
        //         index = j;
        //         break;
        //     }
        // }
        
        if(index != -1) inc += dp[index];
        dp[i] = max(dp[i-1],inc);
    }
    cout<<dp[n-1];
    return 0;
}
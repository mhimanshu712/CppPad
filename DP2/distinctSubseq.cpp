#include <bits/stdc++.h>
using namespace std;

int MOD = pow(10,9)+7;

int main()
{
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        vector <int> dp(s.length()+1,1);
        vector <int> h(256,-1);
        
        
        for(int i=1;i<s.length()+1;i++){
            dp[i] = (2*dp[i-1])%MOD;
            if(h[s[i-1]] > -1){
                dp[i] -= dp[h[s[i-1]]];
                
                //Had to add this to handle the very special when dp[i]>MOD but dp[...] is not
                //Then the number becomes negative
                if(dp[i]<0) dp[i] += MOD;
            }
            h[s[i-1]] = i-1;
        }
        
        cout<<dp[s.length()]<<endl;
    }
    return 0;
}
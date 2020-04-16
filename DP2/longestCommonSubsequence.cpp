#include <bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2){
    vector<vector<int>> vec(s1.length()+1,vector<int>(s2.length()+1));
    
    for(int i=0;i<=s1.length();i++) vec[i][0] = 0;
    for(int j=0;j<=s2.length();j++) vec[0][1] = 0;
    
    for(int i=1;i<=s1.length();i++)
        for(int j=1;j<=s2.length();j++){
            if(s1[s1.length() - i] == s2[s2.length() - j]) vec[i][j] = 1+vec[i-1][j-1];
            else
                vec[i][j] = max(vec[i-1][j],vec[i][j-1]);
        }
    
    return vec[s1.length()][s2.length()];
}

int main(){
    string a,b;
    cin>>a>>b;
    cout<<lcs(a,b);
}
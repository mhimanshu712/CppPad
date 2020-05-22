#include <bits/stdc++.h>

using namespace std;

int countPalindromeSubstrings(char s[]) {
    int n = strlen(s);
    int count=0;
    
    for(int i=0;i<n;i++){
        int l=i,r=i;
        while(l>=0 && r<n && s[l] == s[r]){
            count++;
            l--; r++;
        }
        
        l = i, r = i + 1;
        while(l>=0 && r<n && s[l] == s[r]){
            count++;
            l--; r++;
        }
    }
    return count;
}


int main(){
    char s[100];
    cin>>s;
    int res = countPalindromeSubstrings(s);
    cout<<res;

    return 0;
}
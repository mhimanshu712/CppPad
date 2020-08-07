#include <bits/stdc++.h>

char* uniqueChar(char *str){
    // Write your code here
    set <int> s;
    
    int n = strlen(str);
    char * o = new char[n];
    
    int j = 0;
    for(int i=0;i<n;i++){
        if(s.find(str[i]) == s.end()){
            o[j++] = str[i];
            s.insert(str[i]);
            
        }
    }
    o[j] ='\n';
    return o;
}
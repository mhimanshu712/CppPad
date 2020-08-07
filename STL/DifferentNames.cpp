#include <iostream>
#include<bits/stdc++.h>
#include<string>
#include <map>

using namespace std;

int main(){
    
    string s;
    getline(cin,s);
    map<string,int>mp;


   string word = ""; 
   for (auto x : s) { 
       if (x == ' ') { 
           mp[word]++;
           word = ""; 
       } 
       else{ 
           word = word + x; 
       } 
   }  
   mp[word]++;
 
  int f=0;
    for(auto bp:mp){
          if(bp.second>1){
          	cout<< bp.first<<" "<<bp.second<<endl;
          f=1;
          }
        
    }
    if(f==0){
        return -1;
    }
}
  
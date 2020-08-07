#include <bits/stdc++.h>
using namespace std;

char getChar(int i){
	return (char) (i+97);
}

void printPalindrome(string s){

	map<char,vector<int> > indexMap;
	for(int i=0;i<s.length();i++){
		indexMap[s[i]].push_back(i);
	}

	int odd = 0;
	for(int i=0;i<26;i++){
		if((indexMap[getChar(i)].size() % 2) != 0){
			odd++;
		}
	}

	if(odd > 1){
		cout<<"-1";
		return;
	}

	int ans[s.length()];
	int start = 0;
	int end = s.length()-1;

	for(int i=0;i<26;i++){
		for(int j = 0 ; j<indexMap[getChar(i)].size(); j+= 2){

			if((indexMap[getChar(i)].size() - j)  == 1){
				ans[s.length()/2] = indexMap[getChar(i)][j];
				continue;
			}

			ans[start] = indexMap[getChar(i)][j];
			ans[end] = indexMap[getChar(i)][j+1];
			start++;
			end--;
		}
	}

	for(int i=0;i<s.length();i++){
		cout<<ans[i] + 1<<" ";
	}

	return;

}

int main(){
	int t; cin>>t;
	while(t--){
		string s; cin>>s;
		printPalindrome(s);
		cout<<endl;
	}
	return 0;
}

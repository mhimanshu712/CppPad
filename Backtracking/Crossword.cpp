#include<bits/stdc++.h>
using namespace std;

vector <string> grid(10);
vector <string> words;

bool findPos(vector<string> grid,char s,int &x,int &y){
    for(int i=x;i<grid.size();i++)
        for(int j=y;j<grid.size();j++)
            if(grid[i][j] == '-' || grid[i][j] == s){
                x = i;
                y = j;
                return true;
            }
    return false;
}

bool checkHorizontal(vector<string> grid,string word,int x,int y){
    int j = 0;
    while(j < word.length()){
        //Bounds check
        if(y+j >= grid.size()) return false;
        if(grid[x][y+j] != '-' && grid[x][y+j] != word[j])
            return false;
        j++;    
    }
    if(y+j < grid.size() && grid[x][y+j] == '+') return true;
    return false;
}

bool checkVertical(vector<string> grid,string word,int x,int y){
    int i=0;
    while(i < word.length()){
        if(x+i >= grid[0].length()) return false;
        if(grid[x+i][y] != '-' && grid[x+i][y] != word[i])
            return false;
        i++;
    }
    if(x+i<grid[0].length() && grid[x+i][y] == '+') return true;
    return false;
}

void fillVertical(vector<string> &grid,int x,int y,string word,vector<bool> &mem){
    int i = 0;
    while(i<word.length()){
        if(grid[x+i][y] == '-') mem[i] = true;
        grid[x+i][y] = word[i];
        i++;
    }
}

void fillHorizontal(vector<string> &grid,int x,int y,string word,vector<bool> &mem){
    int j=0;
    while(j<word.length()){
        if(grid[x][y+j] == '-') mem[j] = true;
        grid[x][y+j] = word[j];
        j++;
    }
}

unfillVer(vector<string> &grid,int x,int y,vector<bool> &mem){
	int i=0;
    while(i<mem.size()){
    	if(mem[i] == true) grid[x+i][y] = '-';
        i++;
    }
}

unfillHor(vector<string> &grid,int x,int y,vector<bool> &mem){
	int j=0;
    while(j<mem.size()){
    	if(mem[j] == true) grid[x][y+j] = '-';
        j++;
    }
}


bool solveCrossWord(vector<string> &grid,vector <string> &words,int s,int x,int y){
    if(s == words.size()){
		for(int i=0;i<10;i++){
        	for(int j=0;j<10;j++)
            	cout<<grid[i][j];
        	cout<<endl;
    	}
    	
    	return false;
	}
    
    findPos(grid,words[s][0],x,y);
    
    if(checkVertical(grid,words[s],x,y)){
        vector <bool> mem(words[s].length(),false);
        fillVertical(grid,x,y,words[s],mem);
        solveCrossWord(grid,words,s+1,0,0);
        unfillVer(grid,x,y,mem);
    }
    if(checkHorizontal(grid,words[s],x,y)){
        vector <bool> mem(words[s].length(),false);
        fillHorizontal(grid,x,y,words[s],mem);
        solveCrossWord(grid,words,s+1,0,0);
        unfillHor(grid,x,y,mem);
    }
    
    //solveCrossWord(grid,words,s,x,y);
}

void split(string &st,char d,vector<string> &out){
	int i=0;
	string temp;
    while(i <= st.length()){
        if(st[i] == d || i == st.length()){
            out.push_back(temp);
            temp = "";
            i++;
        }
        temp.push_back(st[i++]);
    }
}

int main() {
    for(int i=0;i<10;i++)
        cin>>grid[i];
    
    string s;
    cin>>s;
	split(s,';',words);
    
    solveCrossWord(grid,words,0,0,0);
}

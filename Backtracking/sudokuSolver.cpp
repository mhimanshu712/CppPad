#include <bits/stdc++.h>

using namespace std;

#define N 9

bool checker(int arr[][9],int r,int c,int v){
	for(int i=0;i<N;i++)
		if(arr[i][c] == v) return false;
		
	for(int j=0;j<N;j++)
		if(arr[r][j] == v) return false;
	
	//Check grid	
	int rf = (r/3)*3, cf = (c/3)*3;
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			if(arr[rf+i][cf+j] == v) return false;
	
		
	return true;
}

bool findEmpty(int arr[][9],int &r,int &c){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(arr[i][j] == 0){
				r = i;
				c = j;
				return true;
			}
		}
	}
	return false;
}

bool solveSudoku(int arr[][9]){
	int r,c;
	if(!findEmpty(arr,r,c)){
		return true;
	}
	
	for(int i=1;i<=N;i++){
		if(checker(arr,r,c,i)){
			arr[r][c] = i;
			if(solveSudoku(arr)){
				return true;
			}
			arr[r][c] = 0;
		}
	}
	return false;
}

int main(){
	int arr[N][N];
	
	for(int i=0;i<N;i++){
		string s;
		cin>>s;
		for(int j=0;j<N;j++) arr[i][j] = s[j] - '0';
	}
	
	solveSudoku(arr);
	
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++)
			cout<<arr[i][j];
			
		cout<<endl;
	}
	
}
#include <bits/stdc++.h>
using namespace std;

void matmul(int A[2][2],int B[2][2]){
	int C[][2] = {{0,0},{0,0}};

	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			for(int k=0;k<2;k++){
				C[i][j] += A[i][k]*B[k][j];
			}
		}
	}

	for(int i=0;i<2;i++)
		for(int j=0;j<2;j++) A[i][j] = C[i][j];
}

void matExpo(int A[2][2],int n){
	if(n == 1) return;

	matExpo(A,n/2);
	matmul(A,A);
	if(n%2 != 0){
		int F[2][2] = {{1,1},{1,0}};
		matmul(A,F);
	}
}

int fibo(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	
	int A[][2] = {{1,1},{1,0}};
	matExpo(A,n-1);
	return A[0][0];
}

int main(){
	int n; cin>>n;
	cout<<fibo(n);
	return 0;
}
#include <bits/stdc++.h>

const int mod = pow(10,9)+7;
typedef unsigned long long ull;

void matMul(ull A[2][2], ull B[2][2]){
    ull C[2][2] = {{0,0},{0,0}};
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                C[i][j] = (C[i][j]+(A[i][k]*B[k][j])%mod)%mod;
            }
        }
    }
    
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            A[i][j] = C[i][j];
        }
    }
}

void matPow(ull A[2][2],int n){
    if(n == 1) return;
    
    matPow(A,n/2);
    matMul(A,A);
    if(n%2 != 0){
        ull T[2][2] = {{1,1},{1,0}};
        matMul(A,T);
    }
}

int fibo(ull n){
    if(n == 0) return 0;
    if(n == 1) return 1;
    
    ull A[2][2] = {{1,1},{1,0}};
    matPow(A,n-1);
    return (int)(A[0][0]%mod);
}

unsigned long long fiboSum(unsigned long long m,unsigned long long n)
{
	return ((fibo(n+2)-1) - (fibo(m+1)-1) + mod)%mod;
}

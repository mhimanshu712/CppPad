
#include <stdio.h>
#include <stdbool.h>
#include "headers/mat_input.h"
#include "headers/mat_display.h"

int main(){
	matrix m;
	m = mat_input();

	int * d = (int *) calloc(sizeof(int),m.n);
	int count=0;
	bool * v = (bool *) calloc(sizeof(bool),m.n);

	for(int i=0;i<m.n;i++) d[i] = INT_MAX;

	printf("Enter the starting vertex: ");
	int s;
	scanf("%d",&s);
	d[s] = 0;
	d[s] = true;
	count++;

	while(count<m.e){
		int min=INT_MAX, minindex;
		for(int i=0;i<m.n && v[i]==false;i++){
			if(d[i]<min){
				min = d[i];
				minindex = i;
			}
		}

		int t = d[minindex];
		v[minindex] = true;
		count++;

		for(int i=0;i<m.n;i++){
			if(m.ptr[minindex][i] && !v[i]){
				if(d[i]>m.ptr[minindex][i]) d[i] = m.ptr[minindex][i];
			}
		}
	}

	for(int i=0;i<m.n;i++) printf(" %d",d[i]);

}
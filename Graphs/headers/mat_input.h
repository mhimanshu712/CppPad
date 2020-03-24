#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int n;
	int * * ptr;
}matrix;

matrix  input_mat(){
	matrix  mt;
	printf("\nEnter number of Vertices: ");
	int n;
	scanf("%d",&n);
	
	int **at = (int **) malloc(n*sizeof(int *));
	for(int i=0;i<n;i++)
		at[i] = (int *) calloc(sizeof(int),n);
	
	int e;
	printf("Enter the number of Edges: ");
	scanf("%d",&e);
	printf("Enter each each edge pairwise: ");
	int a,b;
	for(int i=0;i<e;i++){
		scanf("%d %d",&a,&b);
		at[a][b] = at[b][a] = 1;
	}
	
	mt.ptr=at;
	mt.n = n;
	return mt;
}
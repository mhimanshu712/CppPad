#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int n;
	int e;
	int * * ptr;
}matrix;

matrix  mat_input(){
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
	printf("Enter each each edge pairwise and corresponding weight: ");
	int a,b,w;
	for(int i=0;i<e;i++){
		scanf("%d %d %d",&a,&b,&w);
		at[a][b] = at[b][a] = w;
	}
	
	mt.ptr=at;
	mt.n = n;
	mt.e = e;
	return mt;
}
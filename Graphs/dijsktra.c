
#include <stdio.h>
#include "headers/mat_input.h"
#include "headers/mat_display.h"

int main(){
	matrix m;
	m = mat_input();

	int * v = (int *) malloc(sizeof(int)*m.n);
	for(int i=0;i<v;i++) v[i] = INT_MAX;

}
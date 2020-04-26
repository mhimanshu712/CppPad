#include <bits/stdc++.h>

using namespace std;
#define MAX_VAL 10000000

heap {
	int * arr = new int[MAX_VAL];
	int i = 0;
};

void insert(heap* h,int val){
	h->arr[h->i++] = val;
}

int main(){
	heap mh;

}
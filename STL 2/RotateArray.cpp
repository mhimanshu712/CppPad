// arr - input array
// size - size of array
// d - array to be rotated by d elements

void Rotate(int arr[], int d, int size) {
    for(int i=0;i<d;i++){
        int a = arr[0];
        for(int j=0;j<size-1;j++){
            arr[j]=arr[j+1];
        }
        arr[size-1] = a;
    }

}	

int clearAllBits(int n, int i){
    int m = (1<<(i+1)) - 1;
    return m & n;
}
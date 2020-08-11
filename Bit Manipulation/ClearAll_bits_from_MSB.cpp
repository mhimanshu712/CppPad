int clearAllBits(int n, int i){
    int m = ~(-1<<i);
    return m & n;
}
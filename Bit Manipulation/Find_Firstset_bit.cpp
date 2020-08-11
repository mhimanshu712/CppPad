int returnFirstSetBit(int n){
    n = n & (-1 * n);
    return n;
}
int turnOffFirstSetBit(int n){
    return n & ~(-n);
}
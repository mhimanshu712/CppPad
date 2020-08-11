int flipIthBit(int n, int i){
    n = n ^ (1<<i);
    
    return n;
}
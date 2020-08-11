bool checkPowerOfTwo(int n){
	n = n & (n-1);
	return (n == 0);
}
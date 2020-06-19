#include <bits/stdc++.h>
using namespace std;

struct node{
	int x,y,gcd;
};

node extEuclid(int a,int b){
	// ax + by = gcd(a,b)
	// if b=0; ax = a; x = 1; let y=0;
	if(b == 0){
		node ans = {1,0,a};
		return ans;
	}

	node smallAns = extEuclid(b,a%b);
	node ans;
	ans.gcd = smallAns.gcd;
	ans.x = smallAns.y;
	ans.y = smallAns.x - (a/b)*smallAns.y;
	return ans;
}

int main(){
	node ans = extEuclid(15,10);
	cout<<ans.x<<" "<<ans.y<<" "<<ans.gcd;
	return 0;
}
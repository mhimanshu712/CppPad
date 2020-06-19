#include <bits/stdc++.h>
using namespace std;

struct node {
	int x,y,gcd;
};

node extEuclid(int a,int b){
	if(b == 0){
		node ans = {1,0,a};
		return ans;
	}

	node smallAns = extEuclid(b,a%b);
	node ans;
	ans.x = smallAns.y;
	ans.y = smallAns.x - (a/b)*smallAns.y;
	ans.gcd = smallAns.gcd;

	return ans;
}

int mmInverse(int a,int m){
	node ans = extEuclid(a,m);
	return ans.x;
}

int main(){
	int a = 5;
	int m = 12;

	int ans = mmInverse(a,m);
	cout<<ans;
}
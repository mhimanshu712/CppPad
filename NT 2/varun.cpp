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
	return (ans.x%m + m)%m;
}

int main(){
	int t; cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		int g = __gcd(a,b);
		if(d%g){
			cout<<0<<endl;
			continue;
		}

		if(d == 0){
			cout<<1<<endl;
			continue;
		}
		a/=g;
		b/=g;
		d/=g;

		int y1 = ((d%a) + mmInverse(b,a))%a;
		int firstVal = d/b;

		if(d < y1*b){
			cout<<0<<endl;
			continue;
		}

		int n = (firstVal - y1)/a;

		int ans = n+1;
		cout<<ans<<endl;
	}
	return 0;
}
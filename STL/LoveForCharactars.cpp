#include<bits/stdc++.h>
#include<map>
using namespace std;
int main()
{
    
	string s;
    int len;
    cin>>len;
    cin>>s;
    map<char,int>m;
    int ch;
    for(int i=0;i<len;i++)
    {
        ch=s[i];
        if(ch=='a'||ch=='s'||ch=='p')
        m[ch]=m[ch]+1;
    }
    
    map<char,int>::iterator it;
    //for(it=m.begin();it!=m.end();it++)
         cout<<m['a']<<" "<<m['s']<<" "<<m['p']<<endl;
}
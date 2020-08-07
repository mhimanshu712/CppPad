#include<bits/stdc++.h>
using namespace std;
int main() {

	int num;
    cin>>num;
    int *arr=new int[num];
    int *dep=new int[num];
    sort(arr,arr+num);
    sort(dep,dep+num);
    int c=0;
    int res=0;
    int j=0;
    for(int i=0;i<num;i++)
    {
      if(arr[i]<=dep[j])
      {
          c++;
          i++;
      
        if(res<c)
        {
            res=c;
        }
      }  
        else
        {
            c--;
            j++;
        }
    }
    cout<<res<<endl;
}
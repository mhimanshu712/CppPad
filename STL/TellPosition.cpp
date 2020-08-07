#include <bits/stdc++.h>

using namespace std;

typedef struct {
    int roll;
    char name[50];
    int marks;
}stud;

bool sortS(stud a, stud b){
    if(a.marks == b.marks)
        return a.roll < b.roll;
        
    return a.marks > b.marks;
}

int main(){
    int n;
    cin>>n;
    stud * studs = new stud[n];
    int a,b,c;
    for(int i=0;i<n;i++){
        cin>>studs[i].name>>a>>b>>c;
        studs[i].roll = i;
        studs[i].marks = a+b+c;
    }
    
    sort(studs,studs+n,sortS);
    
    for(int i=0;i<n;i++) cout<<i+1<<" "<<studs[i].name<<endl;
    
}

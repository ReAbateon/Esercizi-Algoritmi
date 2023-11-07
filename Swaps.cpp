//UVa_00331_Mapping _the_Swaps

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector <int> a;
int ans, c;

void backtrack(int x){
    int flag=0, t;
    for(int i=1; i<a.size(); i++){
        if(a[i]<a[i-1]){
            t=a[i];
            a[i]=a[i-1];
            a[i-1]=t;
            backtrack(x+1);
            t=a[i];
            a[i]=a[i-1];
            a[i-1]=t;
            flag=1;
        }
    }
    if(flag==0){
        if(ans>x){
            ans=x;
            c=0;
        }
        if(ans==x){
            c++;
        }
    }
}

void build(int n){
    a.clear();
    a.resize(n);
}

int main(){
    ifstream file("/Users/lorenzo/Documents/Algoritms and Data Structure/Programmi/input.txt");
    
    int t;

    while(1){
        int n;
        file>>n;
        if(n==0){
            break;
        }
        t++;

        build(n);

        for(int i=0; i<n; i++){
            file>>a[i];
        }
        ans=100000;
        c=0;
        backtrack(0);
        if(ans==0){
            c=0;
        }
        cout<<"There are "<<c<<" swap maps for input data set "<<t<<endl;
    }
}
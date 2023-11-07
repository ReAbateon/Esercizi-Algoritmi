#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int k, dim;
vector <int> a;
int result;

int countoccurrences(int left, int right){
    if(left==right){
        if(a[left]==k){
            return 1;
        }else{
            return 0;
        }
    }else if(left<right){
        int c=0;
        int mid=(left+right)/2;
        c+=countoccurrences(left, mid);
        c+=countoccurrences(mid+1, right);

        return c;
    }
}

void build (){
    a.clear();
    a.resize(dim);
}

int main(){
    ifstream file("/Users/lorenzo/Documents/Algoritms and Data Structure/Programmi/input.txt");
    
    int t;
    file>>t;

    for(int i=0; i<t; i++){
        file>>k;
        file>>dim;

        build();

        for(int i=0; i<dim; i++){
            file>>a[i];
        }

        result=countoccurrences(0, dim-1);
        cout<<result<<endl;

    }
}
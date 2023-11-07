#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int dim, sum;
vector <int> a;

int findUtil(int left, int right, int diff){
    while(left<=right){
        int mid=(left+right)/2;

        if((a[mid]-a[0])/diff==mid){
            left=mid+1;
        }else{
            right=mid-1;
        }
    }
    return a[right]+diff;
}

int find(){
    int diff=((a[dim-1]-a[0])/dim);

    return findUtil(0, dim-1, diff);
}

void build(){
    a.clear();
    a.resize(dim);
}

int main(){
    ifstream  file("/Users/lorenzo/Documents/Algoritms and Data Structure/Programmi/input.txt");

    int N;
    file>>N;

    for(int i=0; i<N; i++){
        file>>dim;
        
        build();

        for(int i=0; i<dim; i++){
            file>>a[i];
        }
        
        cout<<find()<<endl;
    
    }
}
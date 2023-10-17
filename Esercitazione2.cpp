#include <iostream>
#include <vector>

using namespace std;

vector <bool> Tree;

int FinalPos (int x, int D, int n){
    if(x==D){
        return n;
    }

    if(!Tree[n]){
        Tree[n]=true;
        return FinalPos(x+1, D, 2*n+1);
    }else{
        Tree[n]=false;
        return FinalPos(x+1, D, 2*n+2);
    }
}

int main(){
    int D, N, sol;

    cout<<"Inserisci la profondità : ";
    cin>>D;
    cout<<"Inserisci il numero di palline : ";
    cin>>N;

    int size=1;

    for(int i=0; i<D; i++){
        size*=2;
    }

    Tree.resize(size);

    for(int i=0; i<N; i++){
        sol=FinalPos(1, D, 0)+1;
    }

    cout<<sol<<endl;
    
}
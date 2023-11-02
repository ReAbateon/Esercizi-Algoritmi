//UVa 10276 - Hanoi Tower Troubles Again

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n, sol;
vector <vector<int> > pioli;

bool control(int b, int pos){
    if(pioli[pos].empty()){
        return true;
    }
    int r=sqrt(pioli[pos].back()+b);
    if(r*r==pioli[pos].back()+b){
        return true;
    }else{
        return false;
    }
}

void backtrack(int b){
    for(int i=0; i<n; i++){
        if(control(b, i)){
            sol++;
            pioli[i].push_back(b);
            return backtrack(b+1);
        }
    }
    return;
}

int main(){
    //cout<<"Inserisci il numero di pioli : ";
    //cin>>n;
    n=25;
    sol=0;
    pioli.resize(n);
    backtrack(1);
    cout<<sol<<endl;
}
//UVa 00750 - 8 Queens Chess Problem

#include <iostream>
#include <cstdlib>

using namespace std;

int r,c, cont;
int riga[8];

bool control(int i, int j){
    for(int prev=0; prev<j; prev++){
        if(riga[prev]==i || (abs(riga[prev]-i))==abs(prev-j)){
            return false;
        }
    }
    return true;
}

void backtrack(int j){
    if(j==8 && riga[c]==r){
        cout<<cont++<<"    "<<riga[0]+1;
        for(int x=1; x<8; x++){
            cout<<" "<<riga[x]+1;
        }
        cout<<endl;
    }
    for(int i=0; i<8; i++){
        if(control(i, j)){
            riga[j]=i;
            backtrack(j+1);
        }
    }
}

int main(){
    //cin>>r>>c;
    //r--;
    //c--;
    r=1;
    c=2;
    r--;
    c--;
    cont=1;
    backtrack(0);
}
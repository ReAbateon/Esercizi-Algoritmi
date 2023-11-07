#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector <int> a;
int k=0, sol=10000;

void backtrack(int att){
    if(att==a.size()-1 || att>a.size()-1){
        if(sol>k){
            sol=k;
        }
        return;
    }
    for(int i=1; i<=a[att]; i++){
        k++;
        backtrack(att+i);
        k--;
    }
}

int main(){
    ifstream file("/Users/lorenzo/Documents/Algoritms and Data Structure/Programmi/input.txt");

    int N;
    file>>N;

    a.resize(N);

    for(int i=0; i<N; i++){
        file>>a[i];
    }

    backtrack(0);

    cout<<sol<<endl;
}
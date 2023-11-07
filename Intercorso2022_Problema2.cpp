#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int S, N, P;
vector <int> prim;
vector <int> sol;
int sum=0;

bool isPrime (int num){
    if(num<=1){
        return false;
    }

    for(int i=2; i*i<=num; i++){
        if(num%i==0){
            return false;
        }
    }
    return true;
}

void CreateSequence(){
    for(int i=P+1; i<=S; i++){
        if(isPrime(i)){
            prim.push_back(i);
        }
    }
}

void backtrack(int x){
    if(sol.size()==N){    
        if(sum==S){
            for(int j=0; j<sol.size(); j++){
                cout<<sol[j]<<" ";
            }
            cout<<endl;
        }
        return;
    }    
    if(sum>S){
        return;
    }
    for(int i=x; i<prim.size(); i++){
        sol.push_back(prim[i]);
        sum+=prim[i];
        backtrack(i+1);
        sum-=prim[i];
        sol.pop_back();
    }
}

int main(){
    ifstream file("/Users/lorenzo/Documents/Algoritms and Data Structure/Programmi/input.txt");

    int t;
    file>>t;

    for(int i=0; i<t; i++){
        file>>S;
        file>>N;
        file>>P;

        CreateSequence();

        cout<<"CASO DI TEST "<<i+1<<endl;

        backtrack(0);
        prim.clear();
        sol.clear();
        sum=0;
        
    }
}
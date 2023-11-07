#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

typedef pair <int,int> pii;
string parola;
int N, M;
vector <vector<char> > a;
vector <pii> indici;
int k=0;

bool control(int x, int y, int attr, int attc){
    if(x>=0 && x<M && y>=0 && y<N && a[x][y]==parola[k]){
        if(x!=attr || y!=attc){
            return true;
        }    
    }else{
        return false;
    }
}

void backtrack(int attr, int attc){
    if(indici.size()==parola.length()){
        for(auto &z:indici){
            cout<<z.first+1<<" "<<z.second+1<<endl;
        }
        cout<<"END"<<endl;
        return;
    }
    for(int x=attr-1; x<attr+2; x++){
        for(int y=attc-1; y<attc+2; y++){
            if(control(x, y, attr, attc)){
                indici.push_back(make_pair(x, y));
                k++;
                backtrack(x, y);
                if(indici.size()==parola.length()){
                    return;
                }
                k--;
                indici.pop_back();
            }
        }
    }
}

void build(){
    a.clear();
    a.resize(N);
    for(int i=0; i<N; i++){
        a[i].resize(M);
    }
}

int main(){
    ifstream file("/Users/lorenzo/Documents/Algoritms and Data Structure/Programmi/input.txt");

    int t;
    file>>t;
    
    for(int i=0; i<t; i++){
        file>>parola;
        file>>N;
        file>>M;

        build();

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                file>>a[i][j];
            }
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(a[i][j]==parola[0]){
                    indici.clear();
                    k=0;
                    indici.push_back(make_pair(i, j));
                    k++;
                    backtrack(i, j);
                }
                if(indici.size()==parola.length()){
                        break;
                }
            }
            if(indici.size()==parola.length()){
                        break;
            } 
        }
    }
}
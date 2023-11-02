//UVa 00167 - The Sultan Successor

#include <iostream>
#include <set>
#include <vector>

using namespace std;

typedef pair<int,int> pii;
int scacchiera [8][8];
set <int> righe, colonne, diagprinc, diagsec;
vector <pii> regine;
int finale;

bool sicurezza(int i, int j){
    return !righe.count(i) && !colonne.count(j) && !diagprinc.count(i+j) && !diagsec.count(i-j);
}

void make_move(int i, int j){
    regine.push_back(make_pair(i, j));
    righe.insert(i);
    colonne.insert(j);
    diagprinc.insert(i+j);
    diagsec.insert(i-j);
}

void unmake_move(int i, int j){
    regine.pop_back();
    righe.erase(i);
    colonne.erase(j);
    diagprinc.erase(i+j);
    diagsec.erase(i-j);
}

void process_solution(){
    int somma=0;
    for(auto &x:regine){
        somma+=scacchiera[x.first][x.second];
    }
    if(somma>finale){
        finale=somma;
    }
}

void backtrack(int i){
    if(i==8){
        if(regine.size()==8){
            process_solution();
        }
        return;
    }

    for(int j=0; j<8; j++){
        if(sicurezza(i,j)){
            make_move(i, j);
            backtrack(i+1);
            unmake_move(i, j);
        }
    }
}

void start(){
    regine.clear();
    righe.clear();
    colonne.clear();
    diagprinc.clear();
    diagsec.clear();
    finale=0;
}

int main(){
    int k=1;

    //cout<<"Inserisci il numero di scacchiere : ";
    //cin>>k;
    int n=0;
    while(k--){
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                scacchiera[i][j]=n+1;
                n++;
                cout<<scacchiera[i][j]<<" ";
            }
            cout<<endl;
        }

        start();
        backtrack(0);
        cout<<finale<<endl;
    }
}
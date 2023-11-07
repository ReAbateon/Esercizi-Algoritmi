#include <iostream>
#include <vector>

using namespace std;

vector <vector<int> > a;
vector <vector<int> > sol;
int attr, attc;
int N;

void build(){
    a.resize(N);
    for(int i=0; i<N; i++){
        a[i].resize(N);
    }

    sol.resize(N);
    for(int i=0; i<N; i++){
        sol[i].resize(N);
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            sol[i][j]=0;
        }
    }

}

bool down(int attr, int attc){
    if(attr==N-1){
        return false;
    }
    if(a[attr+1][attc]==1){
        return true;
    }else{
        return false;
    }
}

bool right(int attr, int attc){
    if(attc==N-1){
        return false;
    }
    if(a[attr][attc+1]==1){
        return true;
    }else{
        return false;
    }
}

void backtrack(int attr, int attc){
    if(attr==N-1 && attc==N-1){
        sol[attr][attc]=1;
        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                cout<<sol[i][j]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    for(int i=0; i<2; i++){
        if(i==0){
            if(down(attr, attc)){
                sol[attr][attc]=1;
                backtrack(attr+1, attc);
                sol[attr][attc]=0;
            }
        }
        if(i==1){
            if(right(attr, attc)){
                sol[attr][attc]=1;
                backtrack(attr, attc+1);
                sol[attr][attc]=0;
            }
        }
    }
}

int main(){
    cout<<"Inserisci N : ";
    cin>>N;

    build();

    int num;
    cout<<"Crea il labirinto : "<<endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cin>>num;
            a[i][j]=num;
        }
    }
    cout<<endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;
    
    backtrack(0, 0);
}
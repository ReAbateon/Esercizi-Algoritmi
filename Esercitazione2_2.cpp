#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

typedef pair<int, int> pii;
int attr, attc, res, sol, W, H;
vector<vector <int> > a;
vector <pii> punti;
string name;

void build(){
    a.resize(H);
    for(int i=0; i<H; i++){
        a[i].resize(W);
    }
}

bool right(int attr, int attc){
    if(attc==W-1){
        return false;
    }
    if(a[attr][attc+1]<a[attr][attc]){
        return true;
    }else{
        return false;
    }
}

bool left(int attr, int attc){
    if(attc==0){
        return false;
    }
    if(a[attr][attc-1]<a[attr][attc]){
        return true;
    }else{
        return false;
    }
}

bool up(int attr, int attc){
    if(attr==0){
        return false;
    }
    if(a[attr-1][attc]<a[attr][attc]){
        return true;
    }else{
        return false;
    }
}

bool down(int attr, int attc){
    if(attr==H-1){
        return false;
    }
    if(a[attr+1][attc]<a[attr][attc]){
        return true;
    }else{
        return false;
    }
}

void backtrack(int attr, int attc){
    if(!right(attr, attc) && !left(attr, attc) && !up(attr, attc) && !down(attr, attc)){
        punti.push_back(make_pair(attr, attc));
        int som=0;
        for(auto &x: punti){
            som+=a[x.first][x.second];
        }
        if(som>res){
            res=som;
            sol=punti.size();
        }
        punti.pop_back();
        return;
    }

    for(int i=0; i<4; i++){
        if(i==0){
            if(right(attr, attc)){
                punti.push_back(make_pair(attr, attc));
                backtrack(attr, attc+1);
                punti.pop_back();
            }
        }
        if(i==1){
            if(left(attr, attc)){
                punti.push_back(make_pair(attr, attc));
                backtrack(attr, attc-1);
                punti.pop_back();
            }
        }
        if(i==2){
            if(down(attr, attc)){
                punti.push_back(make_pair(attr, attc));
                backtrack(attr+1, attc);
                punti.pop_back();
            }
        }
        if(i==3){
            if(up(attr, attc)){
                punti.push_back(make_pair(attr, attc));
                backtrack(attr-1, attc);
                punti.pop_back();
            }
        }
    }
}

int main(){
    ifstream file("/Users/lorenzo/Documents/Algoritms and Data Structure/Programmi/input.txt");
    
    int N;
    file>>N;

    for(int i=0; i<N; i++){
        file>>name;
        file>>H;
        file>>W;

        build();
            
        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                file>>a[i][j];
            }
        }

        for(int i=0; i<H; i++){
            for(int j=0; j<W; j++){
                punti.clear();
                backtrack(i, j);
            }
        }
        
        cout<<name<<": "<<sol<<endl;
        sol=0;
        res=0;
    }
}    
//UVa 00539 - The Settlers of Catan

#include <iostream>
#include <vector>

using namespace std;

const int N=25;
bool visit[N];
vector <int> Strade[N];
int dist;

void backtrack(int s, int d){
   if(d>dist){
        dist=d;
    }
    for(int i=0; i<Strade[s].size(); i++){
        int att=Strade[s][i];
        if(visit[att]){
            continue;
        }
        visit[att]=true;
        backtrack(att, d+1);
        visit[att]=false;
    }
}

int main(){
    int n, m;
    cout<<"Inserisci il numero di città : ";
    cin>>n;
    cout<<"Inserisci il numero di strade : ";
    cin>>m;

    cout<<"Inserisci le coppie di partenza e arrivo : "<<endl;
    int da, a;
    
    while(m--){
        cin>>da>>a;
        Strade[da].push_back(a);
        Strade[a].push_back(da);
        cout<<"ok"<<endl;
    }

    dist=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<N; j++){
            visit[j]=false;
        }
        backtrack(i, 0);
    }

    cout<<dist<<endl;
}
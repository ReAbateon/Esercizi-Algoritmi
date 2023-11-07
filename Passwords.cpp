//UVa_00628_Passwords

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

string rule;
vector <string> words;

void backtrack(int idx, int att){
    if(att==rule.length()){
        for(int x=0; x<rule.length(); x++){
            if(rule[x]=='#'){
                cout<<words[idx];
            }else{
                cout<<rule[x];
            }
        }
        cout<<endl;
        return;
    }
    if(rule[att]=='#'){
        backtrack(idx, att+1);
    }else{
        for(int x='0'; x<='9'; x++){
            rule[att]=x;
            backtrack(idx, att+1);
        }
    }
}

int main(){
    ifstream file("/Users/lorenzo/Documents/Algoritms and Data Structure/Programmi/input.txt");
    
    int t;
    file>>t;
    int n, m;

    for(int i=0; i<t; i++){
        file>>n;
        words.resize(n);
        for(int i=0; i<n; i++){
            file>>words[i];
        }

        file>>m;
        for(int i=0; i<m; i++){
            file>>rule;
            for(int j=0; j<n; j++){
                backtrack(j, 0);
            }
        }
    }

}
#include <iostream>
#include <vector>

using namespace std;

string FindCommonPrefix(vector <string>& strings, int left, int right){
    
    if(left==right){

        return strings[left];
    
    }else if(left<right){

        int middle=(left + right)/2;

        //L'algoritmo divide il vettore originale in due sottovettori tramite chiamate ricorsive. 
        string leftstring = FindCommonPrefix(strings, left, middle);
        string rightstring = FindCommonPrefix(strings, middle+1, right);
        
        //Ricerca della parola più breve per non effettuare confronti inutili
        int minlenght;
        if(leftstring.length()<rightstring.length()){
            minlenght=leftstring.length();        
        }else{
            minlenght=rightstring.length();
        }

        //Ciclo per il confronto delle lettere
        for(int i=0; i < minlenght; i++){
            if(leftstring[i]!=rightstring[i]){
                return leftstring.substr(0, i);
            }
        }

        return leftstring.substr(0, minlenght);

    }else
        cout<<"Errore 1"<<endl;
    
    return "Errore 2";
}

int main(){

    vector <string> strings;
    string CommonPrefix;

    cout<<"Inserisci il numero di test case : ";
    int t;
    cin>>t;
    string word;
    int c;

    for(int i=0; i<t; i++){
        cout<<"Inserisci le parole del caso di test numero "<<i+1<<" (per terminare inserisci 0): "<<endl;
        while(true){
            cin>>word;
            c=word.compare("0");
            
            if(c==0){ 
                break;
            }

            strings.push_back(word);
        }

        CommonPrefix=FindCommonPrefix(strings, 0, strings.size()-1);
        cout<<"Il prefisso in comune è "<<CommonPrefix<<endl;
        strings.clear();
   }

}
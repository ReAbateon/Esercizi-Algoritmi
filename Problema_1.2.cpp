#include <iostream>
#include <vector>

using namespace std;

//Funzione per la ricerca del prefisso in comune più lungo
string FindCommonPrefix(vector <string>& strings, int left, int right){
    //Se left e right sono uguali significa che il vettore di stringhe ha un solo elemento
    if(left==right){

        return strings[left];
    
    }else if(left<right){

        int middle=(left + right)/2;

        //L'algoritmo divide il vettore originale in due sottovettori tramite chiamate ricorsive. 
        string leftstring = FindCommonPrefix(strings, left, middle);
        string rightstring = FindCommonPrefix(strings, middle+1, right);
        
        int minlenght;
        if(leftstring.length()<rightstring.length()){
            minlenght=leftstring.length();        
        }else{
            minlenght=rightstring.length();
        }

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

    //Creo il primo test case
    vector <string> strings = {"1", "flower", "flow", "flight"};
    
    for(int j=0; j<strings.size(); j++){
        cout<<strings[j]<<endl;
    }
    cout<<endl;

    string CommonPrefix = FindCommonPrefix(strings, 1, strings.size()-1);
    cout<<CommonPrefix<<endl;
    cout<<endl;

    //Creo il secondo test case
    strings = {"2", "home", "house", "homelander", "host", "horse", "hope"};

    for(int j=0; j<strings.size(); j++){
        cout<<strings[j]<<endl;
    }
    cout<<endl;

    CommonPrefix = FindCommonPrefix(strings, 1, strings.size()-1);
    cout<<CommonPrefix<<endl;
    cout<<endl;

    //Creo il terzo test case in cui non ci sono prefissi comuni
    strings = {"3", "crest", "razor", "blade"};

    for(int j=0; j<strings.size(); j++){
        cout<<strings[j]<<endl;
    }
    cout<<endl;

    CommonPrefix = FindCommonPrefix(strings, 1, strings.size()-1);
    cout<<CommonPrefix;

}
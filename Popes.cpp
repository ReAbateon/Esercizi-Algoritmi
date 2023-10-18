#include <iostream>

using namespace std; 
int n,a,b;
int i,j;

void PNumber(int popes[], int Y, int p){
    for(i=0; i<p; i++){
        int c=0;
        for(j=i; j<p && popes[j]<popes[i]+Y; j++){
            c++;
        }

        if(c>n){
            n=c;
            a=popes[i];
            b=popes[j-1];
        }    
    }
}

int main(){
    int p, Y;
    cout<<"Inserisci il numero di papa : ";
    cin>>p;
    cout<<"Inserisci il periodo : ";
    cin>>Y;
    int popes[p];
    for(int x=0; x<p; x++){
        cin>>popes[x];
    }

    PNumber(popes, Y, p);

    cout<<n<<" "<<a<<" "<<b<<endl; 

}
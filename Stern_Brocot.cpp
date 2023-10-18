//UVa_10077_The-Stern-Brocot
#include <iostream>

using namespace std;

string Brocot(int m, int n, int a=0, int b=1, int c=1, int d=0){
    int x=a+c;
    int y=b+d;

    if(m==x && n==y){
        return "";
    }

    if(m*y<n*x){
        return 'L' + Brocot(m, n, a, b, x, y);
    }else{
        return 'R' + Brocot(m, n, x, y, c, d);
    }
}

int main(){
    int m,n;
    cout<<"Inserisci il numeratore : ";
    cin>>m;
    cout<<"Inserisci il denominatore : ";
    cin>>n;

    string nbrocot=Brocot(m, n);
    
    if(m==1 && n==1){
        nbrocot="I";
    }
    
    cout<<nbrocot<<endl;
}
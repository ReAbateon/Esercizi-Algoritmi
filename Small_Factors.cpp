//UVa_11621 Small Factors
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

vector <int> C;

void Gen(int m){
    int p, l;
    for(int i=0; i<32; i++){
        for(int j=0; j<32; j++){
            p=pow(2,i)*pow(3,j);
            if(p>m){
                C.push_back(p);
                break;
            }else{
                C.push_back(p);
            }
        }
    }
}

int Find(int m){
    
    Gen(m);

    sort(C.begin(), C.end());

    int left=0;
    int right=C.size()-1;
    int mid;
    int y;

    while(left<=right){
        mid=(left+right)/2;

        if(C[mid]>=m){
            y=C[mid];
            right=mid-1;
        }else{
            left=mid+1;
        }    
    }


    return y;


}

int main(){
    int m, t, y;
    cout<<"Inserisci il numero di casi di test : ";
    cin>>t;
    for(int x=0; x<t; x++){
        cout<<"Inserisci il numero : ";
        cin>>m;
        y=Find(m);
        cout<<"Il più piccolo numero è : "<<y<<endl;
        C.clear();
    }
}
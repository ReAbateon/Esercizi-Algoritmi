//UVa 11876 - N + NOD (N)
#include <iostream>
#include <vector>

using namespace std;

vector <int> sequence;

void CreateSequence(int B){
    int n=1;
    int i=0;
    int d=0;
    sequence.push_back(n);

    while(sequence[i]<B){
        for(int j=1; j<=n; j++){
            if(n%j==0){
                d++;
            }
        }
        n+=d;
        sequence.push_back(n);
        i++;
        d=0;
    }
}

int IndexA(int A, int left, int right){
    int y;

    while(left<=right){
        int mid=(left+right)/2;

        if(sequence[mid]>A){
            y=mid;
            right=mid-1;  
        }else{
            left=mid+1;
        }
    }

    return y;
}

int IndexB(int B, int left, int right){
    int y;

    while(left<=right){
        int mid=(left+right)/2;

        if(sequence[mid]>=B){
            right=mid-1;  
        }else{
            y=mid;
            left=mid+1;
        }
    }

    return y;
}

int Find(int A, int B){
    CreateSequence(B);

    int left=0;
    int right=sequence.size()-1;
    int IA, IB;

    IA=IndexA(A, left, right);
    IB=IndexB(B, left, right);

    return IB-IA+1;

}

int main(){
    int t, A, B, y;

    A=3000;
    B=4000;

    y=Find(A, B)+2;
    cout<<y;

    /*cout<<"Inserisci il numero di casi di test : ";
    cin>>t;

    for(int i=0; i<t; i++){
        cout<<"Inserisci A e B : ";
        cin>>A>>B;
        y=Find(A, B)+2;
        cout<<y;
        sequence.clear();
        cout<<endl;
    }*/
}
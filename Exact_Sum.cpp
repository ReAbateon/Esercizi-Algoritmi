//UVa 11057 - Exact Sum

#include <iostream>
#include <vector>

using namespace std;

void Find(vector <int>& prices, int N, int M){
    sort(prices.begin(), prices.end());
    int y1=0;
    int y2=0;

    for(int i=0; i<N && M-prices[i]>=prices[i]; i++){
        int x=M-prices[i];
        int left=i+1;
        int right=N-1;
        int mid;
        while(left<=right){
            mid=(left+right)/2;

            if(prices[mid]>x){
                right=mid-1;
            }else if(prices[mid]<x){
                left=mid+1;
            }else if(prices[mid]==x){
                y1=prices[i];
                y2=prices[mid];
                break;
            }
        }
    }

    cout<<"Peter dovrebbe comprare i libri con prezzi "<<y1<<" e "<<y2<<endl;
}

int main(){
    int t, N, p, M;
    int j=0;
    vector <int> prices;
    
    cout<<"Inserisci il numero di casi di test : ";
    cin>>t;

    for(int i=0; i<t; i++){
        cout<<"Inserisci il numero di libri : ";
        cin>>N;
        cout<<"Inserisci il prezzo dei libri : "<<endl;
        while(j<N){
            cin>>p;
            prices.push_back(p);
            j++;
        }
        cout<<"Inserisci i soldi : ";
        cin>>M;

        Find(prices, N, M);
        prices.clear();
        j=0;
    }
}
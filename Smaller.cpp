#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int partition(vector <int>& a, int left, int right){
    int p=a[right];
    int i=left-1;

    for(int j=left; j<right; j++){
        if(a[j]<p){
            i++;
            swap(a[i], a[j]);
        }
    }

    swap(a[i+1], a[right]);
    return i+1;
}

int quickselect(vector <int>& a, int left, int right, int k){
    if(left==right){
        return a[left];
    }

    int pivot=partition(a, left, right);

    if(k==pivot){
        return a[pivot];
    }else if(k<pivot){
        return quickselect(a, left, pivot-1, k);
    }else{
        return quickselect(a, pivot+1, right, k);
    }
}

int Smaller(vector <int>& a, int k){
    if(k<0 || k>=a.size()){
        cout<<"Errore"<<endl;
        return -1;
    }

    return quickselect(a, 0, a.size()-1, k);
}

int main(){
    ifstream file("/Users/lorenzo/Documents/Algoritms and Data Structure/Programmi/input.txt");

    int N;
    file>>N;

    vector <int> a;
    a.resize(N);

    int k;
    file>>k;

    for(int i=0; i<N; i++){
        file>>a[i];
    }

    int sol=Smaller(a, k-1);

    cout<<sol<<endl;


}
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int Majority(vector <int>& a, int left, int right){
    if(left==right){
        return a[left];
    }

    int mid=(left+right)/2;

    int leftMaj=Majority(a, left, mid);
    int rightMaj=Majority(a, mid+1, right);

    if(leftMaj==rightMaj){
        return leftMaj;
    }

    int leftcount=0;
    int rightcount=0;

    for(int i=left; i<=right; i++){
        if(a[i]==leftMaj){
            leftcount++;
        }else if(a[i]==rightMaj){
            rightcount++;
        }
    }

    if(leftcount>rightcount){
        return leftMaj;
    }else{
        return rightMaj;
    }
}

int main(){
    ifstream file("/Users/lorenzo/Documents/Algoritms and Data Structure/Programmi/input.txt");

    int N;
    file>>N;

    vector <int> a;
    a.resize(N);
    for(int i=0; i<N; i++){
        file>>a[i];
    }

    int sol=Majority(a, 0, a.size()-1);

    int count = 0;
    for (int i=0; i<N; i++){
        if(a[i]==sol){
            count++;
        }
    }

    if(count>N/2){
        cout<<sol<<endl;
    }
}
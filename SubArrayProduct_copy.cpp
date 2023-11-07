#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int prodTotal(vector <int>& a, int left, int mid, int right){
    int prod_s=a[mid];
    int prod=prod_s;

    for(int i=left; i<mid; i++){
        prod*=a[i];
       // if(prod>prod_s){
        //    prod_s=prod;
        //}
    }
    prod_s=prod;

    prod=1;
    int prod_d=-100000;
    for(int i=mid+1; i<right+1; i++){
        prod*=a[i];
        if(prod>prod_d){
            prod_d=prod;
        }
    }

    return prod_d*prod_s;
}

int find(vector <int>& a, int left, int right){
    if(left==right){
        return a[left];
    }

    int mid=(left+right)/2;

    int max_s=find(a, left, mid);
    int max_d=find(a, mid+1, right);
    int max_c=prodTotal(a, left, mid, right);

    if(max_s>max_d && max_s>max_c){
        return max_s;
    }else if(max_d>max_s && max_d>max_c){
        return max_d;
    }else{
        return max_c;
    }
}

int main(){
    ifstream file("input.txt");

    string linea;
    int num, res;
    vector <int> a;

    while(getline(file, linea)){
        if(linea.empty()){
            break;
        }
        if(istringstream(linea)>>num){
            a.resize(num);
        }
        for(int i=0; i<num; i++){
            file>>a[i];
        }
        int sol=0;

        for(int i=0; i<num/2; i++){
            res=find(a, i, (num-1)-i);
            if(res>sol)
                sol=res;
        }
        cout<<sol<<endl;


    }
}
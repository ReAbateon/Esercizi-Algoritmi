#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int SumCentral(vector <int>& a, int left, int mid, int right){
    int sum_sx=a[mid];
    int sum=sum_sx;

    for(int i=left; i<mid; i++){
        sum+=a[i];
        if(sum>sum_sx){
            sum_sx=sum;
        }
    }

    sum=0;
    int sum_dx=-10000;
    for(int i=mid+1; i<right+1; i++){
        sum+=a[i];
        if(sum>sum_dx){
            sum_dx=sum;
        }
    }

    return sum_dx+sum_sx;
}

int SumArray(vector <int>& a, int left, int right){
    if(left==right){
        return a[left];
    }else if(left<right){
        int mid=(left+right)/2;

        int max_sx=SumArray(a, left, mid);
        int max_dx=SumArray(a, mid+1, right);
        int max_c=SumCentral(a, left, mid, right);

        if(max_sx>max_dx && max_sx>max_c){
            return max_sx;
        }else if(max_dx>max_sx && max_dx>max_c){
            return max_dx;
        }else if(max_c>max_sx && max_c>max_dx){
            return max_c;
        }
    }
}

int main(){
    ifstream file("/Users/lorenzo/Documents/Algoritms and Data Structure/Programmi/input.txt");

    vector <int> a;
    
    int t;
    file>>t;

    for(int i=0; i<t; i++){
        int n;
        file>>n;
        
        a.clear();
        a.resize(n);
        for(int j=0; j<n; j++){
            file>>a[j];
        }

        int res=SumArray(a, 0, n-1);
        cout<<res<<endl;
    }


}
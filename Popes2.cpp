#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int n=0; 
int a, b;
int c=0;

void Find(vector <int>& popes, int Y, int P){
    for(int i=0; i<P; i++){
        int x=Y+popes[i]-1;
        int left=i+1;
        int right=P-1;
        int mid;
        while(left<=right){
            mid=(left+right)/2;
            if(x>popes[mid]){
                c=(mid-i)+1;
                if(c>n){
                    n=c;
                    a=popes[i];
                    b=popes[mid];
                }
                left=mid+1;
            }else if(x<popes[mid]){
                right=mid-1;
            }else if(x==popes[mid]){
                c=(mid-i)+1;
                if(c>n){
                    n=c;
                    a=popes[i];
                    b=popes[mid];
                }
                break;
            }
        }
    }
}

int main(){
    ifstream file("input.txt");

    int Y;
    file>>Y;
    int P;
    file>>P;

    vector <int> popes;
    popes.resize(P);

    for(int i=0; i<P; i++){
        file>>popes[i];
    }

    Find(popes, Y, P);

    cout<<n<<" "<<a<<" "<<b<<endl;
}
//UVa 10742 - New Rule in Euphomia

#include <iostream>
#include <vector>

using namespace std;

vector <int> primen;
int result;

void Sieve(int n) 
{ 
    // Create a boolean array "prime[0..n]" and initialize 
    // all entries it as true. A value in prime[i] will 
    // finally be false if i is Not a prime, else true. 
    bool prime[n + 1]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p = 2; p * p <= n; p++) { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) { 
            // Update all multiples of p greater than or 
            // equal to the square of it numbers which are 
            // multiple of p and are less than p^2 are 
            // already been marked. 
            for (int i = p * p; i <= n; i += p) 
                prime[i] = false; 
        } 
    } 
    //Metti i numeri primi nel vettore primen
    for (int p = 2; p <= n; p++) 
        if (prime[p]){
            //cout << p << " ";
            primen.insert(primen.end(), p);
        } 
             
}

void Calcres(int n){
    for(int i=0; i<primen.size() && n-primen[i]>primen[i]; i++){
        int x=n-primen[i];
        int l=i+1;
        int r=primen.size()-1;
        int p=i;
        while(l<=r){
            int mid=(l+r)/2;
            if(primen[mid]<=x){
                l=mid+1;
                p=mid;
            }else{
                r=mid-1;
            }
        }
        result+=p-i;
    }
}

int main(){
    int n=10;
    Sieve(n);
    //cout<<primen.size()<<endl;
    for(int i=0; i<primen.size(); i++){
        cout<<primen[i]<<" ";
    }
    cout<<endl;
    Calcres(n);
    cout<<result<<endl;

}
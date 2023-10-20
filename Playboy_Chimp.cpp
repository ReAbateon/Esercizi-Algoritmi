//UVa_10611_Playboy_Chimp
#include <iostream>

using namespace std;

int x,y;

int FindTallestShorter(int Ladies[], int height, int left, int right){
    int mid=left+((right-left)/2);

    if(Ladies[mid]>=height){
        if(left>right){
            return x;
        }

        return FindTallestShorter(Ladies, height, left, mid-1);
    }else{
        if(Ladies[mid]>x){
            x=Ladies[mid];
        }

        if(left>right){
            return x;
        }

        return FindTallestShorter(Ladies, height, mid+1, right);
    }
}

int FindShorterTallest(int Ladies[], int height, int left, int right){
    int mid=left + ((right-left)/2);

    if(Ladies[mid]>height){
        if(Ladies[mid]<y){
            y=Ladies[mid];
        }

        if(left>right){
            return y;
        }
        
        return FindShorterTallest(Ladies, height, left, mid-1);
    }else{
        if(left>right){
            return y;
        }

        return FindShorterTallest(Ladies, height, mid+1, right);
    }
}

int main(){
    
    int N, Q;
    cout<<"Inserisci il numero di Femmine : ";
    cin>>N;

    int Ladies[N];
    //cout<<"Inserisci le altezze : ";
    for(int i=0; i<N; i++){
        Ladies[i]=i;
    }

    cout<<"Inserisci il numero di Query : ";
    cin>>Q;

    cout<<"Inserisci le altezze da confrontre : ";
    int Heights[Q];
    for(int i=0; i<Q; i++){
        cin>>Heights[i];
    }

    int TS,ST;

    for(int i=0; i<Q; i++){
        x=0;
        TS=FindTallestShorter(Ladies, Heights[i], 0, N-1);
        y=100000;
        ST=FindShorterTallest(Ladies, Heights[i], 0, N-1);
        cout<<TS<<" "<<ST<<endl;
    }
    
}       
#include <iostream>
#include <vector>

using namespace std;

int inversioni=0;

void merge(vector <int>& array, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Crea array temporanei
    int leftArray[n1];
    int rightArray[n2];

    // Copia i dati negli array temporanei leftArray[] e rightArray[]
    for (int i = 0; i < n1; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = array[middle + 1 + j];

    // Unisce gli array temporanei in array[left..right]
    int i = 0; // Indice iniziale del primo sottovettore
    int j = 0; // Indice iniziale del secondo sottovettore
    int k = left; // Indice iniziale del sottovettore unito

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
            inversioni=inversioni+n1-i;
        }
        k++;
    }

    // Copia gli elementi rimanenti di leftArray[], se ce ne sono
    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    // Copia gli elementi rimanenti di rightArray[], se ce ne sono
    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}


void mergeSort(vector <int>& array, int left, int right) {
    if (left < right) {
        // Come (left+right)/2, ma evita l'overflow per left e right grandi
        int middle = left + (right - left) / 2;

        // Ordina la prima e la seconda metà
        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        // Unisce le metà ordinate
        merge(array, left, middle, right);
    }
}

int main() {
    int n, t, e;
    vector <int> array;
    cout<<"Inserisci il numero di casi di test : ";
    cin>>t;

    for(int i=0; i<t; i++){
        cout<<"Inserisci il numero di elementi del caso di test numero "<<i+1<<" : ";
        cin>>n;
        cout<<"Inserisci gli elementi "<<endl;
        
        while(array.size()!=n){
            cin>>e;
            array.insert(array.end(), e);
        }


        mergeSort(array, 0, array.size()-1);

        cout<<"Array Ordinato :"<<endl;
        for(int j=0; j<array.size(); j++){
            cout<<array[j]<<" ";
        }
        cout<<endl;

        cout<<"Il numero di inversioni è : "<<inversioni<<endl;
        cout<<endl;
        array.clear();
        inversioni=0;
    }

    return 0;
}




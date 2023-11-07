#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

struct TreapNode{
    char key;
    int priority;
    TreapNode* left, *right;

        TreapNode(char key){
            this->key=key;
            this->priority=rand() % 100;
            this->left=this->right=nullptr;
        }
};

void RotateLeft(TreapNode* &root){
    TreapNode* R=root->right;
    TreapNode* X=root->right->left;

    R->left=root;
    root->right=X;

    root=R;
}

void RotateRight(TreapNode* &root){
    TreapNode* L=root->left;
    TreapNode* Y=root->left->right;

    L->right=root;
    root->left=Y;

    root=L;
}

void TreapInsert(TreapNode* &root, char key){
    if(root==nullptr){
        root=new TreapNode(key);
        return;
    }

    if(key<root->key){
        TreapInsert(root->left, key);

        if(root->left!=nullptr && root->left->priority>root->priority){
           RotateRight(root);
        }
    }else{
        TreapInsert(root->right, key);

        if(root->right!=nullptr && root->right->priority>root->priority){
            RotateLeft(root);
        }
    }
}

void PrintTreap(TreapNode* &root, int space=0, int height=10){
    // Caso base
    if (root == nullptr) {
        return;
    }
 
    // aumenta la distanza tra i livelli
    space += height;
 
    // stampa prima il figlio giusto
    PrintTreap(root->right, space);
    cout << endl;
 
    // stampa il nodo corrente dopo averlo riempito di spazi
    for (int i = height; i < space; i++) {
        cout << ' ';
    }
    cout << root->key << "(" << root->priority << ")\n";
 
    // stampa il figlio sinistro
    cout << endl;
    PrintTreap(root->left, space);
}

int main(){
    int i=0;
    char k;

    TreapNode* root=nullptr;
    srand(time(nullptr));

    do{
        cout<<"1. Inserisci Elemento"<<endl
            <<"2. Stampa Treap"<<endl
            <<"3. Esci"<<endl;
        cin>>i;
        if(i==1){
            cout<<"Inserisci la chiave (carattere) : ";
            cin>>k;
            TreapInsert(root, k);
        }

        if(i==2){
            PrintTreap(root);
        }
        
    }while(i!=3);
}
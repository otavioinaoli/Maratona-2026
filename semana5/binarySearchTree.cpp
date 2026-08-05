#include <iostream>

using namespace std;

class Node {
public:
    int valor;
    Node* esq;
    Node* dir;

    Node(int elem){
        valor = elem;
        esq = NULL;
        dir = NULL;
    }
};

class Tree {
private:
    Node* raiz;

    Node* insert(Node* node, int elem){
        if(node == NULL){
            return new Node(elem);
        }

        if(elem < node->valor){
            node->esq = insert(node->esq, elem);
        }else{
            node->dir = insert(node->dir, elem);
        }

        return node;
    }

    void inorder(Node* node){
        if (node == NULL)
            return;

        inorder(node->esq);

        cout << " " << node->valor;

        inorder(node->dir);
    }
    
    void preorder(Node* node){
        if (node == NULL)
            return;

        cout << " " << node->valor;
        
        preorder(node->esq);

        preorder(node->dir);
    }
    
    void posorder(Node* node){
        if (node == NULL)
            return;
        
        posorder(node->esq);

        posorder(node->dir);
        
        cout << " " << node->valor;
    }

public:
    Tree(){
        raiz = NULL;
    }

    void insert(int elem){
        raiz = insert(raiz, elem);
    }

    void print(){
        cout << "Pre.:";
        preorder(raiz);
        cout << endl;
        cout << "In..:";
        inorder(raiz);
        cout << endl;
        cout << "Post:";
        posorder(raiz);
        cout << endl;
    }
};

int main(){

    int c;

    cin >> c;

    for(int i = 1; i <= c; i++){

        int n;

        cin >> n;

        Tree arvore;

        while(n--){
            int ai;

            cin >> ai;

            arvore.insert(ai);
        }

        cout << "Case " << i << ":" << endl;

        arvore.print();

        cout << endl;
    }

    return 0;
}
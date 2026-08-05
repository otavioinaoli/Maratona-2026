#include <iostream>

using namespace std;

class Node {
public:
    char valor;
    Node* esq;
    Node* dir;

    Node(char elem){
        valor = elem;
        esq = NULL;
        dir = NULL;
    }
};

class Tree {
public:
    Node* raiz;
    
    Tree(){
        raiz = NULL;
    }

    Node* insert(Node* node, char elem){
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
    
    bool find(Node* node, char elem){
        if(node == NULL)
            return false;
    
        if(node->valor == elem)
            return true;
    
        if(elem < node->valor)
            return find(node->esq, elem);
    
        return find(node->dir, elem);
    }

    void insert(char elem){
        raiz = insert(raiz, elem);
    }

     void inorder(Node* node, bool &first){
        if (node == NULL) return;
    
        inorder(node->esq, first);
    
        if (!first) cout << " ";
        cout << node->valor;
        first = false;
    
        inorder(node->dir, first);
    }
    
    void preorder(Node* node, bool &first){
        if (node == NULL) return;
    
        if (!first) cout << " ";
        cout << node->valor;
        first = false;
    
        preorder(node->esq, first);
        preorder(node->dir, first);
    }
    
    void posorder(Node* node, bool &first){
        if (node == NULL) return;
    
        posorder(node->esq, first);
        posorder(node->dir, first);
    
        if (!first) cout << " ";
        cout << node->valor;
        first = false;
    }
};

int main(){
    Tree arvore;
    string comando;

    while(cin >> comando){
        bool first = true;
        
        if(comando == "INFIXA"){
            arvore.inorder(arvore.raiz, first);
            cout << endl;
        }else if(comando == "PREFIXA"){
            arvore.preorder(arvore.raiz, first);
            cout << endl;
        }else if(comando == "POSFIXA"){
            arvore.posorder(arvore.raiz, first);
            cout << endl;
        }else if(comando == "I"){
            char elem;
            cin >> elem;
            arvore.insert(elem);
        }else if(comando == "P"){
            char elem;
            cin >> elem;
            if(arvore.find(arvore.raiz, elem)){
                cout << elem << " existe" << endl;
            }else{
                cout << elem << " nao existe" << endl;
            }
        }
    }

    return 0;
}
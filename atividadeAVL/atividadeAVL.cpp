#include <iostream>

using namespace std;

struct NoArvore {
    int key;  // chave | data
    NoArvore *left;
    NoArvore *right; 
    int altura; 
};


NoArvore* criaNo(int key){
    NoArvore *novoNo = new NoArvore; 

    novoNo -> key = key; 
    novoNo -> left = NULL; 
    novoNo -> right = NULL;
    novoNo -> altura = 1;

    return novoNo;
}

int alturaNo(NoArvore* No){
    if (No = NULL){
        return 0;
    }
    return No -> altura;
}

int maior(int a, int b){
    if(a > b){
        return a;
    } else {
        return b;
    }

}

NoArvore *rotacaoDireita(NoArvore* p){
    NoArvore *u = p -> left;
    NoArvore *t2 = u -> right;

    u -> right = p;
    p -> left = t2;

    p -> altura = maior(alturaNo(p -> left), alturaNo(p -> right)) + 1;
    u -> altura = maior(alturaNo(u -> left), alturaNo(u -> right)) + 1; 

    return u;
}

NoArvore *rotacaoEsquerda(NoArvore* p){
    NoArvore *u = p -> right;
    NoArvore *t2 = u -> left;

    u -> left = p;
    p -> right = t2;

    p -> altura = maior(alturaNo(p -> left), alturaNo(p -> right)) + 1;
    u -> altura = maior(alturaNo(u -> left), alturaNo(u -> right)) + 1; 

    return u;
}



// em ordem 
void exibirArvore(NoArvore *raiz){
    if (raiz == NULL){
        cout << "Raiz não válida" << endl;
    } else {
        exibirArvore(raiz -> left);
        cout << "No: " << raiz -> key << " ";
        exibirArvore(raiz -> right);
    }
}

NoArvore* inserirAVL(NoArvore *&raiz, int key) {
    if (raiz == NULL){
        raiz = criaNo(key);   
        return raiz;
    }

    if (key > raiz -> key){
        raiz -> right = inserirAVL(raiz -> right, key);
    } else if (key < raiz -> key) {
        raiz -> left = inserirAVL(raiz -> left, key);
    } else {
        cout << "No nao permitido ou ja presente na arvore" << endl;
        return raiz;
    }
}



int main(){

    NoArvore *raiz = NULL; 

    raiz = inserirAVL(raiz, 10);
    inserirAVL(raiz, 20);
    inserirAVL(raiz, 30);
    inserirAVL(raiz, 40);
    inserirAVL(raiz, 50);
    inserirAVL(raiz, 60);
    inserirAVL(raiz, 70);
    inserirAVL(raiz, 80);



    exibirArvore(raiz);

}
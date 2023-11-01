#include <iostream>

using namespace std;

struct NoArvore{
	int data; 
	NoArvore *left;
	NoArvore *right;
};

/*
struct ElementoPilha{
	int data;
	ElementoPilha* next;
};
*/

struct ElementoPilha{
	NoArvore* data; 
	ElementoPilha* next;
};

void exibirArvore(NoArvore *raiz){
	if(raiz == NULL){
		return;
	}
	cout << raiz -> data <<" "; 
	exibirArvore(raiz -> left);
	exibirArvore(raiz -> right);
}

void exibirArvorePar(NoArvore *raiz){
	if(raiz == NULL){
		return;
	}
	if(raiz -> data % 2 == 0){ 
		cout << raiz -> data << " ";
	}
	exibirArvorePar(raiz -> left);
	exibirArvorePar(raiz -> right);
}

void exibirArvoreImpar(NoArvore *raiz){
	if(raiz == NULL){
		return;
	}
	if(raiz -> data % 2 != 0){
		cout << raiz -> data << " ";
	}
	exibirArvoreImpar(raiz -> left);
	exibirArvoreImpar(raiz -> right);
}

void destruirArvore(NoArvore *&raiz){
	if(raiz != NULL){
		destruirArvore(raiz -> left);
		destruirArvore(raiz -> right);
		raiz = NULL;
		delete raiz;
	}
}

int contaNoArvore(NoArvore *raiz){
	int contador = 0;
	if (raiz != NULL){
		contador ++;
		contador += contaNoArvore(raiz -> left);
		contador += contaNoArvore(raiz -> right);
		
	}
	return contador;
}

int somaNoArvore(NoArvore *raiz){
	int soma = 0;
	if (raiz != NULL){
		soma += raiz -> data;
		soma += somaNoArvore(raiz -> left);
		soma += somaNoArvore(raiz -> right);
		
	}	
	return soma; 
}

int mediaNoArvore(NoArvore *raiz){
	int media = 0;
	if (raiz != NULL){
		media = somaNoArvore(raiz) / contaNoArvore(raiz);
	}
	return media;
}

void empilhaNo(ElementoPilha *topo, NoArvore *raiz){
	ElementoPilha *elemento = new ElementoPilha;
	elemento -> data = raiz -> data;
	elemento -> next = topo;
	
	topo = raiz;
}

void desempilhaNo(ElementoPilha *topo){
	if (topo = NULL){
		cout << "Erro Fatal";
		exit(1);
	} else {
		ElementoPilha *aux = new ElementoPilha;
		aux = topo;
		
		topo = topo -> next;
		delete aux;
	}
}

//para fazer a preOrdem (raiz -> esquerda -> direita), precisa empilhar o inverso na pilha direita, esquerda, raiz
int preOrdem(NoArvore *raiz){
	if (raiz != NULL){
		cout << raiz -> data << " ";
		empilhaNo(raiz, raiz);
	}
}

int main(){
	NoArvore *raiz = new NoArvore;
	raiz -> data = 2;
	raiz -> left = NULL; 
	raiz -> right = NULL;
	
	NoArvore *no1 = new NoArvore;
	no1 -> data = 7;
	no1 -> left = NULL; 
	no1 -> right = NULL;
	
	NoArvore *no2 = new NoArvore;
	no2 -> data = 5;
	no2 -> left = NULL; 
	no2 -> right = NULL;
	
	NoArvore *no3 = new NoArvore;
	no3 -> data = 2;
	no3 -> left = NULL; 
	no3 -> right = NULL;
	
	NoArvore *no4 = new NoArvore;
	no4 -> data = 6;
	no4 -> left = NULL; 
	no4 -> right = NULL;
	
	NoArvore *no5 = new NoArvore;
	no5 -> data = 5;
	no5 -> left = NULL; 
	no5 -> right = NULL;
	
	NoArvore *no6 = new NoArvore;
	no6 -> data = 11;
	no6 -> left = NULL; 
	no6 -> right = NULL;
	
	NoArvore *no7 = new NoArvore;
	no7 -> data = 9;
	no7 -> left = NULL; 
	no7 -> right = NULL;

	NoArvore *no8 = new NoArvore;
	no8 -> data = 4;
	no8 -> left = NULL; 
	no8 -> right = NULL;
	
	raiz -> left = no1;
	raiz -> right = no2;
	no1 -> left = no3;
	no1 -> right = no4;
	no4 -> left = no5;
	no4 -> right = no6;
	no2 -> right = no7;
	no7 -> left = no8;
	
	exibirArvore(raiz);
	cout << endl;
	exibirArvorePar(raiz);
	cout << endl;
	exibirArvoreImpar(raiz);
	cout << endl;
	cout << "Quantidade de nos:" << contaNoArvore(raiz);
	cout << endl;
	cout << somaNoArvore(raiz) << endl << endl;	
	cout << mediaNoArvore(raiz) << endl;
	
	return 0;
	
}

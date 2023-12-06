#include <iostream> 
using namespace std;

struct NoArvore {
    int key;
    NoArvore *left;
    NoArvore *right;
    int bf;
};

NoArvore *inserirArvore(NoArvore *&raiz, int chave){
	if (raiz == NULL) {
		NoArvore *novoNo = new NoArvore;
		novoNo -> key = chave;
		novoNo -> left = NULL;
		novoNo -> right = NULL;
		novoNo -> bf = 0;
		raiz = novoNo;
		return raiz;
	} else if (chave < raiz -> key){
		return inserirArvore(raiz -> left, chave);
	} else if (chave > raiz -> key){
		return inserirArvore(raiz -> right, chave);
	} else {
		cout << "chave existente" << endl;
	}
    return raiz;
};

void emOrdem(NoArvore* raiz){
    if (raiz != NULL){
         emOrdem(raiz -> left);
         cout << raiz -> key << " ";
         emOrdem(raiz -> right);
    }
};

void posOrdem(NoArvore* raiz){
    if (raiz != NULL){
         posOrdem(raiz -> left);
         posOrdem(raiz -> right);
         cout << raiz -> key << " ";
    }
};

bool comparaArvore(NoArvore* raiz1, NoArvore* raiz2){
    if (raiz1 == NULL){
        if (raiz2 != NULL){
            return false;
        }
        return true;
    } 
    
    if (raiz1 -> key == raiz2 -> key){
        return comparaArvore(raiz1 -> left, raiz2 -> left) && comparaArvore(raiz1 -> right, raiz2 -> right);
    }
    return false;
};

int alturaArvore(NoArvore *raiz){
	if (raiz!= NULL){
		if (raiz -> left == NULL && raiz -> right == NULL){
			return 0;
		} else if (raiz -> left != NULL && raiz -> right != NULL){
			if (alturaArvore(raiz -> right) >= alturaArvore(raiz -> left)){
				return 1 + alturaArvore(raiz -> right);
			}else{
				return 1 + alturaArvore(raiz -> left);
			}
		} else if (raiz -> left != NULL){
			return 1 + alturaArvore(raiz -> left);
		} else {
			return 1 + alturaArvore(raiz -> right);
		}
	}
};

bool somaFolhaIgualRaiz(NoArvore *raiz){
    if (raiz != NULL){
        if (raiz -> key == (raiz -> left -> key) + (raiz -> right -> key))
            return true; 
        else {
            return false;
        } 
    }
};

bool igualArvore(NoArvore *raiz1, NoArvore *raiz2){
    if (raiz1 != NULL){
        if (raiz2 == NULL){
            return false;
        }
        return true;
    }
    if (raiz1 -> key == raiz2 -> key){
        return igualArvore(raiz1 -> left, raiz2 -> left) && igualArvore(raiz1 -> right, raiz2 -> right);
    }
    return false;
};

void atualizaBF(NoArvore *raiz){
	if (raiz != NULL){
		raiz -> bf = alturaArvore(raiz -> left) - alturaArvore(raiz -> right);
		atualizaBF(raiz -> left);
		atualizaBF(raiz -> right);
	}
};

bool confereBalanceamento(NoArvore *raiz){
	atualizaBF(raiz);
	if (raiz != NULL){
		return (raiz -> bf < 2 && raiz -> bf > -2) && confereBalanceamento(raiz -> left) && confereBalanceamento(raiz -> right);
	} else {
		return true;
	}
};

NoArvore *rotacaoD(NoArvore *raiz){
	if (raiz != NULL && raiz -> left != NULL){
		NoArvore *aux = raiz;
		raiz = raiz -> right;
		aux -> left = NULL;
		if (raiz -> right != NULL){
			aux -> left = raiz -> right;
		}
		raiz -> right = aux;
	}
	return raiz;
};

NoArvore *rotacaoE(NoArvore *raiz){
	if (raiz != NULL && raiz -> right != NULL){
		NoArvore *aux = raiz;
		raiz = raiz -> right;
		aux -> right = NULL;
		if (raiz -> left != NULL){
			aux -> right = raiz -> left;
		}
		raiz -> left = aux;	
	}
	return raiz;
};

NoArvore *rotacaoDD(NoArvore *raiz){
	if (raiz != NULL && raiz -> left != NULL){
		rotacaoE(raiz -> left);
		return rotacaoD(raiz);
	}
};

NoArvore *rotacaoDE(NoArvore *raiz){
	if (raiz != NULL && raiz -> right != NULL){
		rotacaoD(raiz -> right);
		return rotacaoE(raiz);
	}
};

NoArvore *balanceiaAVL(NoArvore *raiz){
	if (raiz != NULL){
		balanceiaAVL(raiz -> left);
		balanceiaAVL(raiz -> right);
		atualizaBF(raiz);
		if (raiz -> bf > 1){
			if (raiz -> left -> bf >= 0){
				return rotacaoD(raiz);
			} else {
				return rotacaoDD(raiz);
			}
		} else if (raiz -> bf < -1){
			if (raiz -> right -> bf <= 0){
				return rotacaoE(raiz);
			} else {
				return rotacaoDE(raiz);
			}
		}
		return raiz;
	}
};

void balancearArvore(NoArvore *raiz){
	while (confereBalanceamento(raiz) != true){
		raiz =  balanceiaAVL(raiz);
		atualizaBF(raiz);
	}
};

bool confereBST(NoArvore *raiz){
	if (raiz != NULL){
		if (raiz -> left == NULL && raiz -> right == NULL){
			return true;
		} else if (raiz -> left == NULL){
			if (raiz -> left -> key >= raiz -> key){
				return false;
			}
			return confereBST(raiz-> left);
		} else if (raiz -> left == NULL){
			if (raiz -> right -> key <= raiz -> key){
				return false;
			}
			return confereBST(raiz-> right);
		} else {
			if (raiz -> right -> key <= raiz -> key || raiz -> left -> key >= raiz -> key){
				return false;
			}
			return confereBST(raiz -> left) && confereBST(raiz -> right);
		}
	} else {
		return true;
	}
};

void inverteArvore(NoArvore *raiz){
	if (raiz != NULL){
		NoArvore *aux = raiz -> right;
		raiz -> right = raiz -> left;
		raiz -> left = aux;

		inverteArvore(raiz -> left);
		inverteArvore(raiz -> right);
	}
};

int somaFolhas(NoArvore *raiz){
    if (raiz != NULL){
        if (raiz -> left != NULL && raiz -> right != NULL){
            return raiz -> key + (somaFolhas(raiz -> left)) + (somaFolhas(raiz -> right));
        }
    }
};

int somaNo(NoArvore *raiz){
    if (raiz != NULL){
        return raiz -> key + (somaNo(raiz -> left)) + (somaNo(raiz -> right));
        }
};

int maiorSubArvore(NoArvore *raiz){
    int somaE;
    int somaD;
    if (raiz != NULL){
        somaE = somaNo(raiz -> left);
        somaD = somaNo(raiz -> right);
        if (somaE > somaD){
            cout << "A maior Subarvore eh a da esquerda, sendo sua soma: " << endl;
            return somaE;
        }   
        if (somaD > somaE){
            cout << "A maior Subarvore eh a da direita, sendo sua soma: " << endl;
            return somaD;
        }
    }
};

NoArvore *transformaVetor(int vetor[], int n){
    NoArvore* raiz = NULL;
    for (int i; i < n; i++){
        inserirArvore(raiz, i);
    }
};

NoArvore *maiorNoBST(NoArvore *raiz){
    if (raiz != NULL){
        if (raiz -> right != NULL){
            return maiorNoBST(raiz -> right);
        }
    } else {
        return raiz;
    }
};

NoArvore *menorNoBST(NoArvore *raiz){
    if (raiz != NULL){
        if (raiz -> left != NULL){
            return menorNoBST(raiz -> left);
        }
    } else {
        return raiz;
    }
};

void buscaNaBST(NoArvore *raiz, int valor){
    if (raiz != NULL){
        if (valor > raiz -> key) {
            buscaNaBST(raiz -> right, valor);
        } else if (valor < raiz -> key){
            buscaNaBST(raiz -> left, valor);
        } else {
            cout << "O valor foi encontrado." << endl;
        }
    } else {
        cout << "O valor nao foi encontrado ou a raiz eh invalida" << endl;
    } 
};

int main(){

    //Arvore Principal
	NoArvore *raiz1 = NULL;

	inserirArvore(raiz1, 10);
	inserirArvore(raiz1, 20);
	inserirArvore(raiz1, 30);
	inserirArvore(raiz1, 40);
	inserirArvore(raiz1, 50);
	inserirArvore(raiz1, 60);
	inserirArvore(raiz1, 70);
    inserirArvore(raiz1, 80);
    inserirArvore(raiz1, 90);
    inserirArvore(raiz1, 100);


	//Arvore Teste
	NoArvore *raiz2 = NULL;

	inserirArvore(raiz2, 1);
	inserirArvore(raiz2, 3);
	inserirArvore(raiz2, 5);
	inserirArvore(raiz2, 7);
	inserirArvore(raiz2, 9);


	//Arvore Simples
	NoArvore *raiz3 = NULL;

	inserirArvore(raiz3, 5);
	inserirArvore(raiz3, 10);
	inserirArvore(raiz3, 15);


    // Questão 1 
    cout << "Questao 1: ";
    emOrdem(raiz1);
    cout << endl;

    // Questão 2
    cout << "Questao 2: ";
    cout << "Arvore 1 e 2 sao iguais?: " << comparaArvore(raiz1, raiz3);
    cout << endl;

    // Questão 3 e 4
    cout << "Questao 3 e 4: ";
    posOrdem(raiz1);
    cout << endl;

    // Questão 6 e 7
    cout << "Questao 6 e 7: ";
    cout << alturaArvore(raiz1);
    cout << endl;

    // Questão 8
    cout << "Questao 8: ";
    cout << confereBalanceamento(raiz1);
    cout << endl;

    // Questão 9
    cout << "Questao 9: ";
    emOrdem(raiz2);
    cout << endl;
    balancearArvore(raiz2);
    cout << endl;


    // Questão 10
    cout << "Questao 10: ";
    cout << confereBST(raiz1);
    cout << endl;

    // Questão 11
    cout << "Questao 11: ";
    emOrdem(raiz1);
    cout << endl;
    inverteArvore(raiz1);
    cout << endl;
    emOrdem(raiz1);
    cout << endl;
    inverteArvore(raiz1);
    cout << endl;

    // Questão 13
    cout << "Questao 13: ";
    cout << somaFolhaIgualRaiz(raiz3);
    cout << endl;

    // Questão 15
    cout << "Questao 15: ";
    cout << somaFolhas(raiz1);
    cout << endl;

    // Questão 17
    cout << "Questao 17: ";
    cout << maiorSubArvore(raiz2);
    cout << endl;

    // Questão 18
    int vetor[5] = {1, 2, 3, 4, 5};
    cout << "Questao 18: ";
    cout << endl;
    NoArvore *raiz4 = transformaVetor(vetor, 5);
    cout << endl;
    emOrdem(raiz4);
    cout << endl;

    // Questão 19
    cout << "Questao 19: ";
    cout << maiorNoBST(raiz2);
    cout << endl;

    // Questão 20
    cout << "Questao 20: ";
    cout << menorNoBST(raiz2);
    cout << endl;

    // Questão 21
    cout << "Questao 21: ";
    buscaNaBST(raiz1, 7);
    cout << endl;

};
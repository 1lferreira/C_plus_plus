#include <iostream>

using namespace std;

struct NoArvore{
	int data;
	NoArvore *left;
	NoArvore *right;
};


void exibirArvore(NoArvore *raiz){
	if(raiz != NULL){
		cout << raiz -> data << " ";
		exibirArvore(raiz -> left);
		exibirArvore(raiz -> right);
	}
}


int alturaArvore(NoArvore *raiz){
	if(raiz!= NULL){
		if(raiz -> left == NULL && raiz -> right == NULL){
			return 0;
		}else if(raiz -> left != NULL && raiz -> right != NULL){
			if(alturaArvore(raiz -> right) >= alturaArvore(raiz -> left)){
				return 1 + alturaArvore(raiz -> right);
			}else{
				return 1 + alturaArvore(raiz -> left);
			}
		}else if(raiz -> left != NULL){
			return 1 + alturaArvore(raiz -> left);
		}else{
			return 1 + alturaArvore(raiz -> right);
		}
	}
}


bool arvoreCheia(NoArvore *raiz){
	if(raiz != NULL){
		if(raiz -> left == NULL && raiz -> right == NULL){
			return true;
		}else if(raiz -> left != NULL && raiz -> right != NULL){
			return arvoreCheia(raiz -> left) && arvoreCheia(raiz -> right);
		}else{
			return false;
		}
	}
}


bool arvorePerfeita(NoArvore *raiz){
	if(raiz != NULL){
		if(raiz -> left == NULL && raiz -> right == NULL){
			return true;
		}else if(raiz -> left != NULL && raiz -> right != NULL){
			return (arvorePerfeita(raiz -> left) == arvorePerfeita(raiz -> right) && arvorePerfeita(raiz -> left) && arvorePerfeita(raiz -> right));
		}else{
			return false;
		}
	}
}


bool arvoreCompleta(NoArvore *raiz){
	if(raiz == NULL){
		return true;
	} else if(raiz -> left != NULL && raiz -> right != NULL){
		int diferencaEsqDir = alturaArvore(raiz -> left) - alturaArvore(raiz -> right);
		bool esquerdaPreenchida = true;
		if(raiz -> right -> left != NULL && raiz -> left -> right == NULL){
			esquerdaPreenchida = false;
		}
		return(diferencaEsqDir <= 1 && diferencaEsqDir >= 0) && arvoreCompleta(raiz -> left) && arvoreCompleta(raiz -> right) && esquerdaPreenchida;
	}else if(raiz -> right == NULL){
		return alturaArvore(raiz) <= 1;
	}else{
		return false;
	}
}


bool arvoreBalanceada(NoArvore *raiz){
	if(raiz != NULL){
		if(raiz -> left == NULL && raiz -> right == NULL){
			return true;
		} else if(raiz -> left != NULL && raiz -> right != NULL){
			int diferencaAltura;
			if(alturaArvore(raiz -> left) - alturaArvore(raiz -> right) >= alturaArvore(raiz -> right) - alturaArvore(raiz -> left)){
				diferencaAltura = alturaArvore(raiz -> left) - alturaArvore(raiz -> right);
			}else{
				diferencaAltura = alturaArvore(raiz -> right) - alturaArvore(raiz -> left);
			}
			return (diferencaAltura <= 1 && arvoreBalanceada(raiz -> left) && arvoreBalanceada(raiz -> right));
		}else{
			return(alturaArvore(raiz) <= 1);
		}
	}
}


bool arvoreDegenerada(NoArvore *raiz){
	if(raiz != NULL){
		if(raiz -> left != NULL && raiz -> right != NULL){
			return false;
		}
		else if(raiz -> left != NULL){
			return arvoreDegenerada(raiz -> left);
		}else if(raiz -> right != NULL){
			return arvoreDegenerada(raiz -> right);
		}else{
			return true;
		}
	}
}


bool arvoreDistorcida(NoArvore *raiz){
	if(raiz != NULL){
		if(raiz -> left != NULL && raiz -> right != NULL){
			return false;
		}
		else if(raiz -> left != NULL){
			if(raiz -> left -> right != NULL){
				return false;
			}
			return arvoreDistorcida(raiz -> left);
		}else if(raiz -> right != NULL){
			if(raiz -> right -> left != NULL){
				return false;
			}
			return arvoreDistorcida(raiz -> right);
		}else{
			return true;
		}	
	}
}


int main() {

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
	
	NoArvore *no9 = new NoArvore;
	no9 -> data = 3;
	no9 -> left = NULL;
	no9 -> right = NULL;
	
	NoArvore *no10 = new NoArvore;
	no10 -> data = 11;
	no10 -> left = NULL;
	no10 -> right = NULL;
	
	raiz -> left = no1;
	raiz -> right = no2;
	no1 -> left = no3;
	no1 -> right = no4;
	no4 -> left = no5;
	no4 -> right = no6;
	no2 -> right = no7;
	no2 -> left = no9;
	no7 -> left = no8;
	no7 -> right = no10;
	
	exibirArvore(raiz);

	cout << boolalpha << endl;
	cout << "Arvore cheia? " << arvoreCheia(raiz);
	cout << endl;
	cout << "Altura da arvore: " << alturaArvore(raiz);
	cout << endl;
	cout << "Arvore perfeita? " << arvorePerfeita(raiz);
	cout << endl;
	cout << "Arvore completa? " << arvoreCompleta(raiz);
	cout << endl;
	cout << "Arvore balanceada? " << arvoreBalanceada(raiz);
	cout << endl;
	cout << "Arvore degenerada? " << arvoreDegenerada(raiz);
	cout << endl;
	cout << "Arvore distorcida? " << arvoreDistorcida(raiz);
	cout << endl;
	
	NoArvore *raizDeg = new NoArvore;
	raizDeg -> data = 2;
	raizDeg -> left = NULL;
	raizDeg -> right = NULL;
	
	NoArvore *no1Deg = new NoArvore;
	no1Deg -> data = 7;
	no1Deg -> left = NULL;
	no1Deg -> right = NULL;
	
	NoArvore *no2Deg = new NoArvore;
	no2Deg -> data = 5;
	no2Deg -> left = NULL;
	no2Deg -> right = NULL;
	
	NoArvore *no3Deg = new NoArvore;
	no3Deg -> data = 2;
	no3Deg -> left = NULL;
	no3Deg -> right = NULL;
	
	raizDeg -> left = no1Deg;
	no1Deg -> left = no2Deg;
	no2Deg -> left = no3Deg;
	
	exibirArvore(raizDeg);

	cout << endl;
	cout << "Arvore degenerada? " << arvoreDegenerada(raizDeg);
	cout << endl;
	cout << "Arvore distorcida? " << arvoreDistorcida(raizDeg);
	cout << endl;

}
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//UEMA - UNIVERSIDADE ESTADUAL DO MARANH�O 
//ENGENHARIA DA COMPUTA��O 

//ESTRUTURA M�E DA �RVORE
typedef struct arvore{
	struct arvore *esquerda;
	struct arvore *direita;
	int info;
}arv;
//ESTRUTURA DO ELEMENTO R�IZ
typedef struct{
	arv *raiz;
}arvb;
//FUN��ES DA �RVORE
void inserir(arvb *a, int valor);
void inserir_esq(arv *a, int valor);
void inserir_dir(arv *a, int valor);
void imprimir(arv *three);
void sair_do_programa();
//FUN��O MAIN 

int main() {
	setlocale(LC_ALL,"Portuguese");
//SE��O DE VARI�VEIS DENTRO DA MAIN 
int op, valor;
arvb arvore_inicial;
arvore_inicial.raiz = NULL;
do{
	system("cls");
	printf("\nBEM VINDO AO CONSTRUTOR DE �RVORE BIN�RIAS!!");
	printf("\n============================================");
	printf("\nDigite ( 1 ) para inserir um elemento na �rvore.");
	printf("\nDigite ( 2 ) para ler os elementos da �rvore.");
	printf("\nDigite ( 0 ) para sair do construtor.");
	printf("\n=============================================");
	printf("\nRESPOSTA:");
	scanf("%d", &op);
		switch(op){
		case 1:
			printf("\nDigite o valor a ser inserido na �rvore:");
			scanf("%d", &valor);
			inserir(&arvore_inicial,valor);
		break;
		case 2:
			printf("\n============================");
			printf("\nELEMENTOS DA �RVORE BIN�RIA:");
			imprimir(arvore_inicial.raiz);
			printf("\n==========================\n");
			
			system("pause");
		break;
		case 0:
			sair_do_programa();
		break;	
		}
	}while(op != 0);
	return 0;
}
//FUN��O PARA INSERIR ELEMENTOS NA ESQUERDA DE UM N� 
void inserir_esq(arv *a, int valor){
	if(a->esquerda == NULL){
		arv *novo = (arv *) malloc(sizeof(arv));
		novo->info = valor;
		novo->esquerda = NULL;
		novo->direita = NULL;
		a->esquerda = novo;		
	}else{
/*OBS: UTILIZA-SE RECURS�O NESSE C�DIGO!!!*/
		if(valor<a->esquerda->info){
			inserir_esq(a->esquerda, valor);
		}else{
		inserir_dir(a->esquerda, valor);
		}
	}
}
//FUN��O PARA INSERIR ELEMENTOS NA DIREITA DE UM N�
void inserir_dir(arv *a, int valor){
	if(a->direita == NULL){
		arv *novo = (arv *) malloc(sizeof(arv));
		novo->info = valor;
		novo->esquerda = NULL;
		novo->direita = NULL;
		a->direita = novo;
	}else{
		if(valor>a->esquerda->info){
			inserir_dir(a->direita, valor);
		}else{
		}	inserir_esq(a->direita,valor);
	}
}
void inserir(arvb *a, int valor){
/*Esta primeira condicional insere o elemento ra�z na fun��o//INICIO DE TUDO*/
	if(a->raiz == NULL){
		arv *novo = (arv *)malloc(sizeof(arv));
		novo->info = valor;
		novo->esquerda = NULL;
		novo->direita = NULL;
		a->raiz = novo; 	
	}else{
/*Esta segunda condicional insere o pr�ximo valor considerando que j� tem um 
elemento na estrutura(ra�z), desse modo, esta vai colocar o pr�ximo elemento 
no n� esquerda ( < )*/ 
		if(valor < a->raiz->info){
			inserir_esq(a->raiz, valor);
		}else{
		inserir_dir(a->raiz, valor);
		}
	}
}
void imprimir(arv *three){
	if(three != NULL){
		printf("\n%d", three->info);
		imprimir(three->esquerda);
		imprimir(three->direita);
	}
}
void sair_do_programa(){
	system("cls");
	printf("\nOBRIGADO POR USAR O CONSTRUTOR DE �RVORES BIN�RIAS!");
	printf("\n \n \n");
	printf("\nAt� mais :D");
}

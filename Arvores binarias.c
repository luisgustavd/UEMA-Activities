#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
//UEMA - UNIVERSIDADE ESTADUAL DO MARANHÃO 
//ENGENHARIA DA COMPUTAÇÃO 

//ESTRUTURA MÃE DA ÁRVORE
typedef struct arvore{
	struct arvore *esquerda;
	struct arvore *direita;
	int info;
}arv;
//ESTRUTURA DO ELEMENTO RÁIZ
typedef struct{
	arv *raiz;
}arvb;
//FUNÇÕES DA ÁRVORE
void inserir(arvb *a, int valor);
void inserir_esq(arv *a, int valor);
void inserir_dir(arv *a, int valor);
void imprimir(arv *three);
void sair_do_programa();
//FUNÇÃO MAIN 

int main() {
	setlocale(LC_ALL,"Portuguese");
//SEÇÃO DE VARIÁVEIS DENTRO DA MAIN 
int op, valor;
arvb arvore_inicial;
arvore_inicial.raiz = NULL;
do{
	system("cls");
	printf("\nBEM VINDO AO CONSTRUTOR DE ÁRVORE BINÁRIAS!!");
	printf("\n============================================");
	printf("\nDigite ( 1 ) para inserir um elemento na árvore.");
	printf("\nDigite ( 2 ) para ler os elementos da árvore.");
	printf("\nDigite ( 0 ) para sair do construtor.");
	printf("\n=============================================");
	printf("\nRESPOSTA:");
	scanf("%d", &op);
		switch(op){
		case 1:
			printf("\nDigite o valor a ser inserido na árvore:");
			scanf("%d", &valor);
			inserir(&arvore_inicial,valor);
		break;
		case 2:
			printf("\n============================");
			printf("\nELEMENTOS DA ÁRVORE BINÁRIA:");
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
//FUNÇÃO PARA INSERIR ELEMENTOS NA ESQUERDA DE UM NÓ 
void inserir_esq(arv *a, int valor){
	if(a->esquerda == NULL){
		arv *novo = (arv *) malloc(sizeof(arv));
		novo->info = valor;
		novo->esquerda = NULL;
		novo->direita = NULL;
		a->esquerda = novo;		
	}else{
/*OBS: UTILIZA-SE RECURSÃO NESSE CÓDIGO!!!*/
		if(valor<a->esquerda->info){
			inserir_esq(a->esquerda, valor);
		}else{
		inserir_dir(a->esquerda, valor);
		}
	}
}
//FUNÇÃO PARA INSERIR ELEMENTOS NA DIREITA DE UM NÓ
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
/*Esta primeira condicional insere o elemento raíz na função//INICIO DE TUDO*/
	if(a->raiz == NULL){
		arv *novo = (arv *)malloc(sizeof(arv));
		novo->info = valor;
		novo->esquerda = NULL;
		novo->direita = NULL;
		a->raiz = novo; 	
	}else{
/*Esta segunda condicional insere o próximo valor considerando que já tem um 
elemento na estrutura(raíz), desse modo, esta vai colocar o próximo elemento 
no nó esquerda ( < )*/ 
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
	printf("\nOBRIGADO POR USAR O CONSTRUTOR DE ÁRVORES BINÁRIAS!");
	printf("\n \n \n");
	printf("\nAté mais :D");
}

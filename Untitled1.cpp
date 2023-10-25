#include <stdio.h>
#include <stdlib.h>

struct no {
	int numero;
	struct no *anterior;
	struct no *proximo;
};

struct no *cabeca = NULL;

void inserir(int numero){
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> anterior = NULL;
	novoNo -> proximo = NULL;
	if (cabeca == NULL) {
		cabeca = novoNo;
	}else {
		struct no *ponteiro = cabeca;
	//procura o ultimo no da lista
		while (ponteiro -> proximo != NULL) {
			ponteiro = ponteiro -> proximo;
		}
		//executa os apontamenstos
		ponteiro -> proximo = novoNo;
		novoNo -> anterior = ponteiro;
	}
}

void imprimir() {
	struct no *ponterio = cabeca;
	while (ponterio != NULL) {
		printf("%d\n", ponterio -> numero);
		ponterio = ponterio -> proximo;
	}
	
	printf("=======\n");
}

void remover(int numero) {
 struct no *ponterio = cabeca;
 while (ponterio != NULL) {
 	if (ponterio -> numero == numero) {
 		if (ponterio -> anterior == NULL) {
 			cabeca = cabeca -> proximo;
 			if (cabeca != NULL) {
 				cabeca -> anterior = NULL;
			 }
 			free(ponterio);
 			ponterio = cabeca;
		 } else if (ponterio -> proximo == NULL) {
		 	struct no *temp = ponterio;
		 	ponterio = ponterio -> anterior;
		 	ponterio -> proximo = NULL;
		 	free(temp);
		 }else {
		 	struct no *temp = ponterio;
		 	ponterio = ponterio-> anterior;
		 	temp -> anterior -> proximo = temp -> proximo;
		 	temp -> proximo -> anterior = temp -> anterior;
		 	free(temp);
		 }
	 }
	 if (ponterio != NULL) {
	 	ponterio = ponterio -> proximo;
	 }
	 
 }	
}

int main() {
	imprimir();
	inserir(1);
	remover(1);
	imprimir();
	inserir(1);
	inserir(2);
	inserir(3);
	inserir(4);
	inserir(5);
	remover(1);
	remover(5);
	remover(3);
	imprimir();
}

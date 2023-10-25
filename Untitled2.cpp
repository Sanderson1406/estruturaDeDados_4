#include <stdio.h>
#include <stdlib.h>

struct no {
	int numero;
	struct no *anterior;
	struct no *proximo;
};

struct no *cabeca = NULL;
void inserir(int numero) {
	struct no *novoNo = (struct no *) malloc(sizeof(struct no));
	novoNo -> numero = numero;
	novoNo -> proximo = cabeca;
	
	if (cabeca == NULL) {
		cabeca = novoNo;
		novoNo -> proximo = cabeca;
	} else {
		struct no *ponterio = cabeca;
		while (ponterio -> proximo != cabeca) {
			ponterio = ponterio -> proximo;
		}
		ponterio -> proximo = novoNo;
	}
}

void imprimir() {
	struct no *ponterio = cabeca;
		if (ponterio != NULL) {
			while(1) {
				printf("%d\n", ponterio -> numero);
		    	ponterio = ponterio -> proximo;
				if (ponterio == cabeca) {
					break;
				}
			}
		}
	printf("=======\n");
}

void remover(int numero){
	if (cabeca != NULL) {
		if (cabeca -> numero == numero) {
			if (cabeca -> proximo == cabeca) {
				free(cabeca);
				cabeca = NULL;
			}else {
				struct no *ponterioExcluir = cabeca;
				cabeca = cabeca -> proximo;
				struct no *ponterioAnterior = cabeca;
				while (ponterioAnterior -> proximo != ponterioExcluir) {
					ponterioAnterior = ponterioAnterior -> proximo;
				}
				ponterioAnterior -> proximo = cabeca;
				free(ponterioExcluir);
			}
		}else {
			struct no *ponterioAnterior = cabeca;
			while ((ponterioAnterior -> proximo != cabeca) && (ponterioAnterior -> proximo -> numero != numero)) {
				ponterioAnterior = ponterioAnterior -> proximo;
			}
			if (ponterioAnterior -> proximo != cabeca) {
				struct no *ponterioExcluir = ponterioAnterior -> proximo;
				ponterioAnterior -> proximo = ponterioExcluir -> proximo;
				free(ponterioExcluir);
			}
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
	remover(3);
	imprimir();
}

#include "pilha.hpp"

void FPVazia(Pilha *p){
	p->base = (Block*) malloc (sizeof(Block));
	p->top  = p->base;
	p->base->prox = NULL;
}

void Push(Pilha *p, Item d){
	Block *aux = (Block*) malloc (sizeof(Block));
	aux->data = d;
	aux->prox = p->top;
	p->top = aux;
}

void Pop(Pilha *p, Item *d){
	Block *aux;

	if(p->base == p->top || p == NULL){
		printf("PILHA VAZIA!\n");
		return;
	}
	
	aux = p->top;
	p->top = aux->prox;
	*d = aux->data;
	free(aux);
}


void PImprime(Pilha *p){
	Block *aux;

	aux = p->top;
	while(aux != p->base){
		printf("%d %d\n", aux->data.x, aux->data.y);
		aux = aux->prox;
	}

}

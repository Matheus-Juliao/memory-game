#ifndef QUEUE_LETTERS_H_INCLUDED
#define QUEUE_LETTERS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Create data structure for Node
struct no {
	int elem;
	struct no *next;
};

// Check if the stack is empty
int empty(struct no *t) {
	if (t == NULL){
		return 1;
	} else {
		return 0;
	}
}


// Insert node on stack
void push(int valor, struct no **t) {
	struct no *next;
	next = (struct no *) malloc (sizeof(struct no));
	next->elem = valor;
	if( (*t) == NULL ){
		(*t) = next;
		(*t)->next = NULL;
	} else {
		next->next = (*t);
		(*t)=next;
	}
}

// List the stack
int query(struct no *t, char *storedString) {
	int size = strlen(storedString);
	int numberLetter;
	if (t == NULL){
		printf("Pilha Vazia \n");
		return -1;
	} else {
		do {
			for(int i = 0; i < size; i++) {
				numberLetter = storedString[i];
				if(numberLetter == t->elem) {
					t = t->next;
				} else {
					return 0;
				}
			}
		} while(t != NULL);
		return 1;
	}
}

// Show List the stack
void showAndClearStack(struct no *t, struct no **tt) {
	struct no *aux;
	do {
		printf("%c", t->elem);
		t = t->next;
		aux = (*tt);
		(*tt)=(*tt)->next;
		free(aux);
	} while(t != NULL);
	printf("\n\n");
}

#endif // QUEUE_LETTERS_H_INCLUDED
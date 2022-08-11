#ifndef QUEUE_LETTERS_H_INCLUDED
#define QUEUE_LETTERS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_STRINGS 100

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
	int cont = 0;
	int result;
	if (t == NULL){
		printf("Pilha Vazia \n");
		return 1;
	} else {
		do {
			result = 0;
			cont++;
			if(result == 0) {
				t = t->next;
				if(cont == size) {
					
				}
			}	else {
					return 1;
				}
		} while(t != NULL);
		return 0;
	}
}

#endif // QUEUE_LETTERS_H_INCLUDED
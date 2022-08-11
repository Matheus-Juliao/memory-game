#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "queue_letters.h"
#define NUM_STRINGS 100

char chooseLetter();
void userPlayMenu();
int generateRandomLetter();
void computerPlayMenu(int numberLetter);
void userRepeatSequenceMenu();
void compareSequence(int cont, struct no *top);

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Create Stack data structure
    struct no *top = NULL;
    // Variables
    int numberLetter, start=1, cont=0, points=0;
    //int x;

    while(start == 1) {
        userPlayMenu();
        numberLetter = chooseLetter();
        push(numberLetter, &top);
        cont++;
        system("cls");

        numberLetter = generateRandomLetter();
        push(numberLetter, &top);
        cont++;
        computerPlayMenu(numberLetter);
        system("cls");

        userRepeatSequenceMenu();
        compareSequence(cont, top);
        points += 10;
    } 
    
    printf("\n\n\n\n");
}

char chooseLetter() {
    char letter;
    scanf("%c", &letter);
    fflush(stdin);

    return letter;
}

void userPlayMenu() {
    printf("\t\t\tJogo de memoria\n");
    printf("\t\t\t***GENIUS C***\n\n");
    printf("\t\t\t***Usuario Joga***\n\n");
    printf("\t\t   Informe uma letra entre A e Z: ");
}

void computerPlayMenu(int numberLetter) {
    printf("\t\t\tJogo de memoria\n");
    printf("\t\t\t***GENIUS C***\n\n");
    printf("\t\t\t***Programa Joga***\n\n");
    printf("\t\t   Letra selecionada pelo programa: %c\n\n", numberLetter);
    printf("\t\t   Voce tem 3 segundos para memorizar!");
    Sleep(3000);
}

void userRepeatSequenceMenu() {
    printf("\t\t\tJogo de memoria\n");
    printf("\t\t\t***GENIUS C***\n\n");
    printf("\t\t\t***Usuario Repete a Sequencia***\n\n");
    printf("\t\tInforme a sequencia de letras ate o momento iniciando\n\t\tpela ultima letra informada ate a primeira: ");
}

int generateRandomLetter() {
    srand(time(NULL));
    int letter=0;
    letter = 65 + (rand()%26);

    return letter;
}

void compareSequence(int cont, struct no *top) {
    char typedSequence[cont];
    int status;
    scanf("%s", typedSequence);
    status = query(top, typedSequence);
    if(status == 0) {
        printf("\n\t\t     Certa a sequencia! Ganhou 10 pontos!");
        system("pause>NULL");
    } else{
        printf("errou");
        system("pause>NULL");
    }
    
}
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include "queue_letters.h"

char chooseLetter();
void userPlayMenu();
void computerPlayMenu(int numberLetter);
void userRepeatSequenceMenu();
void gameOverMenu();
void showPoints(int points);
int generateRandomLetter();
int compareSequence(int cont, struct no *top, int points);

int main() {
    setlocale(LC_ALL, "Portuguese");

    // Create Stack data structure
    struct no *top = NULL;
    // Variables
    int numberLetter, start=1, cont=0, points=0;

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
        points = compareSequence(cont, top, points);
        system("cls");
        if(points == -1) {
            start = 0;
        }
    }
}

char chooseLetter() {
    char letter;
    scanf("%c", &letter);
    fflush(stdin);

    return letter;
}

void userPlayMenu() {
    printf("                                                                     ______________________________\n");
    printf("\t\t\t                                                     Jogo de memória\n");
    printf("\t\t\t                                                      ***GENIUS C***\n");
    printf("                                                                     ______________________________\n");
    printf("\n");
    printf("\t\t\t                                                     ***Usuário Joga***\n\n");
    printf("\t\t                                                      Informe uma letra entre A e Z: ");
}

void computerPlayMenu(int numberLetter) {
    printf("                                                                     ______________________________\n");
    printf("\t\t\t                                                     Jogo de memória\n");
    printf("\t\t\t                                                      ***GENIUS C***\n\n");
    printf("                                                                     ______________________________\n");
    printf("\t\t\t                                                    ***Programa Joga***\n\n");
    printf("\t\t                                                    Letra selecionada pelo programa: %c\n\n", numberLetter);
    printf("\t\t                                                   Você tem 3 segundos para memorizar!");
    Sleep(3000);
}

void userRepeatSequenceMenu() {
    printf("                                                                     ______________________________\n");
    printf("\t\t\t                                                     Jogo de memória\n");
    printf("\t\t\t                                                      ***GENIUS C***\n\n");
    printf("                                                                 ________________________________________\n");
    printf("\t\t\t                                             ***Usuário Repete a Sequencia***\n\n");
    printf("\t\t                                          Informe a sequência de letras até o momento iniciando\n");
    printf("\t\t                                               pela última letra informada até a primeira: ");
}

void gameOverMenu() {
    printf("                                                                     ______________________________\n");
    printf("\t\t\t                                                     Jogo de memória\n");
    printf("\t\t\t                                                      ***GENIUS C***\n\n");
    printf("                                                                     ______________________________\n");
    printf("\t\t\t                                                    ***Final de Jogo***\n\n");
    printf("\t\t                                              A sequência de letras até o momento foi: ");

}

void showPoints(int points) {
    printf("\t\t                                                    A sua pontuação foi: %d pontos!\n", points);
}

int generateRandomLetter() {
    srand(time(NULL));
    int letter=0;
    letter = 65 + (rand()%26);

    return letter;
}

int compareSequence(int cont, struct no *top, int points) {
    char typedSequence[cont];
    int status;
    scanf("%s", typedSequence);
    fflush(stdin);
    //printf("%d", typedSequence[0]);
    status = query(top, typedSequence);
    if(status == 1) {
        printf("\n\t\t                                                       Sequência certa! Ganhou 10 pontos!");
        points += 10;
        Sleep(3000);
    } else {
        if(status == 0) {
            printf("\n\t\t                                                       Sequência errada! Fim de Jogo!");
            Sleep(3000);
            system("cls");
            gameOverMenu();
            showAndClearStack(top, &top);
            showPoints(points);
            system("PAUSE");
            points = -1;
        }
        points += 0;
    }

    return points;
}
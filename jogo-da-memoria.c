#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Portuguese");
    //printf("Hello World");

    char opcao[1];

    printf("Adivinhe a letra: ");
    scanf("%s", &opcao);
    if(strcmp(opcao, "X") == 0) {
       //opcao[0] = 'x';
       printf("Letra correta");
    } else {
        printf("Letra errada");
    }
}
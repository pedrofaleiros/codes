/* 
2) Faça um programa que leia do usuário 10 números inteiros 
e armazene os números pares em uma lista ligada
e os números ímpares em uma segunda lista ligada. 
Mostre o conteúdo das 2 listas; 
*/

// pronto
#include "lista_ligada.h"

int main()
{
    lista * pares, * impares;
    int i = 0, num;

    pares = aloca_lista();
    impares = aloca_lista();

    for(; i < 10; i++){
        printf("\n numero> ");
        scanf("%d", &num);
        if(num % 2 == 0)
            inclui_no_final(pares, num);
        else
            inclui_no_final(impares, num);
    }

    printf("\n pares:");
    mostra_lista(pares);

    printf("\n impares:");
    mostra_lista(impares);

    printf("\n");
    return 0;
}
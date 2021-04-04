/* 
3) Faça um programa que leia do usuário um número N inteiro positivo 
e solicite ao usuário N números para serem armazenados.
    a primeira metade dos N números, deverá ser armazenada em uma lista ligada 
    e a segunda metade dos N números deverá ser 
    armazenado em uma segunda lista.
    Mostre na tela quais valores são comuns entre as 2 listas ligadas. 
*/

// pronto
#include "lista_ligada.h"

void mostra_iguais(lista * l1, lista * l2);

int main()
{
    lista *l1, *l2;
    int n, num;

    l1 = aloca_lista();
    l2= aloca_lista();

    printf("\n numero n> ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("\n numero> ");
        scanf("%d", &num);
        if(i < (n/2)){
            inclui_no_final(l1, num);
        }else{
            inclui_no_final(l2, num);
        }
    }

    printf("\n elementos iguais:");
    mostra_iguais(l1, l2);

    printf("\n");
    return 0;
}

void mostra_iguais(lista * l1, lista * l2)
{
    if(l1->inicio && l2->inicio){
        elemento * aux1, * aux2;
        aux1 = l1->inicio;

        while(aux1){
            aux2 = l2->inicio;
            while(aux2){
                if(aux2->valor == aux1->valor){
                    printf("\n %d", aux1->valor);
                    break;
                }
                aux2 = aux2->prox;
            }
            aux1 = aux1->prox;
        }

    }else{
        printf("\n list vazia");
    }
}
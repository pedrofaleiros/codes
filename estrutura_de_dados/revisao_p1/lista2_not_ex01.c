/* 
1 ) Faça um programa que receba do usuário um número N 
e preencha 2 listas ligadas com N números aleatórios.
    Depois de preenchida as 2 listas, 
    remova os números em comum das 2 listas 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct elemento{
    int valor;
    struct elemento * prox;
}elemento;

typedef struct lista{
    int qtd;
    struct elemento * inicio;
}lista;

lista * aloca_lista();
elemento * aloca_elemento();
void mostra_lista(lista * l);
void remove_iguais(lista * l1, lista * l2);
void remove_elemento(lista * l, int num);
void inclui_ordenado(lista * l, int num);

int main()
{
    srand(time(NULL));

    int n, n1, n2;
    lista * l1, * l2;

    l1 = aloca_lista();
    l2 = aloca_lista();

    printf("\n n: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        n1 = rand()%10 + 1;
        n2 = rand()%10 + 1;
        inclui_ordenado(l1, n1); 
        inclui_ordenado(l2, n2);
    }


    printf("\n");
    return 0;
}



void mostra_lista(lista * l)
{
    if(l->inicio){
        elemento * aux;
        aux = l->inicio;

        while(aux){
            printf("\n> %d", aux->valor);
            aux = aux->prox;
        }
    }else{
        printf("\n lista vazia");
    }
}

elemento * aloca_elemento()
{
    elemento * novo;
    novo = (elemento*)malloc(sizeof(elemento));
    novo->valor = 0;
    novo->prox = NULL;
    return novo;    
}

lista * aloca_lista()
{
    lista * nova;
    nova = (lista*)malloc(sizeof(lista));
    nova->qtd = 0;
    nova->inicio = NULL;
    return nova;    
}
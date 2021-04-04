/* 
3 ) Em analogia a estrutura de lista ligada, 
faça um programa que insira números em uma lista duplamente ligada. 
*/

// pronto
#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int valor;
    struct elemento * ant;
    struct elemento * prox;
}elemento;

typedef struct lista{
    int qtd;
    struct elemento * inicio;   
    struct elemento * fim;
}lista;

lista * aloca_lista();
elemento * aloca_elemento();
void inclui_ordenado(lista * l, int num);
void mostra_lista(lista * l);

int main()
{   
    lista * l;
    l = aloca_lista();

    inclui_ordenado(l, 9);
    inclui_ordenado(l, 8);
    inclui_ordenado(l, 14);
    inclui_ordenado(l, 5);
    inclui_ordenado(l, 7);
    inclui_ordenado(l, 3);
    inclui_ordenado(l, 12);
    inclui_ordenado(l, 2);
    inclui_ordenado(l, 1);

    mostra_lista(l);

    printf("\n");
    return 0;
}

void mostra_lista(lista * l)
{
    if(l->inicio){
        elemento * aux;
        aux = l->inicio;

        while(aux){
            printf("\n %d", aux->valor);
            aux = aux->prox;
        }
    }else{
        printf("\n lista vazia");
    }
}

void inclui_ordenado(lista * l, int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio == NULL){
        l->inicio = novo;
        l->fim = novo;
    }else{
        elemento * aux;
        aux = l->inicio;

        while(aux->prox != NULL && aux->valor < num)
            aux = aux->prox;
        
        if(aux->valor >= num){
            if(aux->ant == NULL){
                l->inicio = novo;
            }else{
                novo->ant = aux->ant;
                aux->ant->prox = novo;
            }
            novo->prox = aux;
            aux->ant = novo;
        }else{
            aux->prox = novo;
            novo->ant = aux;
            l->fim = novo;
        }
    }
    l->qtd++;
}

elemento * aloca_elemento()
{
    elemento * novo;
    novo = (elemento*)calloc(1, sizeof(elemento));
    return novo;
}

lista * aloca_lista()
{
    lista * nova;
    nova = (lista*)calloc(1, sizeof(lista));
    return nova;
}
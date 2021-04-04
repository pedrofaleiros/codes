#include <stdio.h>
#include <stdlib.h>

#define VAZIA printf("\nlista vazia");

typedef struct elemento{
    int valor;
    struct elemento * prox;
}elemento;

typedef struct lista{
    int qtd;
    struct elemento * inicio;
}lista;

elemento * aloca_elemento();
lista * aloca_lista();
void inclui_ordenado(lista * l, int num);
void mostra_lista(lista * l);
void remove_elemento(lista *l, int num);

void inclui_ordenado(lista * l, int num)
{
    elemento * novo;

    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio != NULL)
    {
        elemento * aux, * ant = NULL;

        aux = l->inicio;

        while(aux->prox && aux->valor < num){
            ant = aux;
            aux = aux->prox;
        }

        if(aux->valor >= num){
            if(ant != NULL)
                ant->prox = novo;
            else
                l->inicio = novo;

            novo->prox = aux;   
        }else{
            aux->prox = novo;
        }

    }else{
        l->inicio = novo;
    }
    l->qtd++;
}

void remove_elemento(lista *l, int num)
{
    if(l->inicio != NULL){
        elemento * aux, * ant = NULL;

        aux = l->inicio;

        while(aux->prox && aux->valor != num){
            ant = aux;
            aux = aux->prox;
        }

        if(aux->valor == num){
            if(ant != NULL){
                ant->prox = aux->prox;
            }else{
                l->inicio = aux->prox;
            }
            printf("numero removido");
            free(aux);
            l->qtd--;
        }else{
            printf("numero nao esta na lista");
        }

    }else{
        VAZIA;
    }
}

lista * aloca_lista()
{
    lista * nova_lista;

    nova_lista = (lista*)malloc(sizeof(lista));
    nova_lista->qtd = 0;
    nova_lista->inicio = NULL;

    return nova_lista;
}

elemento * aloca_elemento()
{
    elemento * novo_elemento;

    novo_elemento = (elemento*)malloc(sizeof(elemento));
    novo_elemento->valor = 0;
    novo_elemento->prox = NULL;

    return novo_elemento;
}

void mostra_lista(lista * l)
{
    if(l->inicio != NULL){
        elemento * aux;

        aux = l->inicio;

        printf("\nelementos:");
        while(aux != NULL)
        {
            printf("\n> %d", aux->valor);
            aux = aux->prox;
        }
    }else{
        VAZIA;
    }
}
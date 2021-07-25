#include <stdio.h>
#include <stdlib.h>

typedef struct elemento
{
    int valor;
    struct elemento * prox;
}elemento;

typedef struct lista
{
    int qtd;
    struct elemento * inicio;
}lista;

void inclui_no_final(lista * l, int num);
void inclui_no_inicio(lista * l, int num);
void mostra_lista(lista * l);
void inclui_ordenado(lista * l, int num);
int remove_ultimo_elemento(lista * l);
int remove_elemento(lista * l, int num);
lista * aloca_lista();
elemento * aloca_elemento();

int main()
{
    lista * numeros;

    numeros = aloca_lista();

    mostra_lista(numeros);

    inclui_no_final(numeros, 1);
    inclui_no_final(numeros, 3);
    inclui_no_final(numeros, 5);

    remove_ultimo_elemento(numeros);
    
    mostra_lista(numeros);

    printf("\n");
    return 0;
}

int remove_ultimo_elemento(lista * l)
{
    int num;

    if(l->inicio == NULL)
        num = -1;
    else{
        elemento * aux, * ant;

        ant = NULL;
        aux = l->inicio;

        while(aux->prox){
            ant = aux;
            aux = aux->prox;
        }

        if(ant == NULL){
            num = l->inicio->valor;
            free(aux);
            l->inicio = NULL;
        }else{
            num = aux->valor;
            ant->prox = NULL;
            free(aux);
        }

        l->qtd--;
    }

    return num;
}

void mostra_lista(lista * l)
{
    if(l->inicio != NULL){
        elemento * aux;
        aux = l->inicio;

        while(aux != NULL){
            printf("\n %d", aux->valor);
            aux = aux->prox;
        }
    }else
        printf("\n lista vazia");
}

void inclui_no_inicio(lista * l, int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio == NULL)
        l->inicio = novo;
    else{
        novo->prox = l->inicio;
        l->inicio = novo;
    }

    l->qtd++;
}

void inclui_no_final(lista * l, int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio == NULL)
        l->inicio = novo;
    else{
        elemento * aux;
        aux = l->inicio;

        while(aux->prox != NULL)
            aux = aux->prox;

        aux->prox = novo;
    }

    l->qtd++;
}

lista * aloca_lista()
{
    lista * nova;
    nova = calloc(1, sizeof(lista));
    return nova;
}

elemento * aloca_elemento()
{
    elemento * novo;
    novo = calloc(1, sizeof(elemento));
    return novo;
}
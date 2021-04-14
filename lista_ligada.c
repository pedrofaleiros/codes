#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int valor;
    struct elemento * prox;
}elemento;

typedef struct Lista{
    struct elemento * inicio;
    void (*inclui)(struct Lista*, int);
    void (*mostra)(struct Lista*);
    void (*remove)(struct Lista*, int);
}Lista;

Lista * aloca_lista();
elemento * aloca_elemento();
void construtor(Lista * lista);
void mostra_lista(Lista * l);
void inclui_elemento(Lista * l, int num);
void remove_elemento(Lista * l, int num);

int main()
{
    Lista * l;
    l = aloca_lista();
    construtor(l);

    l->inclui(l, 1);
    l->inclui(l, 2);
    l->inclui(l, 3);
    l->inclui(l, 4);

    l->remove(l, 1);
    l->remove(l, 2);

    l->inclui(l, 5);
    l->inclui(l, 6);

    l->mostra(l);

    printf("\n");
    return 0;
}

void inclui_elemento(Lista * l, int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio != NULL)
    {
        elemento * aux, * ant;

        ant = NULL;
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
}

void remove_elemento(Lista * l, int num)
{
    if(l->inicio != NULL){
        elemento * aux, * ant;
        
        ant = NULL;
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
            free(aux);
        }

    }
}

void mostra_lista(Lista * l)
{
    if(l->inicio == NULL){
        printf("\n lista vazia");
    }else{
        elemento * aux;
        aux = l->inicio;

        while(aux){
            printf("\n> %d", aux->valor);
            aux = aux->prox;
        }
    }
}

void construtor(Lista * lista)
{
    lista->inicio = NULL;
    lista->inclui = inclui_elemento;
    lista->remove = remove_elemento;
    lista->mostra = mostra_lista;
}

Lista * aloca_lista()
{
    Lista * nova;
    nova = (Lista*)calloc(1, sizeof(Lista));
    return nova;
}
elemento * aloca_elemento()
{
    elemento * novo;
    novo = (elemento*)calloc(1, sizeof(elemento));
    return novo;
}
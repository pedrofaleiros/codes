#include <stdio.h>
#include <stdlib.h>

typedef struct lista_dupla{
    int qtd;
    struct elemento * inicio;
    struct elemento * fim;
}lista_dupla;

typedef struct elemento{
    int valor;
    struct elemento * prox;
    struct elemento * ant;
}elemento;

lista_dupla * aloca_lista()
{
    lista_dupla * nova;

    nova = (lista_dupla*)malloc((sizeof(lista_dupla)));
    nova->qtd = 0;
    nova->inicio = NULL;
    nova->fim = NULL;

    return nova;
}

elemento * aloca_elemento()
{
    elemento * novo;

    novo = (elemento*)malloc((sizeof(elemento)));
    novo->valor = 0;
    novo->prox = NULL;
    novo->ant = NULL;

    return novo;
}

void inclui(lista_dupla *l, int num)
{
    elemento * novo;

    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio){
        elemento * aux;

        aux = l->inicio;

        while(aux->prox){
            aux = aux->prox;
        }

        aux->prox = novo;
        novo->ant = aux;
        l->fim = novo;

    }else{
        l->inicio = novo;
        l->fim = novo;
    }
    l->qtd++;
}

void mostra_lista(lista_dupla *l)
{
    if(l->inicio){
        elemento * aux;
        aux = l->inicio;

        while(aux){
            printf("\n> %d", aux->valor);
            aux = aux->prox;
        }

    }else{
        printf("\nLista vazia\n");
    }
}

void mostra_lista_inverso(lista_dupla *l)
{
    if(l->inicio){
        elemento * aux;
        aux = l->fim;

        while(aux){
            printf("\n> %d", aux->valor);
            aux = aux->ant;
        }
    }else{
        printf("\nLista vazia\n");
    }
}

void inclui_ordenado(lista_dupla *l, int num);

int main()
{
    lista_dupla * l;
    int num;

    l = aloca_lista();

    while(num){
        printf("\nNum: ");
        scanf("%d", &num);

        if(num) inclui_ordenado(l, num);
    }

    printf("\nLista:");
    mostra_lista(l);

    printf("\n\ninvertido:");
    mostra_lista_inverso(l);

    return 0;
}

void inclui_ordenado(lista_dupla *l, int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio){
        elemento * aux;

        aux = l->inicio;

        while(aux->prox && aux->valor < num){
            aux = aux->prox;
        }

        if(aux->valor > num){
            if(aux->ant){
                novo->prox = aux;
                novo->ant = aux->ant;
                aux->ant->prox = novo;
                aux->ant = novo;
            }else{
                l->inicio = novo;
                novo->prox = aux;
                aux->ant = novo;
            }
        }else{
            //inclui no final
            aux->prox = novo;
            novo->ant = aux;
            l->fim = novo;
        }

    }else{
        l->inicio = novo;
        l->fim = novo;
    }
    l->qtd++;
}
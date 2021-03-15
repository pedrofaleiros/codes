#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int qtd;
    struct elemento *inicio;
}lista;

typedef struct elemento{
    int valor;
    struct elemento *prox;
}elemento;

lista* aloca_lista();
elemento* aloca_elemento();
void inclui_elemento(lista *l, int x);
void inclui_ordenado(lista *l, int n);
void mostra_valores_iguais(lista *l1, lista *l2);

int main()
{
    int n, i = 0, x;
    lista *lista1, *lista2;

    lista1 = aloca_lista();
    lista2 = aloca_lista();

    printf("Numero N: ");
    scanf("%d", &n);

    float num = n;
    
    for(;i < n; i++)
    {
        printf("Numero: ");
        scanf("%d", &x);

        if(i < num/2){
            inclui_ordenado(lista1, x);
        }else{
            inclui_ordenado(lista2, x);
        }
    }

    mostra_valores_iguais(lista1, lista2);

    return 0;
}

void inclui_ordenado(lista *l, int n)
{
    elemento * novo;

    novo = aloca_elemento();
    novo->valor = n;

    if(l->inicio){
        elemento *aux = NULL, *ant = NULL;

        aux = l->inicio;

        while(aux)
        {
            if(aux->valor > n){
                ant = aux;
                aux = aux->prox;
            }else{
                if(ant){
                    novo->prox = aux;
                    ant->prox = novo;
                }else{
                    l->inicio = novo;
                    novo->prox = aux;
                }
                l->qtd += 1;
                return;
            }
        }

    }else{
        l->inicio = novo;
    }
}

void mostra_valores_iguais(lista *l1, lista *l2)
{
    int achou_igual = 0;

    printf("\nElementos em comum:\n");
    if(l1->inicio && l2->inicio){
        elemento *aux1, *aux2;

        aux1 = l1->inicio;

        while(aux1)
        {
            aux2 = l2->inicio;
            while(aux2)
            {
                if(aux1->valor == aux2->valor)
                {
                    printf("> %d\n", aux1->valor);
                    achou_igual = 1;
                }
                aux2 = aux2->prox;
            }
            aux1 = aux1->prox;
        }

    }else{
        printf("\nUma lista esta vazia\n");
        exit(0);
    }

    if(!achou_igual){
        printf("\nNenhum elemento em comum\n");
    }
}

lista* aloca_lista()
{
    lista *nova;

    nova = (lista*)malloc(sizeof(lista));
    nova->qtd = 0;
    nova->inicio = NULL;

    return nova;
}

elemento* aloca_elemento()
{
    elemento *novo;

    novo = (elemento*)malloc(sizeof(elemento));
    novo->valor = 0;
    novo->prox = NULL;

    return novo;
}

void inclui_elemento(lista *l, int x)
{
    elemento *novo;

    novo = aloca_elemento();

    novo->valor = x;

    if(l->inicio){
        elemento *aux;

        aux = l->inicio;

        while(aux->prox)
        {
            aux = aux->prox;
        }

        aux->prox = novo;
    }else{
        l->inicio = novo; 
    }

    l->qtd += 1;
}

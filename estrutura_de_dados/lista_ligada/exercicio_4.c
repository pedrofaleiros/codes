/* 
4) Ajuste a solução do exercício 3 para que a pesquisa de números em comuns seja feita utilizando o algoritmo Balance-Line.
    Dicas: A inserção na lista precisa ser ordenada! 
    PRA AGORA

 */

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
void mostra_valores_iguais(lista *l1, lista *l2);

int main()
{
    int n, i, x;
    lista * lista1, *lista2;

    lista1 = aloca_lista();
    lista2 = aloca_lista();

    printf("Numero N: ");
    scanf("%d", &n);

    float num = n;

    for(i = 0;i < n; i++)
    {
        printf("Numero: ");
        scanf("%d", &x);

        if(i < num/2){
            inclui_elemento(lista1, x);
        }else{
            inclui_elemento(lista2, x);
        }
    }

    mostra_valores_iguais(lista1, lista2);

    return 0;
}

void mostra_valores_iguais(lista *l1, lista *l2)
{
    if(l1->inicio && l2->inicio){
        elemento * a1, * a2;
        int achou_igual = 0;

        a1 = l1->inicio;
        a2 = l2->inicio;

        printf("\nElementos em comum:\n");
        while(a1 && a2){
            if(a1->valor == a2->valor){
                printf("%d\n", a1->valor);
                a1 = a1->prox;
                a2 = a2->prox;
                achou_igual = 1;
            }else{
                if(a1->valor > a2->valor){
                    a2 = a2->prox;
                }else{
                    a1 = a1->prox;
                }
            }
        }

        if(!achou_igual){
            printf("Nenhum numero em comum\n");
        }

    }else{
        printf("\nLista vazia\n");
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
    elemento * novo;

    novo = aloca_elemento();
    novo->valor = x;

    if(l->inicio){
        elemento * aux, * ant;

        ant = NULL;
        aux = l->inicio;

        while(aux->prox){
            if(aux->valor > x){
                if(ant){
                    ant->prox = novo;
                }else{
                    l->inicio = novo;
                }
                novo->prox = aux;
                l->qtd += 1;
                return;
            }else{
                ant = aux;
                aux = aux->prox;
            }
        }

        aux->prox = novo;

    }else{
        l->inicio = novo;
    }
    l->qtd += 1;
}
/* 
4) Ajuste a solução do exercício 3 para que a pesquisa de números em comuns seja feita utilizando o algoritmo Balance-Line.
    Dicas: A inserção na lista precisa ser ordenada! 
    PRA AGORA

 */

//errado

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
void inclui_elemento(lista *l, int num);
void mostra_valores_iguais(lista *l1, lista *l2);

int main()
{
    int n, i, x;
    lista * lista1, * lista2;

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

void inclui_elemento(lista *l, int num)
{
    elemento * novo;

    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio){
        elemento * aux, * ant = NULL;

        aux = l->inicio;

        while(aux){
            if(aux->valor > num){
                if(ant == NULL){
                    l->inicio = novo;
                    novo->prox = aux;
                }else{
                    ant->prox = novo;
                    novo->prox = aux;
                }
                l->qtd++;
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
    l->qtd++;
    return;
}

void mostra_valores_iguais(lista *l1, lista *l2)
{
   printf("aaa\n");
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

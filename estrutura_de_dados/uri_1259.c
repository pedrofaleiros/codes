/* Considerando a entrada de valores inteiros não negativos, ordene estes valores segundo o seguinte critério:

    Primeiro os Pares
    Depois os Ímpares

Sendo que deverão ser apresentados os pares em ordem crescente e depois os ímpares em ordem decrescente.

A primeira linha de entrada contém um único inteiro positivo N (1 < N < 105)
Este é o número de linhas de entrada que vem logo a seguir.
As próximas N linhas conterão, cada uma delas, um valor inteiro não negativo.

ex:
10
4
32
34
543
3456
654
567
87
6789
98

*/
//time limit exceeded
#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int qtd;
    struct elemento * inicio;
    struct elemento * fim;
}lista;

typedef struct elemento{
    int valor;
    struct elemento * prox;
    struct elemento * ant;
}elemento;

void inclui_no_final(lista *l, int num);
void mostra_pares(lista *l);
void mostra_impares(lista *l);

int main()
{
    int n, num, i = 0;
    lista * pares, * impares;
    pares = (lista*)malloc(sizeof(lista));
    impares = (lista*)malloc(sizeof(lista));
    pares->qtd = impares->qtd = 0;
    pares->inicio = impares->inicio = NULL;

    scanf("%d", &n);

    for(; i < n; i++){
        scanf("%d", &num);
        if(num % 2 == 0){
            inclui_no_final(pares, num);
        }else{
            inclui_no_final(impares, num);
        }
    }

    mostra_pares(pares);
    mostra_impares(impares);

    return 0;
}

void mostra_impares(lista *l)
{
    if(l->inicio){
        elemento * aux;

        aux = l->fim;

        while(aux){
            printf("%d\n", aux->valor);
            aux = aux->ant;
        }
    }
}

void mostra_pares(lista *l)
{
    if(l->inicio){
        elemento * aux;

        aux = l->inicio;

        while(aux){
            printf("%d\n", aux->valor);
            aux = aux->prox;
        }
    }
}

void inclui_no_final(lista *l, int num)
{
    elemento * novo;
    novo = (elemento*)malloc(sizeof(elemento));
    novo->valor = num;
    novo->prox = NULL;

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

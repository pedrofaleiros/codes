/* 
4) Ajuste a solução do exercício 3 para que 
a pesquisa de números em comuns seja feita utilizando o 
algoritmo Balance-Line.
    Dicas: A inserção na lista precisa ser ordenada!  
*/

// pronto
#include <stdio.h>
#include <stdlib.h>

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
void inclui_ordenado(lista * l, int num);
void mostra_iguais(lista * l1, lista * l2);

int main()
{
    lista *l1, *l2;
    int n, num;

    l1 = aloca_lista();
    l2= aloca_lista();

    printf("\n numero n> ");
    scanf("%d", &n);

    float nn = n/2;
    for(int i = 0; i < n; i++){
        printf("\n numero> ");
        scanf("%d", &num);
        if(i < nn){
            inclui_ordenado(l1, num);
        }else{
            inclui_ordenado(l2, num);
        }
    }

    printf("\n elementos iguais:");
    mostra_iguais(l1, l2);

    printf("\n");
    return 0;
}

void mostra_iguais(lista * l1, lista * l2)
{
    if(l1->inicio && l2->inicio){
        elemento * aux1, * aux2;

        aux1 = l1->inicio;
        aux2 = l2->inicio;

        while(aux1 && aux2){
            if(aux1->valor == aux2->valor){
                printf("\n %d", aux1->valor);
                aux1 = aux1->prox;
                aux2 = aux2->prox;
            }else if(aux1->valor > aux2->valor){
                aux2 = aux2->prox;
            }else{
                aux1 = aux1->prox;
            }
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

    if(l->inicio){
        elemento * aux, * ant;
        ant = NULL;
        aux = l->inicio;

        while(aux->prox && aux->valor < num){
            ant = aux;
            aux = aux->prox;
        }

        if(aux->valor > num){
            if(ant != NULL){
                ant->prox = novo;
            }else{
                l->inicio = novo;
            }
            novo->prox = aux;
        }else{
            aux->prox = novo;
        }
    }else{
        l->inicio = novo;
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
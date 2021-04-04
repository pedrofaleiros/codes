/* 
1 ) Faça um programa que receba do usuário um número N 
e preencha 2 listas ligadas com N números aleatórios.
    Depois de preenchida as 2 listas, 
    remova os números em comum das 2 listas 
*/

// pronto
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
void mostra_lista(lista * l);
void remove_iguais(lista * l1, lista * l2);
void remove_elemento(lista * l, int num);
void inclui_ordenado(lista * l, int num);

int main()
{
    srand(time(NULL));

    int n, num;
    lista * l1, * l2;

    l1 = aloca_lista();
    l2 = aloca_lista();

    printf("\n n: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        num = rand()%10 + 1;
        inclui_ordenado(l1, num); 
        num = rand()%10 + 1;
        inclui_ordenado(l2, num);
    }

    printf("\n lista 1:");
    mostra_lista(l1);

    printf("\n lista 2:");
    mostra_lista(l2);

    remove_iguais(l1, l2);

    printf("\n lista 1:");
    mostra_lista(l1);

    printf("\n lista 2:");
    mostra_lista(l2);

    printf("\n");
    return 0;
}

void remove_elemento(lista * l, int num)
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
            if(ant == NULL){
                l->inicio = aux->prox;
            }else{
                ant->prox = aux->prox;
            }
            l->qtd--;
        }
    }
}

void remove_iguais(lista * l1, lista * l2)
{
    if(l1->inicio && l2->inicio){
        elemento * a1, * a2;

        a1 = l1->inicio;
        a2 = l2->inicio;

        while(a1 && a2){
            if(a1->valor == a2->valor){
                remove_elemento(l1, a1->valor);
                remove_elemento(l2, a1->valor);
                a1 = a1->prox;
                a2 = a2->prox;
            }else if(a1->valor > a2->valor){
                a2 = a2->prox;
            }else{
                a1 = a1->prox;
            }
        }
    }
}

void inclui_ordenado(lista * l, int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio == NULL){
        l->inicio = novo;
    }else{
        elemento * aux, * ant;

        ant = NULL;
        aux = l->inicio;

        while(aux->prox && aux->valor <= num){
            ant = aux;
            aux = aux->prox;
        }

        if(aux->valor >= num){
            if(ant == NULL){
                l->inicio = novo;
            }else{
                ant->prox = novo;
            }
            novo->prox = aux;
        }else{
            aux->prox = novo;
        }
    }
}

void mostra_lista(lista * l)
{
    if(l->inicio){
        elemento * aux;
        aux = l->inicio;

        while(aux){
            printf("\n> %d", aux->valor);
            aux = aux->prox;
        }
    }else{
        printf("\n lista vazia");
    }
}

elemento * aloca_elemento()
{
    elemento * novo;
    novo = (elemento*)malloc(sizeof(elemento));
    novo->valor = 0;
    novo->prox = NULL;
    return novo;    
}

lista * aloca_lista()
{
    lista * nova;
    nova = (lista*)malloc(sizeof(lista));
    nova->qtd = 0;
    nova->inicio = NULL;
    return nova;    
}
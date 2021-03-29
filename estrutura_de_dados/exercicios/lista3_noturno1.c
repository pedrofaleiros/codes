/*
1) utilizando como base a solucao_lista2_exercicio3.c construa as seguintes funções para uma lista duplamente ligada:
    1 - Remover Primos
    2 - Remover numeros iguais
    3 - Buscar por numero
    4 - Comparar 2 listas ( falar os numeros iguais e quais sao diferentes)
    5 - incluir de forma ordenada
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int valor;
    struct elemento * ant;
    struct elemento * prox;
}elemento;

typedef struct lista{
    int qtd;
    struct elemento * inicio;
    struct elemento * fim;
}lista;

elemento * aloca_elemento();
lista * aloca_lista();
void inclui_ordenado(lista * l, int num);
int busca(lista * l, int num);
void comparar_listas(lista * l1, lista * l2);
void remover_numero(lista * l, int num);
void remover_primos(lista * l);
void remover_iguais(lista * l1, lista * l2);
int menu();
void mostra_lista(lista * l);

int main()
{
    lista * l1, * l2;
    int n, num;

    l1 = aloca_lista();
    l2 = aloca_lista();

    printf("\nNumero n: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        printf("\nnum: ");
        scanf("%d", &num);
        if(i < n/2)
            inclui_ordenado(l1, num);
        else
            inclui_ordenado(l2, num);
    }

    int opcao = 1;
    while(opcao){
        opcao = menu();

        printf("\nlista 1:");
        mostra_lista(l1);

        printf("\nlista 2:");
        mostra_lista(l2);

        if(opcao == 1){
            remover_primos(l1);
            remover_primos(l2);
        }else if(opcao == 2){
            remover_iguais(l1, l2);
        }else if(opcao == 3){
            comparar_listas(l1, l2);
        }
    }

    return 0;
}

int menu()
{
    int opcao;
    printf("\n1 - remover primos");
    printf("\n2 - remover iguais");
    printf("\n3 - comparar listas");
    printf("\nopcao: ");
    scanf("%d", &opcao);
    return opcao;
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

void remover_iguais(lista * l1, lista * l2)
{
    if(l1->inicio && l2->inicio){
        elemento * aux;
        aux = l1->inicio;

        while(aux){
            if(busca(l2, aux->valor)){
                remover_numero(l1, aux->valor);
                remover_numero(l2, aux->valor);
            }else{
                aux = aux->prox;
            }
        }
    }
}

void comparar_listas(lista * l1, lista * l2)
{
    if(l1->inicio && l2->inicio){
        elemento * aux1;
        aux1 = l1->inicio;

        printf("\n valores iguais:");
        while(aux){
            if(busca(l2, aux->valor)){
                printf("\n> %d", aux->valor);
            }
        }
        
        aux1 = l1->inicio;

        printf("\n valores diferentes:");
        while(aux){
            if(!busca(l2, aux->valor)){
                printf("\n> %d", aux->valor);
            }
        }
    }
}

int busca(lista * l, int num)
{
    int ret = 0;

    if(l->inicio){
        elemento * aux;
        aux = l->inicio;

        while(aux && aux->valor >= num){
            if(aux->valor == num){
                ret = 1;
                break;
            }else{
                aux = aux->prox;
            }
        }
    }

    return ret;
}

void remover_primos(lista * l)
{
    if(l->inicio){
        elemento * aux;
        aux = l->inicio;

            if(verifica_primo(;
        while(aux){
                remover_numero;);
            if(verifica_primo(aux->valor)){
                remover_numero(l, aux->valor);
            }
            aux = aux->prox;
        }
    }
}

void remover_numero(lista * l, int num)
{
    if(l->inicio){
        elemento * aux;
        aux = l->inicio;

        while(aux->prox && aux->valor != num)
            aux = aux->prox;

        if(aux->valor == num){
            if(aux->ant){
                aux->ant->prox = aux->prox;
            }else{
                l->inicio = aux->prox;
            }

            if(aux->prox){
                aux->prox->ant = aux->ant;
            }else{
                l->fim = aux->ant;
            }

            l->qtd--;
            printf("\n removido: %d", aux->valor);
            free(aux);
        }else{
            printf("\n numero nao esta na lista");
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
        elemento * aux;
        aux = l->inicio;

        while(aux->prox && aux->valor < num)
            aux = aux->prox;

        if(aux->valor > num){
            novo->ant  = aux->ant;
            novo->prox = aux;
            aux->ant->prox = novo;
            aux->ant = novo;
        }else{
            novo->ant = aux;
            aux->prox = novo;
            l->fim = novo;
        }

    }else{
        l->inicio = novo;
        l->fim = novo;
    }
    l->qtd++;
}

lista * aloca_lista()
{
    lista * nova_lista;
    nova_lista = (lista*)calloc(1, sizeof(lista));
    return nova_lista;
}

elemento * aloca_elemento()
{
    elemento * novo_elemento;
    novo_elemento = (elemento*)calloc(1, sizeof(elemento));
    return novo_elemento;
}
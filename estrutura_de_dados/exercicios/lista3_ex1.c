/* 
1) Construa uma estrutura de lista duplamente ligada que permita as seguintes operações:
a) Incluir no inicio da lista
b) incluir no final da lista
c) mostrar lista
d) mostrar primos da lista
e) mostrar lista de tras pra frente
f) remover elemento da lista
g) remover primos da lista
*/
#include <stdio.h>
#include <stdlib.h>

#define not !
#define True 1
#define False 0
typedef int bool;

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

lista * aloca_lista();
elemento * aloca_elemento();
bool verifica_primo(int num);
void inclui_fim(lista * l, int num);
void inclui_inicio(lista * l, int num);
void mostra_lista(lista * l);
void mostra_lista_invertida(lista * l);
void mostra_primos_lista(lista * l);
void remove_elemento(lista *l, int num);
void remove_primos(lista *l);
int escolhe_opcao();

int main()
{
    lista * l;
    int opcao = 1, num;

    l = aloca_lista();
    
    while(opcao != 0)
    {
        opcao = escolhe_opcao();

        switch(opcao)
        {
            case 1:
                printf("\nnumero> ");
                scanf("%d", &num);
                inclui_inicio(l, num);
                break;
            case 2:
                printf("\nnumero> ");
                scanf("%d", &num);
                inclui_fim(l, num);
                break;
            case 3:
                mostra_lista(l); 
                break;
            case 4: 
                mostra_lista_invertida(l);
                break;
            case 5:
                mostra_primos_lista(l);
                break;
            case 6:
                printf("\nnumero> ");
                scanf("%d", &num);
                remove_elemento(l, num);
                break;
            case 7:
                remove_primos(l);
                break;
            case 0:
                break;
            default:
                printf("\n opcao invalida");
                break;
        }
    }
    
    return 0;
}

void remove_primos(lista * l)
{
    if(l->inicio != NULL){
        elemento * aux;
        aux = l->inicio;

        while(aux != NULL){
            if(verifica_primo(aux->valor)){
                remove_elemento(l, aux->valor);
            }
            aux = aux->prox;
        }
    }else{
        printf("\n lista vazia");
    }
}

void remove_elemento(lista *l, int num)
{
    if(l->inicio != NULL){
        elemento * aux;
        aux = l->inicio;

        while(aux->prox != NULL && aux->valor != num)
            aux = aux->prox;

        if(aux->valor == num){
            if(aux->ant != NULL){
                if(aux != l->fim){
                    aux->ant->prox = aux->prox;
                    aux->prox->ant = aux->ant;
                }else{
                    l->fim = aux->ant;
                    aux->ant->prox = NULL;
                }
            }else{
                if(aux != l->fim){
                    l->inicio = aux->prox;
                    aux->prox->ant = NULL;
                }else{
                    l->inicio = NULL;
                    l->fim = NULL;
                }
            }
            printf("\n removido: %d", aux->valor);
            free(aux);
            l->qtd--;
        }else{
            printf("\n numero nao esta na lista");
        }

    }else{
        printf("\n lista vazia");
    }
}

bool verifica_primo(int num)
{
    int i = 2, count = 0;

    for(; i <= num; i++){
        if(num % i == 0){
            count++;
        }
    }
    if(count == 1){
        return True;
    }else{
        return False;
    }
}

void mostra_primos_lista(lista * l)
{
    if(l->inicio != NULL){
        elemento * aux;
        bool tem_primo = False;

        aux = l->inicio;

        printf("\n> numeros primos:");
        while(aux != NULL){
            if(verifica_primo(aux->valor)){
                printf("\n %d", aux->valor);
                tem_primo = True;
            }
            aux = aux->prox;
        }
        if(not tem_primo)
            printf("\n nenhum numero primo na lista");
    }else{
        printf("\n lista vazia");
    }
}

void mostra_lista(lista * l)
{
    if(l->inicio != NULL){
        elemento * aux;
        aux = l->inicio;

        printf("\n> lista:");
        while(aux != NULL){
            printf("\n %d", aux->valor);
            aux = aux->prox;
        }
    }else{
        printf("\n lista vazia");
    }
}

void mostra_lista_invertida(lista * l)
{
    if(l->inicio != NULL){
        elemento * aux;
        aux = l->fim;

        printf("\n> lista invertida:");
        while(aux != NULL){
            printf("\n %d", aux->valor);
            aux = aux->ant;
        }
    }else{
        printf("\n lista vazia");
    }
}

void inclui_inicio(lista * l , int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio != NULL){
        elemento * aux;
        aux = l->inicio;

        aux->ant = novo;
        novo->prox = aux;
        l->inicio = novo;
    }else{
        l->inicio = novo;
        l->fim = novo;
    }
    l->qtd++;
}

void inclui_fim(lista * l, int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio != NULL){
        elemento * aux;
        aux = l->fim;

        aux->prox = novo;
        novo->ant = aux;
        l->fim = novo;
    }else{
        l->inicio = novo;
        l->fim = novo;
    }
    l->qtd++;
}

lista * aloca_lista()
{
    lista * nova;

    nova = (lista*)malloc(sizeof(lista));
    nova->qtd = 0;
    nova->inicio = NULL;
    nova->fim = NULL;
    
    return nova;
}

elemento * aloca_elemento()
{
    elemento * novo;

    novo = (elemento*)malloc(sizeof(elemento));
    novo->valor = 0;
    novo->ant = NULL;
    novo->prox = NULL;

    return novo;
}

int escolhe_opcao()
{
    printf("\n");
    printf("\n1 - incluir no inicio");
    printf("\n2 - incluir no final");
    printf("\n3 - mostrar lista");
    printf("\n4 - mostrar lista invertida");
    printf("\n5 - mostrar primos");
    printf("\n6 - remover numero");
    printf("\n7 - remover primos");
    printf("\n0 - sair");
    printf("\nopcao> ");

    int opcao;
    scanf("%d", &opcao);
    return opcao;
}
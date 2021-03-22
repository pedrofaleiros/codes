#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int valor;
    struct elemento * prox;
    struct elemento * ant;
}elemento;

typedef struct lista{
    int qtd;
    struct elemento * inicio;
    struct elemento * fim;
}lista;

int escolhe_opcao(){
    printf("\n1 - Incluir elemento no Inicio");
    printf("\n2 - Incluir elemento no Final");
    printf("\n3 - Mostrar elementos");
    printf("\n4 - Remover elemento");
    printf("\n0 - Sair");
    printf("\nOpcao: ");

    int opcao;
    scanf("%d", &opcao);
    return opcao;
}

lista * aloca_lista(){
    lista * nova;
    
    nova = (lista*)malloc(sizeof(lista));
    nova->qtd = 0;
    nova->inicio = NULL;
    nova->fim = NULL;

    return nova;
}

elemento * aloca_elemento(){
    elemento * novo;

    novo = (elemento*)malloc(sizeof(elemento));
    novo->valor = 0;
    novo->prox = NULL;
    novo->ant = NULL;

    return novo;
}

void inclui_elemento_final(lista * l){
    int num;
    printf("\nIncluir numero: ");
    scanf("%d", &num);

    elemento * novo, * aux;
    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio == NULL){
        l->inicio = novo;
        l->fim = novo;
    }else{
        aux = l->fim;

        l->fim = novo;
        aux->prox = novo;
        novo->ant = aux;
    }

    l->qtd += 1;
}

void inclui_elemento_inicio(lista * l){
    int num;
    printf("\nIncluir numero: ");
    scanf("%d", &num);

    elemento * novo, * aux;
    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio == NULL){
        l->inicio = novo;
        l->fim = novo;
    }else{
        aux = l->inicio;

        l->inicio = novo;
        aux->ant = novo;
        novo->prox = aux;
    }

    l->qtd += 1;
}

void mostra_elementos(lista * l){
    if(l->inicio == NULL){
        printf("\nLista vazia\n");
    }else{
        elemento * aux;

        aux = l->inicio;

        printf("\nElementos:");
        while(aux){
            printf("\n> %d", aux->valor);
            aux = aux->prox;
        }
    }
}

void remove_elemento(lista * l){
    int num;
    printf("\nRemover numero: ");
    scanf("%d", &num);

    if(l->inicio == NULL){
        printf("\nNumero nao encontrado\n");
    }else{
        elemento * aux;

        aux = l->inicio;

        while(aux->prox && aux->valor != num){
            aux = aux->prox;
        }

        if(aux->valor == num){
            if(l->qtd == 1){
                l->inicio = NULL;
                l->fim = NULL;
            }else if(l->inicio == aux){
                l->inicio = aux->prox;
                aux->prox->ant = NULL;
            }else if(l->fim == aux){
                l->fim = aux->ant;
                aux->ant->prox = NULL;
            }else{
                aux->ant->prox = aux->prox;
                aux->prox->ant = aux->ant;
            }

            printf("\nNumero removido\n");
            l->qtd -= 1;
        }else{
            printf("\nNumero nao encontrado\n");
        }
         
    }

}

int main()
{
    lista * l;
    int opcao;

    l = aloca_lista();

    void (*funcao[4])(lista * l);
    funcao[0] = inclui_elemento_inicio;
    funcao[1] = inclui_elemento_final;
    funcao[2] = mostra_elementos;
    funcao[3] = remove_elemento;

    do{
        opcao = escolhe_opcao();

        if(opcao){
            funcao[opcao-1](l);
        }
    }while(opcao != 0);

    return 0;
}
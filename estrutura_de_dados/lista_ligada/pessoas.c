#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<stdio_ext.h>

#define True 1
#define False 0
typedef int bool;

typedef struct pessoa{
    char * nome;
    char * email;
    int idade;
    struct pessoa * prox;
}pessoa;

typedef struct lista{
    int qtd;
    struct pessoa * inicio;
}lista;

void opcoes();
pessoa * aloca_pessoa();
lista * aloca_lista();
void cadastra_pessoa(lista *l);
void mostra_pessoas(lista *l);

int main(){

    lista * grupo;
    int opcao = True, num;

    grupo = aloca_lista();

    while(opcao){
        opcoes();
        scanf("%d", &opcao);

        if(opcao == 1){
            cadastra_pessoa(grupo);
        }else if(opcao == 2){
            mostra_pessoas(grupo);
        }else if(opcao == 3){
            //remove_pessoa(grupo);
            break;
        }

    }

    return 0;
}

void mostra_pessoas(lista *l)
{
    if(l->inicio){
        pessoa * aux;
        int i = 1;

        aux = l->inicio;

        printf("\nPessoas:\n");
        while(aux){
            printf("\n%d:\n", i);
            printf("\tNome: %s\n", aux->nome);
            printf("\tEmail: %s\n", aux->email);
            printf("\tIdade: %d\n", aux->idade);
            aux = aux->prox;
            i++;
        }

    }else{
        printf("\nLista vazia");
    }
}

pessoa * aloca_pessoa()
{
    char nome[100], email[100];
    pessoa * nova;

    nova = (pessoa*)malloc(sizeof(pessoa));

    __fpurge(stdin);
    printf("\nNome: ");
    fgets(nome, 100, stdin);
    nome[strlen(nome)-1] = '\0';
    nova->nome = (char*)malloc(sizeof(char)*strlen(nome));
    strcpy(nova->nome, nome);

    __fpurge(stdin);
    printf("\nEmail: ");
    fgets(email, 100, stdin);
    email[strlen(email)-1] = '\0';
    nova->email = (char*)malloc(sizeof(char)*strlen(email));
    strcpy(nova->email, email);

    printf("\nIdade: ");
    scanf("%d", &nova->idade);

    nova->prox = NULL;

    return nova;
}

void cadastra_pessoa(lista *l)
{
    pessoa * nova;

    nova = aloca_pessoa();

    if(l->inicio){
        pessoa * aux;
        aux = l->inicio;

        while(aux->prox){
            aux = aux->prox;
        }

        aux->prox = nova;
    }else{
        l->inicio = nova;
    }

    l->qtd++;
}

lista * aloca_lista()
{
    lista * nova;

    nova = (lista*)malloc(sizeof(lista));
    nova->qtd = 0;
    nova->inicio = NULL;

    return nova;
}

void opcoes()
{
    printf("\n1 - Cadastrar pessoa");
    printf("\n2 - Mostra pessoas");
    printf("\n3 - Remover pessoa");
    printf("\n0 - Sair");
    printf("\nOpcao: ");
}

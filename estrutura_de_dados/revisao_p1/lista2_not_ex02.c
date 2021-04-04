/* 
2 ) Faça um programa que leia do usuário um número N positivo e construa uma lista ligada de alunos. 
    Cada aluno possui:
    nome, matricula e media final. 
    Disponibilize ao usuários as seguintes opções:
        a) Inserir aluno na lista
        b) Mostrar alunos aprovados
        c) Mostrar alunos reprovados
        d) Remover aluno da lista.
    Obs. É considerado um aluno aprovado aquele que conter média final >=5.0; 
*/

// pronto
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno{
    char * nome;
    int matricula;
    float media_final;
    struct aluno * prox;
}aluno;

typedef struct lista{
    int qtd;
    struct aluno * inicio;
}lista;

aluno * aloca_aluno();
lista * aloca_lista();
int menu();
void inclui_aluno(lista * l);
void mostra_reprovados(lista * l);
void mostra_aprovados(lista * l);
void remove_aluno(lista * l, int mat);

int main()
{
    lista * alunos;
    int opcao = 1, mat;

    alunos = aloca_lista();

    while(opcao){
        opcao = menu();

        switch (opcao)
        {
        case 1:
            inclui_aluno(alunos);
            break;
        case 2:
            mostra_aprovados(alunos);
            break;
        case 3:
            mostra_reprovados(alunos);
            break;
        case 4:
            printf("\n remover aluno\n\tmatricula: ");
            scanf("%d", &mat);
            remove_aluno(alunos, mat);
            break;
        case 0:
            printf("\n saindo");
            break;
        default:
            printf("\n opcao invalida");
            break;
        }
    }

    printf("\n");
    return 0;
}

void remove_aluno(lista * l, int mat)
{
    if(l->inicio != NULL){
        aluno * aux, * ant;

        ant = NULL;
        aux = l->inicio;

        while(aux->prox && aux->matricula != mat){
            ant = aux;
            aux = aux->prox;
        }

        if(aux->matricula == mat){
            if(ant == NULL){
                l->inicio = aux->prox;
            }else{
                ant->prox = aux->prox;
            }
            free(aux);
        }
    }
}

void mostra_reprovados(lista * l)
{
    if(l->inicio == NULL){
        printf("\n lista vazia");
    }else{
        aluno * aux;
        aux = l->inicio;

        printf("\n reprovados: ");
        while(aux){
            if(aux->media_final < 5){
                printf("\n nome: %s\n matricula: %d\n media final: %.2f\n", aux->nome, aux->matricula, aux->media_final);
            }
            aux = aux->prox;
        }
    }
}

void mostra_aprovados(lista * l)
{
    if(l->inicio == NULL){
        printf("\n lista vazia");
    }else{
        aluno * aux;
        aux = l->inicio;

        printf("\n aprovados: ");
        while(aux){
            if(aux->media_final >= 5){
                printf("\n nome: %s\n matricula: %d\n media final: %.2f\n", aux->nome, aux->matricula, aux->media_final);
            }
            aux = aux->prox;
        }
    }
}

void inclui_aluno(lista * l)
{
    aluno * novo;
    novo = aloca_aluno();

    if(l->inicio == NULL){
        l->inicio = novo;
    }else{
        aluno * aux;

        aux = l->inicio;

        while(aux->prox)
            aux = aux->prox;

        aux->prox = novo;
    }
    l->qtd++;
}

lista * aloca_lista()
{
    lista * nova;

    nova = (lista*)calloc(1, sizeof(lista));

    return nova;
}

aluno * aloca_aluno()
{
    aluno * novo;
    char nome[50];

    novo = (aluno*)calloc(1, sizeof(aluno));

    fflush(stdin);
    printf("\n nome: ");
    scanf("%s", nome);
    novo->nome = (char*)malloc(sizeof(char)*strlen(nome));
    strcpy(novo->nome, nome);

    printf("\n matricula: ");
    scanf("%d", &novo->matricula);

    printf("\n media final: ");
    scanf("%f", &novo->media_final);

    return novo;
}

int menu()
{
    int opcao;

    printf("\n 1 - inserir aluno");
    printf("\n 2 - mostra aprovados");
    printf("\n 3 - mostra reprovados");
    printf("\n 4 - remover aluno");
    printf("\n 0 - sair\n opcao: ");
    scanf("%d", &opcao);

    return opcao;
}
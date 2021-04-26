/* 
enquanto tiver 2 ou mais cartas na pilha
Jogue fora a carta do topo e mova a próxima carta (a que ficou no topo) para a base da pilha.

Cada linha de entrada (com exceção da última) contém um número n ≤ 50.
A última linha contém 0 e não deve ser processada.
Cada número de entrada produz duas linhas de saída.
A primeira linha apresenta a sequência de cartas descartadas 
e a segunda linha apresenta a carta remanescente.

ex:
Discarded cards: 1, 3, 5, 2, 6
Remaining card: 4
*/

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
void inclui_no_final(lista * l, int num);
void remove_topo(lista *l);
void move_base_para_final(lista *l);

int main()
{
    int num;

    while(num){
        scanf("%d", &num);


        if(num){
            lista * cartas;

            cartas = aloca_lista();

            int i;

            for(i = 1; i <= num; i++){
                inclui_no_final(cartas, i);
            }

            printf("Discarded cards: ");
            while(cartas->qtd >= 2){
                if(cartas->qtd > 2){
                    printf("%d, ", cartas->inicio->valor);
                }else{
                    printf("%d\n", cartas->inicio->valor);
                }
                remove_topo(cartas);
                move_base_para_final(cartas);
            }

            printf("Remaining card: %d\n", cartas->inicio->valor);

        }
    }

    return 0;
}

void move_base_para_final(lista *l)
{
    int num = l->inicio->valor;

    remove_topo(l);

    inclui_no_final(l, num);
}

void remove_topo(lista *l)
{
    elemento * aux;
    aux = l->inicio;

    l->inicio = aux->prox;

    l->qtd--;
}

void inclui_no_final(lista *l, int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(l->inicio){
        elemento * aux;
        aux = l->inicio;

        while(aux->prox){
            aux = aux->prox;
        }

        aux->prox = novo;

    }else{
        l->inicio = novo;
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

elemento * aloca_elemento()
{
    elemento * novo;

    novo = (elemento*)malloc(sizeof(elemento));
    novo->valor = 0;
    novo->prox = NULL;

    return novo;
}
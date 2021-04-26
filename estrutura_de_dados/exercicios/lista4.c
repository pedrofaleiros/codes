#include <stdio.h>
#include <stdlib.h>

typedef struct elemento{
    int valor;
    struct elemento * prox;
}elemento;

typedef struct fila{
    int tamanho;
    struct elemento * inicio;
}fila;

fila * aloca_fila();
elemento * aloca_elemento();
void insert(fila * f, int num);
int dequeue(fila *f);
int empty(fila * f);

int main()
{
    int num;

    while(num){
        scanf("%d", &num);


        if(num){
            fila * cartas;

            cartas = aloca_fila();

            int i;

            for(i = 1; i <= num; i++){
                insert(cartas, i);
            }

            printf("Discarded cards: ");
            while(cartas->tamanho >= 2){
                if(cartas->tamanho > 2){
                    printf("%d, ", cartas->inicio->valor);
                }else{
                    printf("%d\n", cartas->inicio->valor);
                }
                dequeue(cartas);
                insert(cartas, dequeue(cartas));
            }

            printf("Remaining card: %d\n", cartas->inicio->valor);

        }
    }

    return 0;
}

int empty(fila * f)
{
    if(f->inicio == NULL)
        return 1;
    else    
        return 0;
}

int dequeue(fila *f)
{
    elemento * aux;
    int num;

    aux = f->inicio;
    num = aux->valor;

    f->inicio = aux->prox;

    free(aux);

    f->tamanho--;
    return num;
}

void insert(fila *f, int num)
{
    elemento * novo;
    novo = aloca_elemento();
    novo->valor = num;

    if(!empty(f)){
        elemento * aux;
        aux = f->inicio;

        while(aux->prox){
            aux = aux->prox;
        }

        aux->prox = novo;

    }else{
        f->inicio = novo;
    }
    f->tamanho++;
}

fila * aloca_fila()
{
    fila * nova;
    nova = calloc(1, sizeof(fila));
    return nova;
}

elemento * aloca_elemento()
{
    elemento * novo;
    novo = calloc(1, sizeof(elemento));
    return novo;
}
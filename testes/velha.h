#include <stdio.h>
#include <stdlib.h>

#define cima_esq  'q'
#define cima_esq  'q'
#define cima_dir  'e'
#define meio_esq  'a'
#define meio_mei  's'
#define meio_dir  'd'
#define baixo_esq 'z'
#define baixo_mei 'x'
#define baixo_dir 'c'

#define c_esq [0][0]
#define c_mei [0][1]
#define c_dir [0][2]
#define m_esq [1][0]
#define m_mei [1][1]
#define m_dir [1][2]
#define b_esq [2][0]
#define b_mei [2][1]
#define b_dir [2][2]

typedef struct Tab{
    int vez;
    int mat[3][3];
    int (*verifica_posicao)(Tab *);
    int (*ganhou)(Tab *);
    void (*preenche_posicao)(Tab *);
    void (*mostra)(Tab *);
    void (*play)(Tab *);
}Tab;

Tab * constructor()
{
    Tab * novo;

    novo = malloc(sizeof(Tab));
    novo->vez = 1;
    novo->mat = {0};
    novo->verifica_posicao = _verifica_;
    novo->preenche_posicao = _preenche_;
    novo->mostra = _mostra_;
    novo->play = _play_;
    novo->ganhou = _ganhou_;

    return novo;
}

void _play_(Tab * tab)
{
    while(tab){
        
    }
}
/* 
    tabuleiro:
    q | w | e
    a | s | d
    z | x | c
*/
#include <bits/stdc++.h>
#include <stdlib.h>
#include <unistd.h>
// #include <iostream>

#define cima_esq   'q'
#define cima_meio  'w'
#define cima_dir   'e'
#define meio_esq   'a'
#define meio_meio  's'
#define meio_dir   'd'
#define baixo_esq  'z'
#define baixo_meio 'x'
#define baixo_dir  'c'
using namespace std;

typedef struct tabuleiro
{
    char tab[3][3];
}tabuleiro;

int escolhe_opcao();
void linha();
void joga();
void mostra_tab(tabuleiro * tab);
int verifica_ganhador(tabuleiro * tab);

int main()
{
    while(true)
    {
        int opcao;
        opcao = escolhe_opcao();

        if(opcao == 1){
            joga();
        }else if(opcao == 2){
            break;
        }else{
            cout << "\nOpcao invalida\n" << endl;
            //sleep(2);
        }
    }

    return 0;
}

void joga()
{
    tabuleiro jogo;

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            jogo.tab[i][j] = ' ';
        }
    }

    int jogadas = 1;

    cout << "\n\t> INICIO <" << endl;

    mostra_tab(&jogo);
    while(jogadas <= 9)
    {
        char opcao;
        cout << "\nJogador ";
        if(jogadas % 2 == 0){
            cout << "X : ";
        }else{
            cout << "Bola : ";
        }
        cin >> opcao;

        switch(opcao)
        {
            case cima_esq:
                if(jogo.tab[0][0] == ' '){
                    if(jogadas % 2 == 0)
                    {
                        jogo.tab[0][0] = 'X';
                    }else{
                        jogo.tab[0][0] = 'O';
                    }
                    jogadas += 1;
                }else{
                    cout << "Escolha invalida" << endl;
                }
                break;

            case cima_meio:
                if(jogo.tab[0][1] == ' '){
                    if(jogadas % 2 == 0)
                    {
                        jogo.tab[0][1] = 'X';
                    }else{
                        jogo.tab[0][1] = 'O';
                    }
                    jogadas += 1;
                }else{
                    cout << "Escolha invalida" << endl;
                }
                break;
                
            case cima_dir:
                if(jogo.tab[0][2] == ' '){
                    if(jogadas % 2 == 0)
                    {
                        jogo.tab[0][2] = 'X';
                    }else{
                        jogo.tab[0][2] = 'O';
                    }
                    jogadas += 1;
                }else{
		            cout << "Escolha invalida" << endl;
                }
                break;

            case meio_esq:
                if(jogo.tab[1][0] == ' '){
                    if(jogadas % 2 == 0)
                    {
                        jogo.tab[1][0] = 'X';
                    }else{
                        jogo.tab[1][0] = 'O';
                    }
                    jogadas += 1;
                }else{
                    cout << "Escolha invalida" << endl;
                }
                break;
            case meio_meio:
                if(jogo.tab[1][1] == ' '){
                    if(jogadas % 2 == 0)
                    {
                        jogo.tab[1][1] = 'X';
                    }else{
                        jogo.tab[1][1] = 'O';
                    }
                    jogadas += 1;
                }else{
                    cout << "Escolha invalida" << endl;
                }
                break;

            case meio_dir:
                if(jogo.tab[1][2] == ' '){
                    if(jogadas % 2 == 0)
                    {
                        jogo.tab[1][2] = 'X';
                    }else{
                        jogo.tab[1][2] = 'O';
                    }
                    jogadas += 1;
                }else{
                    cout << "Escolha invalida" << endl;
                }
                break;

            case baixo_esq:
                if(jogo.tab[2][0] == ' '){
                    if(jogadas % 2 == 0)
                    {
                        jogo.tab[2][0] = 'X';
                    }else{
                        jogo.tab[2][0] = 'O';
                    }
                    jogadas += 1;
                }else{
                    cout << "Escolha invalida" << endl;
                }
                break;

            case baixo_meio:
                if(jogo.tab[2][1] == ' '){
                    if(jogadas % 2 == 0)
                    {
                        jogo.tab[2][1] = 'X';
                    }else{
                        jogo.tab[2][1] = 'O';
                    }
                    jogadas += 1;
                }else{
                    cout << "Escolha invalida" << endl;
                }
                break;

            case baixo_dir:
                if(jogo.tab[2][2] == ' '){
                    if(jogadas % 2 == 0)
                    {
                        jogo.tab[2][2] = 'X';
                    }else{
                        jogo.tab[2][2] = 'O';
                    }
                    jogadas += 1;
                }else{
                    cout << "Escolha invalida" << endl;
                }
                break;

            case '0':
                jogadas += 10;
                break;

            default:
                cout << "Escolha invalida" << endl;
                break;
            
        }
        
        mostra_tab(&jogo);

        int ganhou = verifica_ganhador(&jogo);

        if(ganhou == 1){
            cout << "\n\tX ganhou!!!\n" << endl;
            break;
        }else if(ganhou == 2){
            cout << "\n\tBola ganhou!!!\n" << endl;
            break;
        }else if(jogadas == 10){
            cout << "\n\tEMPATE\n" << endl;
        }
    }
}

void mostra_tab(tabuleiro * tab)
{
    
    cout << endl;
    cout << endl;

    cout << "\t" << tab->tab[0][0] << " | " << tab->tab[0][1] << " | " << tab->tab[0][2] << endl;
    linha();   
    cout << "\t" << tab->tab[1][0] << " | " << tab->tab[1][1] << " | " << tab->tab[1][2] << endl;   
    linha();   
    cout << "\t" << tab->tab[2][0] << " | " << tab->tab[2][1] << " | " << tab->tab[2][2] << endl;

    cout << endl;
    cout << endl;
}

int verifica_ganhador(tabuleiro * tab)
{
    int retorno = 0;

    for(int i = 0; i < 3; i++)
    {
        if(tab->tab[i][0] == 'X' && tab->tab[i][1] == 'X' && tab->tab[i][2] == 'X'){
            retorno = 1;
        }else if(tab->tab[0][i] == 'X' && tab->tab[1][i] == 'X' && tab->tab[2][i] == 'X'){
            retorno = 1;
        }else if(tab->tab[0][0] == 'X' && tab->tab[1][1] == 'X' && tab->tab[2][2] == 'X'){
            retorno = 1;
        }else if(tab->tab[0][2] == 'X' && tab->tab[1][1] == 'X' && tab->tab[2][0] == 'X'){
            retorno = 1;
        }

        if(tab->tab[i][0] == 'O' && tab->tab[i][1] == 'O' && tab->tab[i][2] == 'O'){
            retorno = 2;
        }else if(tab->tab[0][i] == 'O' && tab->tab[1][i] == 'O' && tab->tab[2][i] == 'O'){
            retorno = 2;
        }else if(tab->tab[0][0] == 'O' && tab->tab[1][1] == 'O' && tab->tab[2][2] == 'O'){
            retorno = 2;
        }else if(tab->tab[0][2] == 'O' && tab->tab[1][1] == 'O' && tab->tab[2][0] == 'O'){
            retorno = 2;
        }
    }

    return retorno;
}

int escolhe_opcao()
{
    int opcao;
    
    cout << endl;
    cout << endl;

    cout << "Escolha uma opcao:" << endl;
    cout << "\n1 - Jogar\n\n2 - Sair\n" << endl;
    cout << "Opcao: ";
    cin >> opcao;

    return opcao;
}

void linha()
{
    cout << "\t---------" << endl;
}

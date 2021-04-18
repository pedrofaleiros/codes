#include <bits/stdc++.h>
#include <stdlib.h>
#include <unistd.h>
#include <iostream>

using namespace std;

#define up_l 'q'
#define up_c 'w'
#define up_r 'e'
#define center_l 'a'
#define center_c 's'
#define center_r 'd'
#define down_l 'z'
#define down_c 'x'
#define down_r 'c'
#define True 1
#define False 0

class Tabuleiro{
    public:
        Tabuleiro(){
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    matriz[i][j] = '0';
                }
            }
        }

        bool acabou(){
            if(matriz[0][0] == matriz[0][1] && matriz[0][0] == matriz[0][2] && matriz[0][0] != '0'){
                win = True;
                cout << "\n Jogador " << matriz[0][0] << " venceu!!!" << endl;
            }
            else if(matriz[1][0] == matriz[1][1] && matriz[1][0] == matriz[1][2] && matriz[1][0] != '0'){
                win = True;
                cout << "\n Jogador " << matriz[1][0] << " venceu!!!" << endl;
            }
            else if(matriz[2][0] == matriz[2][1] && matriz[2][0] == matriz[2][2] && matriz[2][0] != '0'){
                win = True;
                cout << "\n Jogador " << matriz[2][0] << " venceu!!!" << endl;
            }
            else if(matriz[0][0] == matriz[1][0] && matriz[0][0] == matriz[2][0] && matriz[0][0] != '0'){
                win = True;
                cout << "\n Jogador " << matriz[0][0] << " venceu!!!" << endl;
            }
            else if(matriz[0][1] == matriz[1][1] && matriz[0][1] == matriz[2][1] && matriz[0][1] != '0'){
                win = True;
                cout << "\n Jogador " << matriz[0][1] << " venceu!!!" << endl;
            }
            else if(matriz[0][2] == matriz[1][2] && matriz[0][2] == matriz[2][2] && matriz[0][2] != '0'){
                win = True;
                cout << "\n Jogador " << matriz[0][2] << " venceu!!!" << endl;
            }
            else if(matriz[0][0] == matriz[1][1] && matriz[0][0] == matriz[2][2] && matriz[0][0] != '0'){
                win = True;
                cout << "\n Jogador " << matriz[0][0] << " venceu!!!" << endl;
            }
            else if(matriz[0][2] == matriz[1][1] && matriz[0][2] == matriz[2][0] && matriz[0][2] != '0'){
                win = True;
                cout << "\n Jogador " << matriz[0][2] << " venceu!!!" << endl;
            }else if(jogadas >= 9){
                cout << "\n empate" << endl;
                win = True;
            }

            return win;
        }

        void preenche_posicao(){
            cout << "\n Vez do jogador " << vez << endl;
            cout << "\n opcao: ";
            char opt;
            cin >> opt;

            if(opt == '0')
                win = True;
            else{
                if(esta_livre(opt)){
                    if(vez == 'X')
                        vez = 'O';
                    else
                        vez = 'X';
                    jogadas++;
                }else{
                    cout << "\n opcao invalida" << endl;
                }
            }
        }

        void mostra_tab(){
            char p;
            cout << "\n";
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if(matriz[i][j] == '0'){
                        p = ' ';
                    }else{
                        p = matriz[i][j];
                    }
                    if(j < 2){
                        cout << p << " | "; 
                    }else{
                        cout << p << endl;
                    }
                }
            }
        }

    private:
        bool win = False;

        int jogadas = 0;

        char vez = 'X';

        char matriz[3][3];

        bool esta_livre(char opcao){
            bool ret = True;

            switch(opcao){
                case up_l:
                    if(matriz[0][0] != '0')
                        ret = False;
                    else
                        matriz[0][0] = vez;
                    break;
                case up_c:
                    if(matriz[0][1] != '0')
                        ret = False;
                    else
                        matriz[0][1] = vez;
                    break;
                case up_r:
                    if(matriz[0][2] != '0')
                        ret = False;
                    else
                        matriz[0][2] = vez;
                    break;
                
                case center_l:
                    if(matriz[1][0] != '0')
                        ret = False;
                    else
                        matriz[1][0] = vez;
                    break;
                case center_c:
                    if(matriz[1][1] != '0')
                        ret = False;
                    else
                        matriz[1][1] = vez;
                    break;
                case center_r:
                    if(matriz[1][2] != '0')
                        ret = False;
                    else
                        matriz[1][2] = vez;
                    break;
                
                case down_l:
                    if(matriz[2][0] != '0')
                        ret = False;
                    else
                        matriz[2][0] = vez;
                    break;
                case down_c:
                    if(matriz[2][1] != '0')
                        ret = False;
                    else
                        matriz[2][1] = vez;
                    break;
                case down_r:
                    if(matriz[2][2] != '0')
                        ret = False;
                    else
                        matriz[2][2] = vez;
                    break;
                default:
                    ret = False;
                    break;
            }

            return ret;
        }
};

int main()
{
    int opcao = 1;

    while(opcao != 0){
        cout << "\n 1 - Jogar\n 0 - Sair\n opcao: ";
        cin >> opcao;
        if(opcao){
            system("clear");
            Tabuleiro tab;

            tab.mostra_tab();
            while(!tab.acabou()){
                tab.preenche_posicao();
                tab.mostra_tab();
            }
        }
    }

    cout << "\n";
    return 0;    
}
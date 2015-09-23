/* main.c */
// PONTIFICA UNIVERSIDADE CATOLICA DO PARANA
// ESCOLA POLITECNICA
// CIENCIA DA COMPUTACAO
// PROGRAMACAO IMPERATIVA
//
// GUILHERME GUSTAVO HENSCHEL
// RAFAEL DE SOUZA TEIXEIRA
//
// IMPLEMENTACAO MULTIPLATAFORMA DE PONG
// EM C UTILIZANDO RECURSOS GRAFICOS DO
// TERMINAL OU PROMTCMD
//
// CURITIBA 2015

#include <stdio.h>
#include <stdlib.h>
#include "tela.h"
#include "pong_raquete.h"
#include "desenha_menu.h"

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#define kbhit _kbhit
#define getch _getch
#define limpa_tela() COORD coord = {0, 0}; SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord)
#define dorme(milis) Sleep(milis)
#else
#include <unistd.h>
#include "console.h"
#define limpa_tela() system("clear")
#define dorme(milis) usleep(milis * 1000)
#endif

int main () {
    
    char tela[ALTURA][LARGURA];
	char menu[ALTURA][LARGURA];
    int direcao;
    int reinicia=1;
    Bola b;
    player player1, player2;

    while (reinicia!=0) {    
        menuInic(menu);
        player1.score=0;
        player2.score=0;
        rand_direction(&b);
        limpa_tela();
        menuDesenha(menu);
        while (!(getch() == 13 || getch() == 10)){
            ;
        }
        reinicia=1;
        while (reinicia>-1) {
            inicializa(tela, &b, player1.score, player2.score);
            inicializa_player(tela,&player1, 1);
            inicializa_player(tela,&player2, 2);
            reinicia=1;
            while (1) {
                if (reinicia==4) {while (!(getch()==27)) {
                        ;
                    }
                    reinicia=1;
                }
                if (reinicia==2) {
                    player1.score+=1;
                    b.d=LESTE;
                    break;
                }
                if (reinicia==3) {
                    player2.score+=1;
                    b.d=OESTE;
                    break;
                }
                if (player2.score==10||player1.score==10) {
                    reinicia=5;
                    break;
                }
                
                limpa_tela();
                desenha(tela);
                if (kbhit()) {
                    direcao = getch();
                    muda_direcao_player1(&player1, direcao);
                    muda_direcao_player2(&player2, direcao, &reinicia);
                }
                mover_player(tela, &player1);
                mover_player(tela, &player2);
                mover_bola(tela, &b, &player1,&player2, &reinicia);
                dorme(60);
                }
            }
    }
  return 0;
}

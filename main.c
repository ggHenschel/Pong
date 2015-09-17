/* main.c */

#include <stdio.h>
#include <stdlib.h>
#include "tela.h"
#include "pong_raquete.h"

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#define kbhit _kbhit
#define getch _getch
#define limpa_tela() system("cls")
#define dorme(milis) Sleep(milis)
#else
#include <unistd.h>
#include "console.h"
#define limpa_tela() system("clear")
#define dorme(milis) usleep(milis * 2000)
#endif

int main () {

    char tela[ALTURA][LARGURA];
    int direcao;
    Ponto p;
    player player1, player2;

    inicializa(tela, &p);
    inicializa_player(tela,&player1, 1);
    inicializa_player(tela,&player2, 2);

  while (1) {
    limpa_tela();
    desenha(tela);
    if (kbhit()) {
		direcao = getch();
        muda_direcao_player2(&player2, direcao);
        muda_direcao_player1(&player1, direcao);
    }
    mover_player(tela, &player1);
    mover_player(tela, &player2);
    mover_bola_novo(tela, &p, &player2,&player1);
    dorme(20);
  }

  return 0;
}

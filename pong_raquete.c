//
//  pong_raquete.c
//  Ponto
//
//  Created by Guilherme Gustavo Henschel on 9/11/15.
//  Copyright (c) 2015 Learning. All rights reserved.
//

#include <stdio.h>
#include "tela.h"
#include "pong_raquete.h"

void inicializa_player(char tela[ALTURA][LARGURA], player* player,int n){
    if (n==1) {
        player->x=LARGURA-3;
    }
    else{
        player->x=2;
    }
    player->y=ALTURA/2;
    player->d=2;
    tela[player->y-1][player->x]=BARRA_R;
    tela[player->y][player->x]=BARRA_R;
    tela[player->y+1][player->x]=BARRA_R;
}

void mover_player(char tela[ALTURA][LARGURA], player* player){
    if (player->d == NORTE) {
        if (player->y > 2) {
            norte_player(tela, player);
        }
        else {
            player->d = SUL;
            sul_player(tela, player);
        }
    }
    else if (player->d == SUL) {
        if (player->y < ALTURA - 3) {
            sul_player(tela, player);
        }
        else {
            player->d = NORTE;
            norte_player(tela, player);
        }
    }
}
void norte_player (char tela[ALTURA][LARGURA], player* player){
    tela[player->y+1][player->x] = ESPACO;
    player->y--;
    tela[player->y-1][player->x] = BARRA_R;
    player->d=2; //break
}
void sul_player (char tela[ALTURA][LARGURA], player* player){
    tela[player->y-1][player->x] = ESPACO;
    player->y++;
    tela[player->y+1][player->x] = BARRA_R;
    player->d=2;
}

void muda_direcao_player2 (player* p, int d){
    if (d == 's') {
        p->d = SUL;
    }
    else if (d == 'w') {
        p->d = NORTE;
    }

}

void muda_direcao_player1 (player* p, int d){
    if (d == 'l') {
        p->d = SUL;
    }
    else if (d == 'o') {
        p->d = NORTE;
    }
    
}
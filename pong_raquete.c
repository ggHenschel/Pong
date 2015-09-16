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
    player->d=4;
    tela[player->y-1][player->x]=BARRA_R;
    tela[player->y][player->x]=BARRA_R;
    tela[player->y+1][player->x]=BARRA_R;
}
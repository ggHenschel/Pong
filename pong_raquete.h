//
//  pong_raquete.h
//  Ponto
//
//  Created by Guilherme Gustavo Henschel on 9/11/15.
//  Copyright (c) 2015 Learning. All rights reserved.
//

#ifndef Ponto_pong_raquete_h
#define Ponto_pong_raquete_h

#define BARRA_R '|'

typedef struct barra{
    int x;
    int y;
    enum direcao d;
} player;

void inicializa_player(char tela[ALTURA][LARGURA], player* player,int n);
void mover_player (char tela[ALTURA][LARGURA], player* player);
void norte_player (char tela[ALTURA][LARGURA], player* player);
void sul_player (char tela[ALTURA][LARGURA], player* player);


#endif

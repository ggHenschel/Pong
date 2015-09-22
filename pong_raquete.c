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
#include <stdlib.h>
#include <time.h>

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
        if (player->y > 3) {
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
    player->d=2;
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

void muda_direcao_player1 (player* p, int d, int* reinicia){
    if (d == 'l') {
        p->d = SUL;
    }
    else if (d == 'o') {
        p->d = NORTE;
    } else if (d == 27){
        *reinicia = 4;
    }
    
}

void mover_bola_novo (char tela[ALTURA][LARGURA], Ponto* p, player* p1, player* p2, int* reinicia) {
       if (p->d == OESTE) {
        if (p->y > 1 && !((p->y < p1->x+2 && p->x == p1->y) || (p->y == p1->x+1 && p->x == p1->y-1) || (p->y == p1->x+1 && p->x == p1->y+1) )) {
            oeste(tela, p);
        }
        else {
            if (p->y == p1->x+1 && p->x == p1->y-1) {
                p->d=NORDESTE;
                norte(tela, p);
				leste(tela, p);
            }
            else if (p->y == p1->x+1 && p->x == p1->y+1){
                p->d=SULDESTE;
                sul(tela, p);
				leste(tela, p);
            } else if(p->y == 1){
                *reinicia=2;
                } else {
                p->d = LESTE;
				leste(tela, p);
            }
            
            
        }
    }
    else if (p->d == LESTE) {
        if ((p->y<LARGURA-2)&&!((p->y > p2->x-2 && p->x == p2->y)|| (p->y == p2->x-1 && p->x == p2->y-1) || (p->y == p2->x-1 && p->x == p2->y+1))) {
            leste(tela, p);
        }
        else {
            if (p->y == p2->x-1 && p->x == p2->y-1) {
                p->d=NOROESTE;
                norte(tela, p);
				oeste(tela, p);
            } else if (p->y == p2->x-1 && p->x == p2->y+1){
                p->d=SULDOESTE;
                sul(tela, p);
				oeste(tela, p);
            } else if(p->y==LARGURA-2){
                *reinicia=3;
            } else  {
                p->d = OESTE;
				oeste(tela, p);
            }
            
        }
    }
    else if (p->d == NORDESTE) {
        if ( p->x > 2 && (p->y<LARGURA-2) &&!((p->y == p2->x && p->x == p2->y)|| (p->y == p2->x-1 && p->x == p2->y-1) || (p->y == p2->x-1 && p->x == p2->y+1) || (p->y-1 == p2->x && p->x == p2->y))) {
            leste(tela, p);
            norte(tela, p);
        }
        else {
            if (p->y == p2->x-1 && p->x == p2->y-1) {
                p->d=LESTE;
                leste(tela, p);
            } else if (p->y == p2->x-1 && p->x == p2->y+1){
                p->d=NOROESTE;
                norte(tela, p);
                oeste(tela, p);
            } else if(p->x == 2){
                p->d=SULDESTE;
                sul(tela, p);
                leste(tela, p);
            } else if(p->y==LARGURA-2){
                *reinicia=3;
            } else {
                p->d = SULDOESTE;
                sul(tela, p);
                oeste(tela, p);
                
            }
        }
    }
	else if (p->d == NOROESTE) {
		if (p->x > 2 && p->y>1 && !((p->y-1 == p1->x && p->x == p1->y) || (p->y == p1->x - 1 && p->x == p1->y - 1) || (p->y == p1->x - 1 && p->x == p1->y + 1) || (p->y == p1->x && p->x == p1->y))) {
			norte(tela, p);
			oeste(tela, p);
		}
		else {
		if (p->y == p1->x - 1 && p->x == p1->y - 1) {
				p->d = NORDESTE;
				norte(tela, p);
				leste(tela, p);
			} else if (p->y == p1->x - 1 && p->x == p1->y + 1) {
				p->d = SULDESTE;
				sul(tela, p);
				leste(tela, p);
			} else if (p->x == 2) {
				p->d = SULDOESTE;
				sul(tela, p);
				oeste(tela, p);
            } else if (p->y==1){
                *reinicia=2;
            } else {
				p->d = LESTE;
				leste(tela, p);
			}
		}
	}
	else if (p->d == SULDESTE) {
		if (p->x < ALTURA - 2 && p->y<LARGURA-2 && !((p->y == p2->x && p->x == p2->y) || (p->y == p2->x - 1 && p->x == p2->y - 1) || (p->y == p2->x - 1 && p->x == p2->y + 1) || (p->y-1 == p2->x && p->x == p2->y))) {
			leste(tela, p);
			sul(tela, p);
		}
		else {
			if (p->y == p2->x - 1 && p->x == p2->y - 1) {
				p->d = OESTE;
				oeste(tela, p);
			}
			else if (p->y == p2->x - 1 && p->x == p2->y + 1) {
				p->d = SULDOESTE;
				sul(tela, p);
				oeste(tela, p);
			}
			else if (p->x == ALTURA - 2) {
				p->d = NORDESTE;
				leste(tela, p);
				norte(tela, p);
            } else if (p->y==LARGURA-2) {
                *reinicia=3;
            }
			else {
				p->d = OESTE;
				oeste(tela, p);
			}
		}
	}
	else if (p->d == SULDOESTE) {
		if (p->x < ALTURA - 2 && p->y>1 && !((p->y == p1-> x && p->x == p1->y) || (p->y == p1->x - 1 && p->x == p1->y - 1) || (p->y == p1->x - 1 && p->x == p1->y + 1) || (p->y - 1 == p1->x && p->x == p1->y))){
			sul(tela, p);
			oeste(tela, p);
		}
		else {
			if (p->y == p1->x - 1 && p->x == p1->y + 1) {
				p->d = NORDESTE;
				norte(tela, p);
				leste(tela, p);
			} else if (p->y == p1->x - 1 && p->x == p1->y - 1) {
				p->d = SULDESTE;
				sul(tela, p);
				leste(tela, p);
			} else if (p->x == ALTURA - 2) {
				p->d = NOROESTE;
				norte(tela, p);
				oeste(tela, p);
            }  else if (p->y==1){
                *reinicia=2;
            }
			else {
				p->d = LESTE;
				leste(tela, p);
			}
		}
	}

}

void rand_direction (Ponto* p){
    srand(time(NULL));
    p->d=rand()%6+2;
}
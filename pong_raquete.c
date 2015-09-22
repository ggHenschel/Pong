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
#include "tela.h"
#include "pong_raquete.h"
#include <stdlib.h>
#include <time.h>

void inicializa_player(char tela[ALTURA][LARGURA], player* player,int n){
    if (n==1) {
        player->x=2;
    }
    else{
        player->x=LARGURA-3;
    }
    player->y=ALTURA/2;
    player->d=2;
    tela[player->y-1][player->x]=BARRA_R;
    tela[player->y][player->x]=BARRA_R;
    tela[player->y+1][player->x]=BARRA_R;
}

void mover_player(char tela[ALTURA][LARGURA], player* player){
    if (player->d == NORTE) {
        if (player->y > 4) {
            norte_player(tela, player);
        }
        else {
            player->d = SUL;
            sul_player(tela, player);
        }
    }
    else if (player->d == SUL) {
        if (player->y < ALTURA - 4) {
            sul_player(tela, player);
        }
        else {
            player->d = NORTE;
            norte_player(tela, player);
        }
    }
}
void norte_player (char tela[ALTURA][LARGURA], player* player){
    if (player->y>3) {
        tela[player->y+1][player->x] = ESPACO;
        player->y--;
        tela[player->y-1][player->x] = BARRA_R;
        player->d=2;
    }
}
void sul_player (char tela[ALTURA][LARGURA], player* player){
    if (player->y<ALTURA-3) {
        tela[player->y-1][player->x] = ESPACO;
        player->y++;
        tela[player->y+1][player->x] = BARRA_R;
        player->d=2;
    }
}

void muda_direcao_player1 (player* p, int d){
    if (d == 's') {
        p->d = SUL;
    }
    else if (d == 'w') {
        p->d = NORTE;
    }

}

void muda_direcao_player2 (player* p, int d, int* reinicia){
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
    /*  Toda colisão da bola com o resto do ambiente está contidod aqui*/
       if (p->d == OESTE) {
        if (p->y > 1 && !((p->y == p1->x+1 && p->x == p1->y) || (p->y == p1->x+1 && p->x == p1->y-1) || (p->y == p1->x+1 && p->x == p1->y+1) )) {
            /*  Essa condição define que a bola irá se mover na direção porém irá mudar de direção caso encontre alguma das raquetes.
                Se maior que e diferente de uma das 3 posições da raquete, faça... */
            oeste(tela, p);
        }
        else {
            if (p->y == p1->x+1 && p->x == p1->y-1) {
                // Se igual a raquete superior faça...
                p->d=NORDESTE;
                norte(tela, p);
				leste(tela, p);
            }
            else if (p->y == p1->x+1 && p->x == p1->y+1){
                // Se igual a raquete inferior faça...
                p->d=SULDESTE;
                sul(tela, p);
				leste(tela, p);
            } else if(p->y == 1){
                // Se igual a posição da parede faça...
                *reinicia=3;
                } else {
                // Em qualquer outro caso, mude a direção
                // Só será chamada quando for igual a raquete média
                p->d = LESTE;
				leste(tela, p);
            }
            
            
        }
    }
    else if (p->d == LESTE) {
        if ((p->y<LARGURA-2)&&!((p->y == p2->x-1 && p->x == p2->y)|| (p->y == p2->x-1 && p->x == p2->y-1) || (p->y == p2->x-1 && p->x == p2->y+1))) {
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
                *reinicia=2;
            } else  {
                p->d = OESTE;
				oeste(tela, p);
            }
            
        }
    }
    else if (p->d == NORDESTE) {
        if ( p->x > 2 && (p->y<LARGURA-2) &&!((p->y == p2->x-1 && p->x == p2->y)|| (p->y == p2->x-1 && p->x == p2->y-1) || (p->y == p2->x-1 && p->x == p2->y+1) || (p->y-1 == p2->x && p->x == p2->y))) {
            /*  Essa condição define que a bola irá se mover na direção porém irá mudar de direção caso encontre alguma das raquetes.
             Se maior que e diferente de uma das 3 posições da raquete, faça... */
            leste(tela, p);
            norte(tela, p);
        }
        else {
            if (p->y == p2->x-1 && p->x == p2->y-1) {
                // Se igual a raquete superior faça...
                p->d=NOROESTE;
                norte(tela, p);
                oeste(tela, p);
            } else if (p->y == p2->x-1 && p->x == p2->y+1){
                // Se igual a raquete inferior faça...
                p->d=SULDOESTE;
                sul(tela, p);
                oeste(tela, p);
            } else if(p->x == 2){
                // Se igual ao Teto faça...
                p->d=SULDESTE;
                sul(tela, p);
                leste(tela, p);
            } else if(p->y==LARGURA-2){
                *reinicia=2;
            } else {
                p->d = OESTE;
                oeste(tela, p);
                
            }
        }
    }
	else if (p->d == NOROESTE) {
		if (p->x > 2 && p->y>1 && !((p->y == p1->x+1 && p->x == p1->y) || (p->y == p1->x +1  && p->x == p1->y - 1) || (p->y == p1->x + 1 && p->x == p1->y + 1) || (p->y == p1->x+1 && p->x == p1->y))) {
			norte(tela, p);
			oeste(tela, p);
		}
		else {
		if (p->y == p1->x + 1 && p->x == p1->y - 1) {
				p->d = NORDESTE;
				norte(tela, p);
				leste(tela, p);
			} else if (p->y == p1->x + 1 && p->x == p1->y + 1) {
				p->d = SULDESTE;
				sul(tela, p);
				leste(tela, p);
			} else if (p->x == 2) {
				p->d = SULDOESTE;
				sul(tela, p);
				oeste(tela, p);
            } else if (p->y==1){
                *reinicia=3;
            } else {
				p->d = LESTE;
				leste(tela, p);
			}
		}
	}
	else if (p->d == SULDESTE) {
		if (p->x < ALTURA - 2 && p->y<LARGURA-2 && !((p->y == p2->x-1 && p->x == p2->y) || (p->y == p2->x - 1 && p->x == p2->y - 1) || (p->y == p2->x - 1 && p->x == p2->y + 1) || (p->y == p2->x-1 && p->x == p2->y))) {
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
                *reinicia=2;
            }
			else {
				p->d = OESTE;
				oeste(tela, p);
			}
		}
	}
	else if (p->d == SULDOESTE) {
		if (p->x < ALTURA - 2 && p->y>1 && !((p->y == p1-> x+1 && p->x == p1->y) || (p->y == p1->x + 1 && p->x == p1->y - 1) || (p->y == p1->x + 1 && p->x == p1->y + 1) || (p->y - 1 == p1->x && p->x == p1->y))){
			sul(tela, p);
			oeste(tela, p);
		}
		else {
			if (p->y == p1->x + 1 && p->x == p1->y + 1) {
				p->d = NORDESTE;
				norte(tela, p);
				leste(tela, p);
			} else if (p->y == p1->x + 1 && p->x == p1->y - 1) {
				p->d = SULDESTE;
				sul(tela, p);
				leste(tela, p);
			} else if (p->x == ALTURA - 2) {
				p->d = NOROESTE;
				norte(tela, p);
				oeste(tela, p);
            }  else if (p->y==1){
                *reinicia=3;
            }
			else {
				p->d = LESTE;
				leste(tela, p);
			}
		}
	}

}

void rand_direction (Ponto* p){
    /*  Essa função chama uma direção aleatoria
        entre 6 das 8 direções possiveis para a "bola" */
    srand(time(NULL));
    p->d=rand()%6+2;
}
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
#ifdef _WIN32
#pragma comment(lib, "winmm.lib")
#include <Windows.h>
#define S(x) #x
#define SX(x) S(x)
#define som(file) PlaySound(TEXT(SX(file)),NULL,SND_ASYNC)

#else
#include <unistd.h>
#include "mac_som.h"
#define S(x) #x
#define SX(x) S(x)
#define som(file) mac_som(SX(file))
#endif

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

void mover_player(char tela[ALTURA][LARGURA], player* p) {
	if (tela[p->y + 1][LARGURA - 3] == 'o' || tela[p->y - 1][LARGURA - 3] == 'o' || tela[p->y + 1][2] == 'o' || tela[p->y - 1][2] == 'o')  {
		;
	}
	else if (p->d == NORTE) {
		if (p->y > 3) {
			norte_player(tela, p);
		}
	}
	else if (p->d == SUL) {
		if (p->y < ALTURA - 3) {
			sul_player(tela, p);
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

void muda_direcao_player1 (player* p, int d, int* reinicia){
    if (d == 's') {
        p->d = SUL;
    }
    else if (d == 'w') {
        p->d = NORTE;
	} else if (d == 27) {
		*reinicia = 4;
	}

}

void muda_direcao_player2 (player* p, int d){
    if (d == 'l') {
        p->d = SUL;
    }
    else if (d == 'o') {
        p->d = NORTE;
    }
    
}

void mover_bola (char tela[ALTURA][LARGURA], Bola* b, player* p1, player* p2, int* reinicia) {
    /*  Toda colisão da bola com o resto do ambiente está contidod aqui*/
       if (b->d == OESTE) {
        if (b->x > 2 && !((b->x == 3 && b->y == p1->y) || (b->x == 3 && b->y == p1->y-1) || (b->x == 3 && b->y == p1->y+1) )) {
            /*  Essa condição define que a bola irá se mover na direção porém irá mudar de direção caso encontre alguma das raquetes.
                Se maior que e diferente de uma das 3 posições da raquete, faça... */
            oeste(tela, b);
        }
        else {
            if (b->x == 3 && b->y == p1->y-1) {
                // Se igual a raquete superior faça...
                som(sounds\\raquete.wav);
                b->d=NORDESTE;
                mover_bola(tela, &b, &p1,&p2,&reinicia);
            }
            else if (b->x == 3 && b->y == p1->y+1){
                // Se igual a raquete inferior faça...
                som(sounds\\raquete.wav);
                b->d=SULDESTE;
                mover_bola(tela, &b, &p1,&p2,&reinicia);
            } else if(b->x == 2){
                // Se igual a posição da parede faça...
                som(sounds\\ponto.wav);
                *reinicia=3;
			} else {
                // Em qualquer outro caso, mude a direção
                // Só será chamada quando for igual a raquete média
                som(sounds\\raquete.wav);
                b->d = LESTE;
				mover_bola(tela, &b, &p1,&p2,&reinicia);
            }
            
            
        }
    }
    else if (b->d == LESTE) {
        if ((b->x < LARGURA - 3) &&!((b->x == LARGURA-4 && b->y == p2->y)|| (b->x == LARGURA-4 && b->y == p2->y-1) || (b->x == LARGURA-4 && b->y == p2->y+1))) {
            leste(tela, b);
        }
        else {
            if (b->x == LARGURA-4 && b->y == p2->y-1) {
                som(sounds\\raquete.wav);
                b->d=NOROESTE;
                mover_bola(tela, &b, &p1,&p2,&reinicia);
            } else if (b->x == LARGURA-4 && b->y == p2->y+1){
                som(sounds\\raquete.wav);
                b->d=SULDOESTE;
                mover_bola(tela, &b, &p1,&p2,&reinicia);
            } else if(b->x==LARGURA-3){
                som(sounds\\ponto.wav);
                *reinicia=2;
            } else  {
                som(sounds\\raquete.wav);
                b->d = OESTE;
				mover_bola(tela, &b, &p1,&p2,&reinicia);
            }
            
        }
    }
    else if (b->d == NORDESTE) {
        if ( b->y > 2 && b->x < LARGURA - 3 &&!((b->x == LARGURA-4 && b->y == p2->y)|| (b->x == LARGURA-4 && b->y == p2->y-1) || (b->x == LARGURA-4 && b->y == p2->y+1))) {
            leste(tela, b);
            norte(tela, b);
        }
        else {
            if (b->x == LARGURA-4 && b->y == p2->y-1) {
                // Se igual a raquete superior faça...
                som(sounds\\raquete.wav);
                b->d=NOROESTE;
                mover_bola(tela, &b, &p1,&p2,&reinicia);
            } else if (b->x == LARGURA-4 && b->y == p2->y+1){
                som(sounds\\raquete.wav);	
                b->d=SULDOESTE;
                mover_bola(tela, &b, &p1,&p2,&reinicia);
            } else if(b->y == 2){
                som(sounds\\parede.wav);
                b->d=SULDESTE;
                mover_bola(tela, &b, &p1,&p2,&reinicia);
            } else if(b->x==LARGURA-3){
                som(sounds\\ponto.wav);
                *reinicia=2;
            } else {
                som(sounds\\raquete.wav);
                b->d = OESTE;
                mover_bola(tela, &b, &p1,&p2,&reinicia);
                
            }
        }
    }
	else if (b->d == NOROESTE) {
 		if (b->y > 2 && b->x > 2 && !((b->x == 3 && b->y == p1->y) || (b->x == 3  && b->y == p1->y - 1) || (b->x == 3 && b->y == p1->y + 1) || (b->x == 3 && b->y == p1->y))) {
			norte(tela, b);
			oeste(tela, b);
		}
		else {
		if (b->x == 3 && b->y == p1->y - 1) {
                som(sounds\\raquete.wav);
				b->d = NORDESTE;
				mover_bola(tela, &b, &p1,&p2,&reinicia);
			} else if (b->x == 3 && b->y == p1->y + 1) {
                som(sounds\\raquete.wav);
				b->d = SULDESTE;
				mover_bola(tela, &b, &p1,&p2,&reinicia);			} else if (b->y == 2) {
                som(sounds\\parede.wav);
				b->d = SULDOESTE;
				mover_bola(tela, &b, &p1,&p2,&reinicia);
            } else if (b->x==2){
                som(sounds\\ponto.wav);
                *reinicia=3;
            } else {
                som(sounds\\raquete.wav);
				b->d = LESTE;
				mover_bola(tela, &b, &p1,&p2,&reinicia);
			}
		}
	}
	else if (b->d == SULDESTE) {
		if (b->y < ALTURA - 2 && b->x < LARGURA - 3 && !((b->x == LARGURA-4 && b->y == p2->y) || (b->x == LARGURA-4 && b->y == p2->y - 1) || (b->x == LARGURA-4 && b->y == p2->y + 1) || (b->x == LARGURA-4 && b->y == p2->y))) {
			leste(tela, b);
			sul(tela, b);
		}
		else {
			if (b->x == LARGURA-4 && b->y == p2->y - 1) {
                som(sounds\\raquete.wav);
				b->d = NOROESTE;
                mover_bola(tela, &b, &p1,&p2,&reinicia);
			}
			else if (b->x == LARGURA-4 && b->y == p2->y + 1) {
                som(sounds\\raquete.wav);
				b->d = SULDOESTE;
				mover_bola(tela, &b, &p1,&p2,&reinicia);
			}
			else if (b->y == ALTURA - 2) {
                som(sounds\\parede.wav);
				b->d = NORDESTE;
				mover_bola(tela, &b, &p1,&p2,&reinicia);
            } else if (b->x==LARGURA-3) {
                som(sounds\\ponto.wav);
                *reinicia=2;
            }
			else {
                som(sounds\\raquete.wav);
				b->d = OESTE;
				mover_bola(tela, &b, &p1,&p2,&reinicia);
			}
		}
	}
	else if (b->d == SULDOESTE) {
		if (b->y < ALTURA - 2 && b->x>2 && !((b->x == 3 && b->y == p1->y) || (b->x == 3 && b->y == p1->y - 1) || (b->x == 3 && b->y == p1->y + 1) || (b->x == 3 && b->y == p1->y))){
			sul(tela, b);
			oeste(tela, b);
		}
		else {
			if (b->x == 3 && b->y == p1->y - 1) {
                som(sounds\\raquete.wav);
				b->d = NORDESTE;
				mover_bola(tela, &b, &p1,&p2,&reinicia);
			} else if (b->x == 3 && b->y == p1->y + 1) {
                som(sounds\\raquete.wav);
				b->d = SULDESTE;
				mover_bola(tela, &b, &p1,&p2,&reinicia);
			} else if (b->y == ALTURA - 2) {
                som(sounds\\parede.wav);
				b->d = NOROESTE;
				mover_bola(tela, &b, &p1,&p2,&reinicia);
            }  else if (b->x==2){
                som(sounds\\ponto.wav);
                *reinicia=3;
            }
			else {
                som(sounds\\raquete.wav);
				b->d = LESTE;
				mover_bola(tela, &b, &p1,&p2,&reinicia);
			}
		}
	}

}

void rand_direction (Bola* p){
    srand(time(NULL));
    p->d=rand()%6+2;
}
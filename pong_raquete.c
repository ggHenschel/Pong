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
#include <windows.h>
#define S(x) #x
#define SX(x) S(x)
#define som(file) PlaySound(TEXT(SX(x)),NULL,SND_ASYNC)
#else
#include <unistd.h>
#include "mac_som.h"
#define som(file) mac_som(file,tela)
#endif

void inicializa_player(char tela[ALTURA][LARGURA], player* player,int n){
    if (n==1) {
        player->y=2;
    }
    else{
        player->y=LARGURA-3;
    }
    player->x=ALTURA/2;
    player->d=2;
    tela[player->x-1][player->y]=BARRA_R;
    tela[player->x][player->y]=BARRA_R;
    tela[player->x+1][player->y]=BARRA_R;
}

void mover_player(char tela[ALTURA][LARGURA], player* player){
    if (player->d == NORTE) {
        if (player->x > 3) {
            norte_player(tela, player);
        }
    }
    else if (player->d == SUL) {
        if (player->x < ALTURA - 3) {
            sul_player(tela, player);
        }
    }
}

void norte_player (char tela[ALTURA][LARGURA], player* player){
    if (player->x>3) {
        tela[player->x+1][player->y] = ESPACO;
        player->x--;
        tela[player->x-1][player->y] = BARRA_R;
        player->d=2;
    }
}

void sul_player (char tela[ALTURA][LARGURA], player* player){
    if (player->x<ALTURA-3) {
        tela[player->x-1][player->y] = ESPACO;
        player->x++;
        tela[player->x+1][player->y] = BARRA_R;
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

void mover_bola (char tela[ALTURA][LARGURA], Bola* b, player* p1, player* p2, int* reinicia) {
    /*  Toda colisão da bola com o resto do ambiente está contidod aqui*/
       if (b->d == OESTE) {
        if (b->x > 1 && !((b->x == 3 && b->y == p1->x) || (b->x == 3 && b->y == p1->x-1) || (b->x == 3 && b->y == p1->x+1) )) {
            /*  Essa condição define que a bola irá se mover na direção porém irá mudar de direção caso encontre alguma das raquetes.
                Se maior que e diferente de uma das 3 posições da raquete, faça... */
            oeste(tela, b);
        }
        else {
            if (b->x == 3 && b->y == p1->x-1) {
                // Se igual a raquete superior faça...
                som("//sounds//raquete.wav");
                b->d=NORDESTE;
                norte(tela, b);
				leste(tela, b);
            }
            else if (b->x == 3 && b->y == p1->x+1){
                // Se igual a raquete inferior faça...
                som("//sounds//raquete.wav");
                b->d=SULDESTE;
                sul(tela, b);
				leste(tela, b);
            } else if(b->x == 1){
                // Se igual a posição da parede faça...
                *reinicia=3;
                } else {
                // Em qualquer outro caso, mude a direção
                // Só será chamada quando for igual a raquete média
                som("//sounds//raquete.wav");
                b->d = LESTE;
				leste(tela, b);
            }
            
            
        }
    }
    else if (b->d == LESTE) {
        if ((b->x<LARGURA-2)&&!((b->x == LARGURA-4 && b->y == p2->x)|| (b->x == LARGURA-4 && b->y == p2->x-1) || (b->x == LARGURA-4 && b->y == p2->x+1))) {
            leste(tela, b);
        }
        else {
            if (b->x == LARGURA-4 && b->y == p2->x-1) {
                som("//sounds//raquete.wav");
                b->d=NOROESTE;
                norte(tela, b);
				oeste(tela, b);
            } else if (b->x == LARGURA-4 && b->y == p2->x+1){
                som("//sounds//raquete.wav");
                b->d=SULDOESTE;
                sul(tela, b);
				oeste(tela, b);
            } else if(b->x==LARGURA-2){
                *reinicia=2;
            } else  {
                som("//sounds//raquete.wav");
                b->d = OESTE;
				oeste(tela, b);
            }
            
        }
    }
    else if (b->d == NORDESTE) {
        if ( b->y > 2 && (b->x<LARGURA-2) &&!((b->x == LARGURA-4 && b->y == p2->x)|| (b->x == LARGURA-4 && b->y == p2->x-1) || (b->x == LARGURA-4 && b->y == p2->x+1) || (b->x-1 == p2->y && b->y == p2->x))) {
            leste(tela, b);
            norte(tela, b);
        }
        else {
            if (b->x == LARGURA-4 && b->y == p2->x-1) {
                // Se igual a raquete superior faça...
                som("//sounds//raquete.wav");
                b->d=NOROESTE;
                norte(tela, b);
                oeste(tela, b);
            } else if (b->x == LARGURA-4 && b->y == p2->x+1){
                som("//sounds//raquete.wav");
                b->d=SULDOESTE;
                sul(tela, b);
                oeste(tela, b);
            } else if(b->y == 2){
                som("//sounds//parede.wav");
                b->d=SULDESTE;
                sul(tela, b);
                leste(tela, b);
            } else if(b->x==LARGURA-2){
                *reinicia=2;
            } else {
                som("//sounds//raquete.wav");
                b->d = OESTE;
                oeste(tela, b);
                
            }
        }
    }
	else if (b->d == NOROESTE) {
		if (b->y > 2 && b->x>1 && !((b->x == 3 && b->y == p1->x) || (b->x == 3  && b->y == p1->x - 1) || (b->x == 3 && b->y == p1->x + 1) || (b->x == 3 && b->y == p1->x))) {
			norte(tela, b);
			oeste(tela, b);
		}
		else {
		if (b->x == 3 && b->y == p1->x - 1) {
                som("//sounds//raquete.wav");
				b->d = NORDESTE;
				norte(tela, b);
				leste(tela, b);
			} else if (b->x == 3 && b->y == p1->x + 1) {
                som("//sounds//raquete.wav");
				b->d = SULDESTE;
				sul(tela, b);
				leste(tela, b);
			} else if (b->y == 2) {
                som("//sounds//parede.wav");
				b->d = SULDOESTE;
				sul(tela, b);
				oeste(tela, b);
            } else if (b->x==1){
                *reinicia=3;
            } else {
                som("//sounds//raquete.wav");
				b->d = LESTE;
				leste(tela, b);
			}
		}
	}
	else if (b->d == SULDESTE) {
		if (b->y < ALTURA - 2 && b->x<LARGURA-2 && !((b->x == LARGURA-4 && b->y == p2->x) || (b->x == LARGURA-4 && b->y == p2->x - 1) || (b->x == LARGURA-4 && b->y == p2->x + 1) || (b->x == p2->y-1 && b->y == p2->x))) {
			leste(tela, b);
			sul(tela, b);
		}
		else {
			if (b->x == LARGURA-4 && b->y == p2->x - 1) {
                som("//sounds//raquete.wav");
				b->d = NOROESTE;
                norte(tela, b);
				oeste(tela, b);
			}
			else if (b->x == LARGURA-4 && b->y == p2->x + 1) {
                som("//sounds//raquete.wav");
				b->d = SULDOESTE;
				sul(tela, b);
				oeste(tela, b);
			}
			else if (b->y == ALTURA - 2) {
                som("//sounds//parede.wav");
				b->d = NORDESTE;
				leste(tela, b);
				norte(tela, b);
            } else if (b->x==LARGURA-2) {
                *reinicia=2;
            }
			else {
                som("//sounds//raquete.wav");
				b->d = OESTE;
				oeste(tela, b);
			}
		}
	}
	else if (b->d == SULDOESTE) {
		if (b->y < ALTURA - 2 && b->x>1 && !((b->x == 3 && b->y == p1->x) || (b->x == 3 && b->y == p1->x - 1) || (b->x == 3 && b->y == p1->x + 1) || (b->x - 1 == p1->y && b->y == p1->x))){
			sul(tela, b);
			oeste(tela, b);
		}
		else {
			if (b->x == 3 && b->y == p1->x - 1) {
                som("//sounds//raquete.wav");
				b->d = NORDESTE;
				norte(tela, b);
				leste(tela, b);
			} else if (b->x == 3 && b->y == p1->x + 1) {
                som("//sounds//raquete.wav");
				b->d = SULDESTE;
				sul(tela, b);
				leste(tela, b);
			} else if (b->y == ALTURA - 2) {
                som("//sounds//parede.wav");
				b->d = NOROESTE;
				norte(tela, b);
				oeste(tela, b);
            }  else if (b->x==1){
                *reinicia=3;
            }
			else {
                som("//sounds//raquete.wav");
				b->d = LESTE;
				leste(tela, b);
			}
		}
	}

}

void rand_direction (Bola* p){
    srand(time(NULL));
    p->d=rand()%6+2;
}
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

#ifndef Ponto_pong_raquete_h
#define Ponto_pong_raquete_h

#define BARRA_R '|'

typedef struct barra{
    int x;
    int y;
    enum direcao d;
    int score;
} player;

void inicializa_player(char tela[ALTURA][LARGURA], player* player,int n);
void mover_player (char tela[ALTURA][LARGURA], player* player);
void norte_player (char tela[ALTURA][LARGURA], player* player);
void sul_player (char tela[ALTURA][LARGURA], player* player);
void muda_direcao_player2 (player* p, int d, int* reinicia);
void muda_direcao_player1 (player* p, int d);
void mover_bola (char tela[ALTURA][LARGURA], Bola* p, player* p1, player* p2, int* reinicia);
void rand_direction (Bola* p);

#endif

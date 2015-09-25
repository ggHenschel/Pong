/* tela.h */

#ifndef TELA_H
#define TELA_H

#define ALTURA 23
#define LARGURA 51

#define PONTO 'o'
#define ESPACO ' '
#define TETO_E_CHAO '-'
#define PAREDE '-'
#define SCORE "Score"

typedef enum direcao {      //  As Direções definem a forma do
    NORTE,                  //  movimento, tanto da bola,
    SUL,                    //  quanto da "raquete". Desse
    OESTE,                  //  modo há necessidade, de manter
    LESTE,                  //  as direções NORTE e SUL.
    NORDESTE,               //  A utilização dos pontos cardeais
    NOROESTE,               //  foi de modo a simplificar o
    SULDESTE,               //  entendimento e escrita. Compreenda:
    SULDOESTE               //  NORTE como cima; SUL como baixo
} Direcao;                  //  OESTE como esquerda; LESTE como Direita;
                            //  Os outros são composições desses 4.
typedef struct bola {
  int x, y;
  Direcao d;
} Bola;

void inicializa (char tela[ALTURA][LARGURA], Bola* p, int p1score, int p2score);
void desenha (char tela[ALTURA][LARGURA]);
void mover (char tela[ALTURA][LARGURA], Bola* p);
void norte (char tela[ALTURA][LARGURA], Bola* p);
void sul (char tela[ALTURA][LARGURA], Bola* p);
void oeste (char tela[ALTURA][LARGURA], Bola* p);
void leste (char tela[ALTURA][LARGURA], Bola* p);
void muda_direcao (Bola* p, int d);

#endif

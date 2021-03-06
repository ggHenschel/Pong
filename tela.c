/* tela.c */

#include <stdio.h>
#include <string.h>
#include "tela.h"


void inicializa (char tela[ALTURA][LARGURA], Bola* p, int p1score, int p2score) {
  int i, j, k;
  for (i = 0; i < 1; i++) {
	  for (j = 0; j < LARGURA; j++) {
		  tela[i][j] = ESPACO;
		  if (i == 0 && (j == LARGURA / 6 || j == (LARGURA / 4) * 3)) {
              for (k = 0; k < 9; k++){
                  if (k<7) {
                      tela[0][j + k] = "Score:"[k];
                  } else if (k==7){
                      if (j==LARGURA/6)
                          tela[0][j + k] = 48 + (p1score/10);
                      else
                          tela[0][j+k] = 48 + (p2score/10);
                  } else if (k==8){
                      if (j==LARGURA/6)
                          tela[0][j + k] = 48 + (p1score%10);
                      else
                          tela[0][j + k] = 48 + (p2score%10);
                  }
                  
              }
              j += k - 1;
            }
	  }
  }
  for (i = 1; i < ALTURA; i += (ALTURA - 2)) {
    for (j = 0; j < LARGURA; j++) {
      tela[i][j] = TETO_E_CHAO;
    }
  }
  for (i = 2; i < ALTURA - 1; i++) {
    for (j = 0; j < LARGURA; j += (LARGURA - 1)) {
      tela[i][j] = PAREDE;
    }
  }
  for (i = 2; i < ALTURA - 1; i++) {
    for (j = 1; j < LARGURA - 1; j++) {
      tela[i][j] = ESPACO;
    }
  }

  i = ALTURA / 2;
  j = LARGURA / 2;
  tela[i][j] = PONTO;
  p->y = i;
  p->x = j;
}

void desenha (char tela[ALTURA][LARGURA]) {
  int i, j;
  for (i = 0; i < ALTURA; i++) {
    for (j = 0; j < LARGURA; j++) {
      printf("%c", tela[i][j]);
    }
    printf("\n");
  }
}

void mover (char tela[ALTURA][LARGURA], Bola* p) {
  if (p->d == NORTE) {
    if (p->y > 1) {
      norte(tela, p);
    }
    else {
      p->d = SUL;
      sul(tela, p);
    }
  }
  else if (p->d == SUL) {
    if (p->y < ALTURA - 2) {
      sul(tela, p);
    }
    else {
      p->d = NORTE;
      norte(tela, p);
    }
  }
  else if (p->d == OESTE) {
    if (p->x > 1) {
      oeste(tela, p);
    }
    else {
      p->d = LESTE;
      leste(tela, p);
    }
  }
  else if (p->d == LESTE) {
    if (p->x < LARGURA - 2) {
      leste(tela, p);
    }
    else {
      p->d = OESTE;
      leste(tela, p);
    }
  }
}

void norte (char tela[ALTURA][LARGURA], Bola* p) {
  tela[p->y][p->x] = ESPACO;
  p->y--;
  tela[p->y][p->x] = PONTO;
}

void sul (char tela[ALTURA][LARGURA], Bola* p) {
  tela[p->y][p->x] = ESPACO;
  p->y++;
  tela[p->y][p->x] = PONTO;
}

void oeste (char tela[ALTURA][LARGURA], Bola* p) {
  tela[p->y][p->x] = ESPACO;
  p->x--;
  tela[p->y][p->x] = PONTO;
}

void leste (char tela[ALTURA][LARGURA], Bola* p) {
  tela[p->y][p->x] = ESPACO;
  p->x++;
  tela[p->y][p->x] = PONTO;
}
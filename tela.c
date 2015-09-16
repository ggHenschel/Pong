/* tela.c */

#include <stdio.h>
#include "tela.h"

void inicializa (char tela[ALTURA][LARGURA], Ponto* p) {
  int i, j;
  for (i = 0; i < ALTURA; i += (ALTURA - 1)) {
    for (j = 0; j < LARGURA; j++) {
      tela[i][j] = TETO_E_CHAO;
    }
  }
  for (i = 1; i < ALTURA - 1; i++) {
    for (j = 0; j < LARGURA; j += (LARGURA - 1)) {
      tela[i][j] = PAREDE;
    }
  }
  for (i = 1; i < ALTURA - 1; i++) {
    for (j = 1; j < LARGURA - 1; j++) {
      tela[i][j] = ESPACO;
    }
  }
  i = ALTURA / 2;
  j = LARGURA / 2;
  tela[i][j] = PONTO;
  p->x = i;
  p->y = j;
  p->d = NORTE;
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

void mover (char tela[ALTURA][LARGURA], Ponto* p) {
  if (p->d == NORTE) {
    if (p->x > 1) {
      norte(tela, p);
    }
    else {
      p->d = SUL;
      sul(tela, p);
    }
  }
  else if (p->d == SUL) {
    if (p->x < ALTURA - 2) {
      sul(tela, p);
    }
    else {
      p->d = NORTE;
      norte(tela, p);
    }
  }
  else if (p->d == OESTE) {
    if (p->y > 1) {
      oeste(tela, p);
    }
    else {
      p->d = LESTE;
      leste(tela, p);
    }
  }
  else if (p->d == LESTE) {
    if (p->y < LARGURA - 2) {
      leste(tela, p);
    }
    else {
      p->d = OESTE;
      leste(tela, p);
    }
  }
}

void norte (char tela[ALTURA][LARGURA], Ponto* p) {
  tela[p->x][p->y] = ESPACO;
  p->x--;
  tela[p->x][p->y] = PONTO;
}

void sul (char tela[ALTURA][LARGURA], Ponto* p) {
  tela[p->x][p->y] = ESPACO;
  p->x++;
  tela[p->x][p->y] = PONTO;
}

void oeste (char tela[ALTURA][LARGURA], Ponto* p) {
  tela[p->x][p->y] = ESPACO;
  p->y--;
  tela[p->x][p->y] = PONTO;
}

void leste (char tela[ALTURA][LARGURA], Ponto* p) {
  tela[p->x][p->y] = ESPACO;
  p->y++;
  tela[p->x][p->y] = PONTO;
}

void muda_direcao (Ponto* p, int d) {
  if (d == 'a') {
    p->d = OESTE;
  }
  else if (d == 's') {
    p->d = SUL;
  }
  else if (d == 'd') {
    p->d = LESTE;
  }
  else if (d == 'w') {
    p->d = NORTE;
  }
}

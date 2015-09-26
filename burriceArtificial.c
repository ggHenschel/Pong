#include "tela.h"
#include "pong_raquete.h"
#include <time.h>
#include <stdlib.h>

int random_bi() {
	srand(time(NULL));
	return rand() % 10;
}

void player2_CPU(Bola* b, player* p2, int* m_dir) {
	if (b->x < LARGURA / 2 || b->d == NOROESTE || b->d == SULDOESTE || b->d == OESTE) {
		;
	} else if (random_bi() > 0) {
		if (b->y < p2->y) {
			p2->d = NORTE;
			*m_dir = 1;
		} else if (b->y > p2->y) {
			p2->d = SUL;
			*m_dir = 1;
		} else {
			*m_dir = 0;
		}
	} else {
		if (b->y < p2->y - 1) {
			p2->d = NORTE;
			*m_dir = 1;
		}
		else if (b->y > p2->y + 1) {
			p2->d = SUL;
			*m_dir = 1;
		}
		else {
			*m_dir = 0;
		}
	}
}
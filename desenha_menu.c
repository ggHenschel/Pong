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

#include "desenha_menu.h"

void menuStart(char telaInicial[ALTURA][LARGURA]){
	int i, j, k = 0, l = 0;

	for (i = 0; i < ALTURA; i++) {
		for (j = 0; j < LARGURA; j++) {
			telaInicial[i][j] = ESPACO;
		}
	}
	for (i = 0; i < ALTURA; i += ALTURA - 1) {
		for (j = 0; j < LARGURA; j++) {
			telaInicial[i][j] = TETO_E_CHAO;
		}
	}
	for (i = 1; i < ALTURA - 1; i++) {
		for (j = 0; j < LARGURA; j += (LARGURA - 1)) {
			telaInicial[i][j] = PAREDE_MENU;
		}
	}
	for (i = ALTURA - 3; i < ALTURA - 1; i++) {
		for (j = (LARGURA / 2); j < LARGURA; j++, k++) {
			telaInicial[i][j] = CREDITS[k];
			if (CREDITS[k + 1] == '-' || CREDITS[k] == '\0') { j++; k += 2; break; }
		}
	}
	for (j = 15, k = 0; k < strlen(PRESS_START); j++, k++) {
		telaInicial[14][j] = PRESS_START[k];
	}
	// Desenha o ASCII art "Pong"
	for (i = 0; i < ALTURA - 1; i++)
		for (j = 0; j < LARGURA; j++)
		{
			if (i == 2 && j == 4) { for (l = 0, k = 0; PONG_LOGO[l] != '\n'; k++, l++) telaInicial[i][j + k] = PONG_LOGO[l]; j += k - 1; }
			else if (i == 3 && j == 4) { for (k = 0, l++; PONG_LOGO[l] != '\n'; k++, l++) telaInicial[i][j + k] = PONG_LOGO[l]; j += k - 1; }
			else if (i == 4 && j == 4) { for (k = 0, l++; PONG_LOGO[l] != '\n'; k++, l++) telaInicial[i][j + k] = PONG_LOGO[l]; j += k - 1; }
			else if (i == 5 && j == 4) { for (k = 0, l++; PONG_LOGO[l] != '\n'; k++, l++) telaInicial[i][j + k] = PONG_LOGO[l]; j += k - 1; }
			else if (i == 6 && j == 4) { for (k = 0, l++; PONG_LOGO[l] != '\n'; k++, l++) telaInicial[i][j + k] = PONG_LOGO[l]; j += k - 1; }
			else if (i == 7 && j == 4) { for (k = 0, l++; PONG_LOGO[l] != '\n'; k++, l++) telaInicial[i][j + k] = PONG_LOGO[l]; j += k - 1; }
		}
}

void menuInicial(char telaInicial[ALTURA][LARGURA]) {
	int i, j, l=0, k=0;

	for (i = 0; i < ALTURA; i++) {
		for (j = 0; j < LARGURA; j++) {
			telaInicial[i][j] = ESPACO;
		}
	}
	for (i = 0; i < ALTURA; i += (ALTURA - 1)) {
		for (j = 0; j < LARGURA; j++) {
			telaInicial[i][j] = TETO_E_CHAO;
		}
	}
	for (i = 1; i < ALTURA - 1; i++) {
		for (j = 0; j < LARGURA; j += (LARGURA - 1)) {
			telaInicial[i][j] = PAREDE_MENU;
		}
	}
	// Desenha o ASCII art "Pong"
	for (i = 0; i < ALTURA - 1; i++)
		for (j = 0; j < LARGURA; j++)
		{
			if (i == 2 && j == 4) { for (l = 0, k = 0; PONG_LOGO[l] != '\n'; k++, l++) telaInicial[i][j + k] = PONG_LOGO[l]; j += k - 1; }
			else if (i == 3 && j == 4) { for (k = 0, l++; PONG_LOGO[l] != '\n'; k++, l++) telaInicial[i][j + k] = PONG_LOGO[l]; j += k - 1; }
			else if (i == 4 && j == 4) { for (k = 0, l++; PONG_LOGO[l] != '\n'; k++, l++) telaInicial[i][j + k] = PONG_LOGO[l]; j += k - 1; }
			else if (i == 5 && j == 4) { for (k = 0, l++; PONG_LOGO[l] != '\n'; k++, l++) telaInicial[i][j + k] = PONG_LOGO[l]; j += k - 1; }
			else if (i == 6 && j == 4) { for (k = 0, l++; PONG_LOGO[l] != '\n'; k++, l++) telaInicial[i][j + k] = PONG_LOGO[l]; j += k - 1; }
			else if (i == 7 && j == 4) { for (k = 0, l++; PONG_LOGO[l] != '\n'; k++, l++) telaInicial[i][j + k] = PONG_LOGO[l]; j += k - 1; }
		}
	for (i = 0; i <= strlen(onePlayer); i++) {
		telaInicial[ALTURA / 2 + 2][i + (LARGURA / 2 - strlen(onePlayer) / 2)] = onePlayer[i];
	}
	for (i = 0; i <= strlen(twoPlayer); i++) {
		telaInicial[ALTURA / 2 + 3][i + (LARGURA / 2 - strlen(onePlayer) / 2)] = twoPlayer[i];
	}
}

void menuVitoria(char telaInicial[ALTURA][LARGURA], int playerVit){
	int i;

	if (playerVit == 1) {
		for (i = 0; i < 18; i++) {
			telaInicial[ALTURA / 2][LARGURA / 3 + i] = "Player 1 Wins!!!"[i];
		}
	}
	else {
		for (i = 0; i < 18; i++) {
			telaInicial[ALTURA / 2][LARGURA / 3 + i] = "Player 2 Wins!!!"[i];
		}
	}
}

void menuDesenha(char telaInicial[ALTURA][LARGURA]){
	int i, j;
	for (i = 0; i < ALTURA; i++)
	{
		for (j = 0; j < LARGURA; j++)
			printf("%c", telaInicial[i][j]);
		printf("\n");
	}
}

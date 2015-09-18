#include "desenha_menu.h"

void menu()
{
	int i, j, k, l = 0;
	char telaInicial[ALTURA][LARGURA];
	char pongAsciiArt[633];
	// Pong in ASCII art
	for (i = 0; i < ALTURA; i++)
		for (j = 0; j < LARGURA; j++)
		{
			if (i == 2 && j == 4) { for (l = 0, k = 0; PONG_LOGO[l] != '\n'; k++, l++) telaInicial[i][j + k] = PONG_LOGO[l]; j += k - 1; }
			else if (i == 3 && j == 4) { for (k = 0, l++; PONG_LOGO[l] != '\n'; k++, l++) telaInicial[i][j + k] = PONG_LOGO[l]; j += k - 1; }
			else if (i == 4 && j == 4) { for (k = 0, l++; PONG_LOGO[l] != '\n'; k++, l++) telaInicial[i][j + k] = PONG_LOGO[l]; j += k - 1; }
			else if (i == 5 && j == 4) { for (k = 0, l++; PONG_LOGO[l] != '\n'; k++, l++) telaInicial[i][j + k] = PONG_LOGO[l]; j += k - 1; }
			else if (i == 6 && j == 4) { for (k = 0, l++; PONG_LOGO[l] != '\n'; k++, l++) telaInicial[i][j + k] = PONG_LOGO[l]; j += k - 1; }
			else if (i == 7 && j == 4) { for (k = 0, l++; PONG_LOGO[l] != '\n'; k++, l++) telaInicial[i][j + k] = PONG_LOGO[l]; j += k - 1; }

			else if (i == 12 && j == 15) { for (k = 0; k < strlen(PRESS_START); k++) telaInicial[i][j + k] = PRESS_START[k]; j += k - 1; }
			else if (i == 17 && j == 25) { for (k = 0; k < strlen(CREDITS_1); k++) telaInicial[i][j + k] = CREDITS_1[k]; j += k - 1; }
			else if (i == 18 && j == 27) { for (k = 0; k < strlen(CREDITS_2); k++) telaInicial[i][j + k] = CREDITS_2[k]; j += k - 1; }
			else if (i == 0 || i == ALTURA - 1) telaInicial[i][j] = TETO_E_CHAO;
			else if (j == 0 || j == LARGURA - 1) telaInicial[i][j] = PAREDE;
			else (telaInicial[i][j] = ESPACO);
		}
	for (i = 0; i < ALTURA; i++)
	{
		for (j = 0; j < LARGURA; j++)
			printf("%c", telaInicial[i][j]);
		printf("\n");
	}
}

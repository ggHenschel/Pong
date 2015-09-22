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

#ifndef menuPrincipal

#include <stdio.h>
#include <string.h>

#define ALTURA 22
#define LARGURA 51
#define PONTO 'o'
#define ESPACO ' '
#define TETO_E_CHAO '-'
#define PAREDE2 '|'
#define PRESS_START "PRESS ENTER TO START"
#define CREDITS "By Guilherme Henschel-" \
				"  and Rafael Teixeira"
#define PONG_LOGO "__________\n"\
				  "\\______   \\____   ____    ____\n"\
				  " |     ___/  _ \\ /    \\  / ___\\ \n"\
				  " |    |  (  <_> )   |  \\/ /_/  >\n"\
				  " |____|   \\____/|___|  /\\___  /\n"\
				  "                     \\//_____/  \n"

void menuInic(char telaInicial[ALTURA][LARGURA]);
void menuDesenha(char telaInicial[ALTURA][LARGURA]);

#endif

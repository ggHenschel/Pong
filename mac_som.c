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

#include "mac_som.h"
#include <string.h>
#include <stdio.h>
#define BUFFSIZE 1023
#define S(x) #x
#define SX(x) S(x)


void mac_som(char* path, char tela[ALTURA][LARGURA]){
    char cwd[BUFFSIZE];
    int bufsize = sizeof(cwd);
    system("pwd");
    _NSGetExecutablePath(cwd,&bufsize);
    chdir(cwd);
    strcat(cwd, path);
    printf("%s\n",cwd);
    printf("%s\n", S(cwd));         //Até aqui funciona tão bonito
    pid_t pid = fork();
    if (pid!=0)
        printf("IMPOSSIBLE TO TREAD!");
    else{
        execlp("afplay","-d", cwd);
        system("clear");
        desenha(tela);
    }
}
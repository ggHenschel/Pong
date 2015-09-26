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

#ifndef _WIN32

#include "mac_som.h"
#include <string.h>
#include <stdio.h>
#define BUFFSIZE 1023

//ESTÁ FUNCIONANDO NÃO MEXA

void mac_som(char* path, char tela[ALTURA][LARGURA]){
    char cwd[BUFFSIZE],cwdf[BUFFSIZE];
    int bufsize = sizeof(cwd);
    int counter=0;
    //system("pwd");
    _NSGetExecutablePath(cwd,&bufsize);
    while (cwd[counter]!='\0') {
        counter+=1;
    }
    for (int i=0; i<counter-6; i++) {
        cwdf[i]=cwd[i];
    }
    cwdf[counter-6]='\0';
    //printf("%s\n",cwdf);
    strcat(cwdf, path);
    //printf("%s\n",cwdf);
    //pid_t pid = vfork();
    if (vfork()!=0){
        //printf("IMPOSSIBLE TO TREAD!\n");
    }
    else{
        execlp("afplay","-d",(char *)cwdf, NULL);
        _exit(EXIT_FAILURE);
        
    }
}

#endif
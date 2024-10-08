// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022

//Lara Filipa Da Silva Bizarro
//2021130066
//Engenharia Informática

#ifndef MATDIN_H
#define MATDIN_H

#include <stdlib.h>
#include <stdio.h>

// Liberta uma matriz dinâmica de caracteres com nLin linhas
void libertaMat(char** p, int nLin);

// Cria uma matriz dinâmica de caracteres  com nLin linhas e nCol colunas
// Devolve endereço inicial da matriz
char** inicializa_tab(int nLin, int nCol);

// Imprime o conteúdo de uma matriz dinâmica de caracteres
void escreve_tab(char **p);

// Coloca o caracter c na posição (x, y) de uma matriz dinâmica de caracteres
void setPos(char **p, int *x, int *y, char c);

// Obtém o caracter armazenado na posição (x, y) de uma matriz de caracteres
char getPos(char **p, int *x, int *y);

#endif

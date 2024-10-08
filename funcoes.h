// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022

//Lara Filipa Da Silva Bizarro
//2021130066
//Engenharia Inform�tica

#ifndef funcoes_h

#define funcoes_h
#define N	9
#define M   3

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

// Menu inicial- instru��es + tipo de jogo (contra pessoa ou computador
void menu_jogar();

//Instru��es
void instrucoes();

//Escolher um tabuleiro aleatoriamente
int escolha_tab();

//Obtem as coordenadas do array atrav�s da posi�ao
int conversao(int pos, int *px, int *py,int tabuleiro);

//Obtem as coordenadas do inicio de cada tabuleiro para as valida��es
 void conversao_validar(int tabuleiro,int *px,int *py);

//Valida��o por linha-verifica se h� linhas com o mesmo caracter
int linha_validar (char **p, int *px, int *py);

//Valida��o por coluna-verifica se h� colunas com o mesmo caracter
int coluna_validar(char **p, int *px, int *py);

//Valida��o por diagonal-verifica se h� diagonais com o mesmo caracter
int diag_validar(char **p, int *px, int *py);

//Verifica se o tabuleiro est� preenchido/empatado
int tab_cheio(char **p, int *px, int *py);

//Valida��o dos tabuleiros- verifica se h� tabuleiros em linhas, colunas ou diagonais com o mesmo caracter
int ganhou_jogo(int t_ocupado[N]);

//Verifica se ainda h� tabuleiros dispon�veis
int tabDisponivel(int t_ocupado[N]);

//Escreve quem ganhou ou empate
void escreve_resultado(int ganhou);
#endif


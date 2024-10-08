// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022

//Lara Filipa Da Silva Bizarro
//2021130066
//Engenharia Informática

#ifndef funcoes_h

#define funcoes_h
#define N	9
#define M   3

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

// Menu inicial- instruções + tipo de jogo (contra pessoa ou computador
void menu_jogar();

//Instruções
void instrucoes();

//Escolher um tabuleiro aleatoriamente
int escolha_tab();

//Obtem as coordenadas do array através da posiçao
int conversao(int pos, int *px, int *py,int tabuleiro);

//Obtem as coordenadas do inicio de cada tabuleiro para as validações
 void conversao_validar(int tabuleiro,int *px,int *py);

//Validação por linha-verifica se há linhas com o mesmo caracter
int linha_validar (char **p, int *px, int *py);

//Validação por coluna-verifica se há colunas com o mesmo caracter
int coluna_validar(char **p, int *px, int *py);

//Validação por diagonal-verifica se há diagonais com o mesmo caracter
int diag_validar(char **p, int *px, int *py);

//Verifica se o tabuleiro está preenchido/empatado
int tab_cheio(char **p, int *px, int *py);

//Validação dos tabuleiros- verifica se há tabuleiros em linhas, colunas ou diagonais com o mesmo caracter
int ganhou_jogo(int t_ocupado[N]);

//Verifica se ainda há tabuleiros disponíveis
int tabDisponivel(int t_ocupado[N]);

//Escreve quem ganhou ou empate
void escreve_resultado(int ganhou);
#endif


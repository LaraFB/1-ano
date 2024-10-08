#include "funcoes.h"

#define N	9
#define M   3

void menu_jogar(){

    printf("\nEscolha opção de jogo\n");
    printf("\nI- Instruções\n");
    printf("\nP- Jogar contra outra pessoa\n");
    printf("\nC- Jogar contra o computador\n\n");
}

void instrucoes(){
    printf("   O objetivo do jogo é fazer uma sequência de três símbolos iguais, seja em linha vertical, horizontal ou diagonal,\n   enquanto tenta impedir que seu adversário faça o mesmo;O jogador que ganhe um tabuleiro volta a jogar.\n\n   Quando um dos participantes faz uma linha, ganha no tabuleiro em que se encontra.\n\n   Para ganhar o jogo aplica as mesmas regras, mas nos tabuleiros!\n   Ou seja, terá de fazer com que 3 tabuleiros fiquem com o mesmo simbolo (na horizontal ou na vertical ou na diagonal)!");
    printf("\n---------------------------------------------------------------------------------------------------------------------");
    printf("\n                  Para sair do jogo, introduzir número inferior a 0 (p.e. -1).\n");
    printf("\n                  Se não quiser ver nenhuma jogada, introduza 0.\n");
    printf("\n---------------------------------------------------------------------------------------------------------------------");
    printf("\n\n\n   BOA SORTE!!\n\n\n");
}

int escolha_tab(){

    int escolha_tab;

    srand(time(NULL));
    escolha_tab= 1+rand()%9;

    return escolha_tab;
}

int conversao(int pos, int *px, int *py,int tabuleiro){

    int x,y;

    switch (tabuleiro){
        case 1:
            y=(pos-1)/M;
            x=(pos-1)%M;
        break;
        case 2:
            y=(pos-1)/M;
            x=(pos-1)%M+M;
        break;
        case 3:
            y=(pos-1)/M;
            x=(pos-1)%M+(M+M);
        break;
        case 4:
            y=(pos-1)/M+M;
            x=(pos-1)%M;
        break;
        case 5:
            y=(pos-1)/M+M;
            x=(pos-1)%M+M;
        break;
        case 6:
            y=(pos-1)/M+M;
            x=(pos-1)%M+(M+M);
        break;
        case 7:
            y=(pos-1)/M+(M+M);
            x=(pos-1)%M;
        break;
        case 8:
            y=(pos-1)/M+(M+M);
            x=(pos-1)%M+M;
        break;
        default:
            y=(pos-1)/M+(M+M);
            x=(pos-1)%M+(M+M);
        break;

    }

    *px= x;
    *py= y;
}

 void conversao_validar(int tabuleiro,int *px,int *py){

    int x,y;

    switch (tabuleiro){
        case 1:
            y=0;
            x=0;
        break;
        case 2:
            y=0;
            x=3;
        break;
        case 3:
            y=0;
            x=6;
        break;
        case 4:
            y=3;
            x=0;
        break;
        case 5:
            y=3;
            x=3;
        break;
        case 6:
            y=3;
            x=6;
        break;
        case 7:
            y=6;
            x=0;
        break;
        case 8:
            y=6;
            x=3;
        break;
        default:
            y=6;
            x=6;
        break;

    }

    *px= x;
    *py= y;
}

int linha_validar (char **p, int *px, int *py){
	int i, j;
    i=*px;

    for (j=*py;j<(*py+3);j++){
       if(p[j][i] == p[j][i+1] && p[j][i+1] == p[j][i+2]&& p[j][i]!='_'){
           return 1;
       }
    }
    return 0;
 }


int coluna_validar(char **p, int *px, int *py){
    int i, j;
    j=*py;

    for (i=*px;i<(*px+3);i++){
       if(p[j][i] == p[j+1][i] && p[j+1][i] == p[j+2][i]&& p[j][i]!='_'){

           return 1;
       }
    }
    return 0;
}


int diag_validar(char **p, int *px, int *py){
    int i, j;
    j=*py;
    i=*px;

   if(p[j][i] == p[j+1][i+1] && p[j][i] == p[j+2][i+2]&& p[j][i]!='_'){
       return 1;
   }
   if(p[j][i+2] == p[j+1][i+1] && p[j][i+2] == p[j+2][i]&& p[j][i+2]!='_'){
       return 1;
   }

    return 0;
}

int tab_cheio(char **p, int *px, int *py){
    int i,j;

    for (j=*py;j<(*py+3);j++){
            for (i=*px;i<(*px+3);i++){
                if(p[j][i]=='_')
                return 0;
            }
    }
    return 1;
}

int ganhou_jogo(int t_ocupado[N]){

    int i,j=0;

    for(i=0;i<N;i=i+3){
        if(t_ocupado[i]==t_ocupado[i+1] && t_ocupado[i]==t_ocupado[i+2]&& t_ocupado[i]!=0&& t_ocupado[i]!=3)
            return 1;
    }

    for(i=0;i<M;i++){
        if(t_ocupado[i]==t_ocupado[i+3] && t_ocupado[i]==t_ocupado[i+6]&& t_ocupado[i]!=0&& t_ocupado[i]!=3)
            return 1;
    }

    if(t_ocupado[0]==t_ocupado[4] && t_ocupado[0]==t_ocupado[8]&& t_ocupado[0]!=0&& t_ocupado[0]!=3)
        return 1;

    if(t_ocupado[2]==t_ocupado[4] && t_ocupado[2]==t_ocupado[6]&& t_ocupado[2]!=0&& t_ocupado[2]!=3)
        return 1;

    return 0;
}

int tabDisponivel(int t_ocupado[N]){
    for(int i=0;i<N;i++){
        if (t_ocupado[i]==0){
            return 1;
        }
    }
    return 0;
}


void escreve_resultado(int ganhou){
	if(ganhou == 1)
        printf("\nGanhou o jogador %d\n\n", ganhou);
    else if(ganhou == 2)
        printf("\nGanhou o jogador %d\n\n", ganhou);
	else
		printf("\nEmpate\n\n");
}

#include "matdin.h"
#define N 9

void libertaMat(char** p, int nLin){

    int i;

    for(i=0; i<nLin; i++)
        free(p[i]);
    free(p);
}

char** inicializa_tab(int nLin, int nCol){
    char **p = NULL;
    int i, j;

    p = malloc(sizeof(char*) * nLin);
    if(p == NULL)
        return NULL;

    for(i=0; i<nLin; i++){
        p[i] = malloc(sizeof(char) * nCol);
        if(p[i] == NULL){
            libertaMat(p, i-1);
            return NULL;
        }
        for(j=0; j<nCol; j++)
            p[i][j] = '_';
    }
    return p;
}

void setPos(char **p, int *x, int *y, char c){
    p[*x][*y] = c;
}

char getPos(char **p, int *x, int *y){
    return p[*x][*y];
}

void escreve_tab(char **p){
    int i,j;

    for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			printf(" %c ", p[i][j]);
			if ((j+1)%3==0&&j<6){
                printf(" | ");
            }

		}
        printf(" \n");
        for(j=0; j<N; j++){
            if (((i+1)%3==0&&i<6)&&((j+1)%3==0)){
                    printf(" _________ ");
            }
            if((j==(N-1))&&((i+1)%3==0)){
                    printf(" \n");
            }
        }

    }
}

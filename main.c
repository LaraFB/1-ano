//Lara Filipa Da Silva Bizarro
//2021130066
//Engenharia Inform�tica

#include "matdin.c"
#include "funcoes.c"

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

#define N	9
#define M   3

typedef struct jogada jogadas, *pjogada;
struct jogada{
    int jogada;
    int jogador;
    int tabuleiro;
    pjogada ant;
    pjogada prox;
};

// Lista ordenada
pjogada insere_jogada(pjogada p, int jogada, int jogador, int tabuleiro){
    pjogada novo;

    if((novo = malloc(sizeof(jogadas))) == NULL)
        printf("Erro na alocacao de memoria\n");

    else{
        novo->jogada = jogada;
        novo->jogador = jogador;
        novo->tabuleiro = tabuleiro;
        novo->prox = p;
        novo->ant = NULL;
        if (p!=NULL)
            p->ant=novo;
        p = novo;
    }
    return p;
}

//Escreve no ficheiro texto a informa��o da lista ligada e mais umas informa��es adicionais
int escreve_ficheiro_txt(pjogada lista){
    char nome_ficheiro[1000];

    FILE *f;
    pjogada *atual;

    printf("\nIntroduzir nome do ficheiro: ");
    scanf("%s",&nome_ficheiro);
    strcat(nome_ficheiro,".txt");

    f = fopen(nome_ficheiro, "w");

    if(f==NULL)
        return 0;
    else{

        while(lista != NULL){
            atual = lista;
            lista = lista->prox;
        }
        lista = atual;

        while(lista != NULL) {
            fprintf(f, "tabuleiro: %d, posi��o: %d, jogador: %d\n", lista->tabuleiro,
            lista->jogada, lista->jogador);
            lista = lista->ant;
        }
        fclose(f);
    }
    return 1;
}

//Escreve no ficheiro bin�rio a informa��o da lista ligada
int escreve_ficheiro_bin(pjogada lista, char opcao){
    FILE *f;
    pjogada *atual;
    int numElem=0;

    f = fopen("jogo.bin", "wb");

    if(f==NULL)
        return 0;
    else{
        fwrite(&opcao, sizeof(char), 1, f);

        while(lista != NULL){
            atual = lista;
            lista = lista->prox;
            numElem ++;
        }
        lista = atual;
        fwrite(&numElem, sizeof(int), 1, f);

        while(lista != NULL) {
            fwrite(&lista->tabuleiro, sizeof(int), 1, f);
            fwrite(&lista->jogada, sizeof(int), 1, f);
            fwrite(&lista->jogador, sizeof(int), 1, f);
            //fwrite(&lista, sizeof(jogadas), 1, f);

//            printf("\ntabuleiro: %d, posi��o: %d, jogador: %d\n", lista->tabuleiro,
//            lista->jogada, lista->jogador);
            lista = lista->ant;
        }
        fclose(f);
    }
    return 1;
}

//Mostra as jogadas de 1 a 10 no inicio do jogo
void ver_jogadas(pjogada lista){
    int numJogadas;
    pjogada *atual;
    atual=NULL;

    do{
        printf("\nIntroduzir n�mero de jogadas a ver (1-10): ");
        if (scanf(" %d", &numJogadas) != 1){
                printf("\n!!!Valor inv�lido!!!\n");
                fflush(stdin);
        }

    }while(numJogadas<0 || numJogadas>10);


    if(numJogadas==0)
        return;

    while(lista != NULL && numJogadas>=1){
            atual = lista;
            lista = lista->prox;
            numJogadas --;
    }
    lista = atual;

    while(lista != NULL) {
            printf("\ntabuleiro: %d, posi��o: %d, jogador: %d\n", lista->tabuleiro,
            lista->jogada, lista->jogador);
        lista = lista->ant;
    }

}


int main (){
    setlocale(LC_ALL, "Portuguese");
    FILE *f;

	char* tab;
	int joga, n_jogadas, ganhou, desempate_escolha, tabuleiro=0, pos, i, j;
	int px, py;
    char opcao;
    int tab_ocupado[N];
    char xo;
    pjogada *lista = NULL;

    joga=1;
	n_jogadas=0;
	ganhou=0;
	opcao='-';

	for(i=0;i<N;i++){
        tab_ocupado[i]=0;
	}

    tab=inicializa_tab(N,N);
    tabuleiro=escolha_tab();

    f=fopen("jogo.bin", "rb");

    if(f!=NULL){
            printf("\nPretende continuar o jogo anterior? S (sim)/ N (não)\n");
            scanf(" %c", &opcao);

            while(opcao != 'S' && opcao!='s'&& opcao!='N'&&opcao!='n'){
                printf("[%c] Não é uma opção válido\n", opcao);
                scanf(" %c", &opcao);
            }

            if(opcao=='S'||opcao=='s'){

                int total;

                total = 0;
                fread(&opcao, sizeof(char), 1, f);
                fread(&total, sizeof(int), 1, f);
                system("cls");

                for (int k=0;k<total;k++){

                    fread(&tabuleiro, sizeof(int), 1, f);
                    fread(&pos, sizeof(int), 1, f);
                    fread(&joga, sizeof(int), 1, f);

                    lista=insere_jogada(lista, pos, joga, tabuleiro);
                    conversao(pos,&px,&py,tabuleiro);

                    if(joga==1)
                        setPos(tab,&py,&px,'X');
                    else
                        setPos(tab,&py,&px,'O');

                    conversao_validar(tabuleiro,&px,&py);

                    if(linha_validar(tab,&px,&py)==1 || coluna_validar(tab,&px,&py)==1 || diag_validar(tab,&px,&py)==1){
                        tab_ocupado[tabuleiro-1]=joga;
                        if(joga==1){
                            xo='X';
                        }
                        else{
                            xo='O';
                        }
                        for(i=py;i<py+3;i++){
                            for(j=px;j<px+3;j++){
                                setPos(tab,&i,&j,xo);
                            }
                        }
                    }
                    else
                    joga = joga%2 + 1;
                }
            }
            fclose(f);

            if(opcao=='N'||opcao=='n'){
                remove("jogo.bin");
                system("cls");
                opcao='-';
            }
    }

    if (opcao == '-'){

        do{
            menu_jogar();
            scanf(" %c", &opcao);
            if(opcao=='I'|| opcao=='i'){
                instrucoes();
            }
        }while(opcao=='I'||opcao=='i');

        while(opcao != 'C' && opcao != 'c' && opcao != 'p' && opcao != 'P' ){
                printf("[%c] N�o � uma op��o v�lido\n", opcao);
                scanf(" %c", &opcao);
        }
    }

        system("cls");


        do{
                printf("Para sair do jogo, introduzir n�mero inferior a 0 (p.e. -1)\n");
                printf("Se n�o quiser ver nenhuma jogada, introduza 0.\n\n\n");
                escreve_tab(tab);

                do{


                    while(tab_ocupado[(tabuleiro-1)]!=0){
                        /*tabuleiro++;
                        if (tabuleiro == 10)
                           tabuleiro=1;
                        */
                        tabuleiro=escolha_tab();
                    }

                    printf("\nTabuleiro: %d\n",tabuleiro);

                    if (joga==2 && (opcao=='C'||opcao=='c')){
                        pos= (rand()%8)+1;
                    }
                    else {
                        ver_jogadas(lista);
                        printf("\n� a vez do jogador %d\n", joga);
                        printf("Posi��o: ");
                        if (scanf(" %d", &pos) != 1){
                            printf("\n!!!Valor inv�lido!!!\n");
                            fflush(stdin);
                        }
                    }
                    if (pos<0){
                        printf("Vou sair");
                        escreve_ficheiro_bin(lista,opcao);
                        escreve_ficheiro_txt(lista);
                        return 0;
                    }

                    conversao(pos,&px,&py,tabuleiro);

                }while(pos<1 || pos>M*M || getPos(tab,&py,&px) != '_');

                if(joga==1)
                    setPos(tab,&py,&px,'X');
                else
                    setPos(tab,&py,&px,'O');

                lista = insere_jogada(lista, pos, joga, tabuleiro);
                conversao_validar(tabuleiro,&px,&py);

                if(tab_cheio(tab, &px, &py)==1){
                    tab_ocupado[tabuleiro-1]=3;
                }


                if(linha_validar(tab,&px,&py)==1 || coluna_validar(tab,&px,&py)==1 || diag_validar(tab,&px,&py)==1){
                    tab_ocupado[tabuleiro-1]=joga;
                    if(joga==1){
                        xo='X';
                    }
                    else{
                        xo='O';
                    }
                    for(i=py;i<py+3;i++){
                                    for(j=px;j<px+3;j++){
                                        setPos(tab,&i,&j,xo);

                                    }
                                }
                    //printf("\nJogador %d ganhou o tabuleiro %d!\n\n",joga,tabuleiro);

                }
                else
                    joga = joga%2 + 1;

                tabuleiro=pos;
                n_jogadas ++;
                system("cls");

        }while( n_jogadas < N*N && ganhou_jogo(tab_ocupado)==0 && tabDisponivel(tab_ocupado)==1);

        system("cls");

        escreve_tab(tab);
        escreve_resultado(joga);
        libertaMat(tab, N);
        escreve_ficheiro_txt(lista);

        return 0;
}

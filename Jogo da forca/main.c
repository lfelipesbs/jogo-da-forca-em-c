#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "forca.c"
#include "termforca.h"

char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesdados = 0;

int main(void){

    escolhepalavra(palavrasecreta);
    abertura();

    do{
        desenhaforca();
        imprimepalavra(palavrasecreta, chutesdados, chutes);
        chuta(&chutesdados, chutes);

    }while(!acertou(palavrasecreta, chutesdados, chutes) && !enforcou());

    desenhaforca();

    if(acertou(palavrasecreta, chutesdados, chutes)){
        printf("PARABENS!!! VOCE GANHOU!\n");
        adicionapalavra();
    }else{
        printf("Voce perdeu, boa sorte na proxima vez!\n");
        printf("A palavra era **%s**\n",palavrasecreta);
    }
}

void abertura(){
    printf("*****************\n");
    printf("* JOGO DE FORCA *\n");
    printf("*****************\n\n");
}

void desenhaforca(){

    int erros = chuteserrados(chutesdados, palavrasecreta, chutes);

    printf("                  \n");
    printf("  ________        \n");
    printf(" |/       |       \n");
    printf(" |       %c%c%c   \n", (erros >= 1 ? '(':' '), (erros >= 1 ? '_':' '), (erros >= 1 ? ')':' '));
    printf(" |       %c%c%c   \n", (erros >= 3 ? '_':' '), (erros >= 2 ? '|':' '), (erros >= 4 ? '_':' '));
    printf(" |        %c      \n", (erros >= 2 ? '|':' '));
    printf(" |       %c %c    \n", (erros >= 5 ? '/':' '),( erros >= 6 ? '\\':' '));
    printf(" |                \n");
    printf("_|___             \n");
    printf("\n\n");

}

void adicionapalavra(){

    char quer;

    printf("Voce deseja adicionar uma nova palavra no jogo? (S/N)");
    scanf(" %c", &quer);

    if(quer == 'S'||quer == 's'){

        char novapalavra[TAMANHO_PALAVRA];

        printf("Qual a nova palavra? ");
        scanf("%19s", novapalavra);

        FILE* f;

        f = fopen("palavras.txt","r+");
        if(f == NULL){
            printf("Desculpe, banco de dados nao disponivel\n\n");
            exit(1);
        }

        int qtd;

        fscanf(f,"%d", &qtd);
        qtd++;

        fseek(f, 0, SEEK_SET);
        fprintf(f,"%d",qtd);

        fseek(f, 0, SEEK_END);
        fprintf(f,"\n%s", novapalavra);

        fclose(f);
    }
}

int enforcou(){
    return chuteserrados(chutesdados, palavrasecreta, chutes) >= 6;
}
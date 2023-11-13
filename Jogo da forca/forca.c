#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "forca.h"

void escolhepalavra(char p[TAMANHO_PALAVRA]){
    FILE* f;

    f = fopen("palavras.txt","r");
    if(f == NULL){
        printf("Desculpe, banco de dados nao disponivel\n\n");
        exit(1);
    }

    int qtddepalavras;
    fscanf(f,"%d", &qtddepalavras);

    srand(time(NULL));
    int linha = rand() % qtddepalavras;
    for(int i=0; i<=linha; i++){
        fscanf(f,"%s", p);
    }
    fclose(f);
}

int acertou(char p[TAMANHO_PALAVRA], int c, char a[26]){
    for(int i=0; i<strlen(p); i++){

        int achou = 0;

        jachutou(&achou,i,c,p,a);

        if(!achou){
            return 0;
        }
    }
    return 1;
}

int chuteserrados(int c, char p[TAMANHO_PALAVRA], char a[26]){
    int erros = 0;

    for(int i=0; i<c; i++){
        int existe = 0;

        for(int j=0; j<strlen(p); j++){
            if(a[i] == p[j]){
                existe = 1;
                break;
            }
        }
        if(!existe) erros++;
    }
    return erros;
}

void imprimepalavra(char p[TAMANHO_PALAVRA], int c, char a[26]){
    for(int i=0; i<strlen(p); i++){

        int achou = 0;

        jachutou(&achou,i,c,p,a);
            
        if(achou){
            printf("%c ",p[i]);
        }else{
            printf("_ ");
        }
    }
    printf("\n\n");
}

void chuta(int* c, char a[26]){
    char chute;
    scanf(" %c", &chute);

    a[(*c)] = chute;
    (*c)++;
}

void jachutou(int* achou,int i, int c, char p[TAMANHO_PALAVRA], char a[26]){
    for(int j=0; j<c; j++){
        if(a[j] == p[i]){
            (*achou) = 1;
            break;
        }
    }
}
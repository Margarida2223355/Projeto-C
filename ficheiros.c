#include <stdio.h>
#include <stdlib.h>

//#include "funcoes.c"

#define caminho "E://FP//Projeto-C//Files//participantes.dat"

FILE *ficheiro;
//
//void abrir_ficheiro() {
//    ficheiro = fopen("participantes.dat", "ab");
//
//    if (ficheiro == NULL) {
//        printf("Ficheiro participantes nao foi aberto!\n");
//    }
//
//    else {
//        printf("Ficheiro participantes aberto com sucesso!\n");
//    }
//
//    ficheiro = fopen("inscricoes.dat", "ab");
//
//    if (ficheiro == NULL) {
//        printf("Ficheiro inscricoes nao foi aberto!\n");
//    }
//
//    else {
//        printf("Ficheiro inscricoes aberto com sucesso!\n");
//    }
//
//    ficheiro = fopen("atividades.dat", "ab");
//
//    if (ficheiro == NULL) {
//        printf("Ficheiro atividades nao foi aberto!\n");
//    }
//
//    else {
//        printf("Ficheiro atividades aberto com sucesso!\n");
//    }
//}

void fechar_ficheiros() {
    fclose(ficheiro);
}

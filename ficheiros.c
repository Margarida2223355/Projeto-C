#include <stdio.h>
#include <stdlib.h>

#include "funcoes.c"

#define caminho "E://FP//Projeto-C//Files//participantes.dat"

FILE *ficheiro;

void abrir_ficheiro() {
    ficheiro = fopen(ficheiro, "rb");

    if (ficheiro == NULL) {
        printf("Ficheiro não existe!");
        ficheiro = fopen("participantes.dat", "ab");
        limpar_console();
    }

    else {
        printf("Ficheiro existe!");
    }
}

void fechar_ficheiro() {
    fclose(ficheiro);
}

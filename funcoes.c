#include <stdio.h>
#include <stdlib.h>
#include "dados.c"


int registrar_participante(int ultimo_participante){
    getchar();

        printf("Nome:");
        gets(participante[ultimo_participante].nome);
        printf("Email: ");
        gets(participante[ultimo_participante].email);
        participante[ultimo_participante].id_part = ultimo_participante;
        printf("Escola: ");
        gets(participante[ultimo_participante].escola);
        fflush(stdin);
        printf("NIF: ");
        scanf("%d", &participante[ultimo_participante].nif);
        printf("Telefone: ");
        scanf("%d", &participante[ultimo_participante].telefone);
        ultimo_participante++;

    return ultimo_participante;
}

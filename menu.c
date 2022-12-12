#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "funcoes.c"

int ultimo_participante = 0;
int menu_principal(){
    int resposta;

    printf("\n*****Menu principal*****\n");
    printf("1-Registrar\n");
    printf("2-Consultar\n");
    printf("3-Estatisticas\n");
    printf("0-Sair\n");

    scanf("%d", &resposta);

    return resposta;
}

int menu_registros(){
    int resposta;

    printf("\n*****Menu de registros*****\n");
    printf("1-Registrar participantes\n");
    printf("2-Registrar atividades\n");
    printf("3-Registrar inscricoes\n");
    printf("0-Sair\n");

    //proximas 4 linhas sao apenas para testar a função de registrar participantes
    scanf("%d", &resposta);
    ultimo_participante = registrar_participante(ultimo_participante);

    for(int i = 0; i < ultimo_participante; i++){
        printf("%s numero %d\n", participante[i].nome, participante[i].id_part);
    }

    return resposta;
}

int menu_consultas(){
    int resposta;

    printf("\n*****Menu de consultas*****\n");
    printf("1-Consultar participantes\n");
    printf("2-Consultar atividades\n");
    printf("3-Consultar inscricoes\n");
    printf("0-Sair\n");

    scanf("%d", &resposta);

    return resposta;
}

int menu_estatisticas(){
    int resposta;

    printf("\n*****Menu de estatisticas*****\n");
    printf("1-Número de atividades realizadas por cada associacao\n");
    printf("2-Percentagem de inscrições por escola\n");
    printf("3-Valor total das inscrições entre duas datas (horizonte temporal) por tipo de atividade\n");
    printf("0-Sair\n");

    scanf("%d", &resposta);

    return resposta;
}

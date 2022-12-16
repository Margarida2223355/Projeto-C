#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "funcoes.c"

int ultimo_participante = 0;
int ultima_atividade = 0;
int menu_principal(){
    int resposta;
    limpar_console();

    printf("\n*****Menu principal*****\n");
    printf("1-Registrar\n");
    printf("2-Consultar\n");
    printf("3-Estatisticas\n");
    printf("0-Sair\n");
    printf("************************\n");

    scanf("%d", &resposta);

    return resposta;
}

int menu_registros(){
    int resposta;
    limpar_console();

    do{
        printf("\n*****Menu de registros*****\n");
        printf("1-Registrar participantes\n");
        printf("2-Registrar atividades\n");
        printf("3-Registrar inscricoes\n");
        printf("0-Sair\n");
        printf("***************************\n");

        scanf("%d", &resposta);

        switch(resposta){
            case 1:
                ultimo_participante = registrar_participante(ultimo_participante);
                break;
            case 2:
                ultima_atividade = registrar_atividade(ultima_atividade);
                break;
            case 3:
                //registrar_inscricoes()
                break;
            default:
                if(resposta != 0)
                    printf("Digite o numero correspondente a uma das opçoes do menu\n");
        }
    } while(resposta != 0);

    return resposta+1;// retorna true para voltar ao menu_principal
}

int menu_consultas(){
    int resposta, busca, encontrado;
    limpar_console();

    do{
        printf("\n*****Menu de consultas*****\n");
        printf("1-Consultar participantes\n");
        printf("2-Consultar atividades\n");
        printf("3-Consultar inscricoes\n");
        printf("0-Sair\n");
        printf("***************************\n");

        scanf("%d", &resposta);

        switch(resposta){
            case 1:
                printf("Digite o Id do aluno: ");
                scanf("%d", &busca);
                encontrado = consultar_participante(busca, ultimo_participante);
                if(encontrado == 0)
                    printf("Aluno nao encontrado!\n");
                break;
            case 2:
                printf("Digite o Id da atividade: ");
                scanf("%d", &busca);
                encontrado = consultar_atividade(busca, ultima_atividade);
                if(encontrado == 0)
                    printf("Atividade nao encontrada!\n");
                break;
            case 3:
                //consultar_inscricoes()
                break;
            default:
                if(resposta != 0)
                    printf("Digite o numero correspondente a uma das opçoes do menu\n");
        }
    }while(resposta != 0);
    return resposta+1;// retorna true para voltar ao menu_principal
}

int menu_estatisticas(){
    int resposta;
    limpar_console();

    printf("\n*****Menu de estatisticas*****\n");
    printf("1-Número de atividades realizadas por cada associacao\n");
    printf("2-Percentagem de inscrições por escola\n");
    printf("3-Valor total das inscrições entre duas datas (horizonte temporal) por tipo de atividade\n");
    printf("0-Sair\n");
    printf("******************************\n");

    scanf("%d", &resposta+1);

    return resposta;
}

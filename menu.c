#include <stdio.h>
#include <stdlib.h>
#include "funcoes.c"

int ultimo_participante = 0;
int ultima_atividade = 1;
int ultima_inscricao = 0;
int x, y;

int menu_principal(){
    int resposta;
    //limpar_console();

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
    int resposta,i;
    t_participante participante[MAX_P];
    FILE *participantes;
    size_t fSize;

    limpar_console();

// preciso abrir o arquivo passar o numero de participantes para ultimo_participante

    participantes = fopen("participantes.dat", "rb");

    fseek(participantes, 0L, SEEK_END);
    fSize = ftell(participantes);
    ultimo_participante = fSize/sizeof(t_participante);
    fseek(participantes, 0L, SEEK_SET);
    printf("ultimo participante = %d", ultimo_participante);

    fclose(participantes);

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
                scanf("%d %d", &x, &y);
                ultima_inscricao = registrar_inscricoes(x,y, ultima_inscricao);
                break;
            default:
                if(resposta != 0)
                    printf("Digite o numero correspondente a uma das opçoes do menu\n");
        }
    } while(resposta != 0);

    return resposta+1;// retorna true para voltar ao menu_principal
}

int menu_consultas(){
    int resposta, busca, encontrado, tipo_busca;
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
                limpar_console();
                printf("1- Se deseja buscar individualmente o participante\n2- Se deseja uma lista com todos os participantes\n3- Sair\n");
                scanf("%d", &tipo_busca);
                if(tipo_busca == 1){
                    printf("Digite o Id do participante: ");
                    scanf("%d", &busca);
                    encontrado = consultar_participante(busca, ultimo_participante);
                    if(encontrado == 0)
                        printf("Participante nao encontrado!\n");
                }
                else if(tipo_busca == 2){
                    busca = -1;
                    encontrado = consultar_participante(busca, ultimo_participante);
                }
                break;
            case 2:
                printf("Digite o Id da atividade: ");
                scanf("%d", &busca);
                encontrado = consultar_atividade(busca, ultima_atividade);
                if(encontrado == 0)
                    printf("Atividade nao encontrada!\n");
                break;
            case 3:
                printf("Digite o Id da inscrição: ");
                scanf("%d", &busca);
                consultar_inscricoes(busca, ultima_inscricao);
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

    do{
        printf("\n*****Menu de estatisticas*****\n");
        printf("1-Número de atividades realizadas por cada associacao\n");
        printf("2-Percentagem de inscrições por escola\n");
        printf("3-Valor total das inscrições entre duas datas (horizonte temporal) por tipo de atividade\n");
        printf("0-Sair\n");
        printf("******************************\n");

        scanf("%d", &resposta);

        switch(resposta){
            case 1:
                atividade_por_associacao(ultima_atividade);
                break;
            case 2:
                inscricao_por_escola(ultimo_participante, ultima_inscricao);
                break;
            case 3:
                printf("valor total entre bla bla\n");
                break;
            default:
                if(resposta != 0)
                    printf("Digite o numero correspondente a uma das opçoes do menu\n");
        }

    }while(resposta != 0);
    return resposta+1;// retorna true para voltar ao menu_principal
}

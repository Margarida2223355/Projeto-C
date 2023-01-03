#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "dados.c"

int main(){
    int resposta;

    setlocale(LC_ALL, "Portuguese");

    //atividade teste
    atividade[0].id_ativ = 0;
    strcpy(atividade[0].designacao, "briga");
    strcpy(atividade[0].tipo_atividade, "luta");
    strcpy(atividade[0].associacao, "AE-ESECS");
    strcpy(atividade[0].local, "leiria");
    atividade[0].valor_inscricao = 20;
    atividade[0].data_hora.dia = 10;
    atividade[0].data_hora.mes =10;
    atividade[0].data_hora.ano = 2022;
    atividade[0].data_hora.hora =20;
    atividade[0].data_hora.minuto = 20;

    do{
        resposta = menu_principal();

        switch(resposta){
            case 1:
                resposta = menu_registros();
                break;
            case 2:
                resposta = menu_consultas();
                break;
            case 3:
                resposta = menu_estatisticas();
                break;
        }
    } while(resposta != 0);
    getchar();
}

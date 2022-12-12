#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "dados.c"
#include "menu.h"


int main(){
    int resposta;

    setlocale(LC_ALL, "Portuguese");

    resposta = menu_principal();
    printf("%d", resposta);

    do{
    switch(resposta){
        case 1:
            resposta = menu_registros();
            printf("%d", resposta);
            break;
        case 2:
            resposta = menu_consultas();
            printf("%d", resposta);
            break;
        case 3:
            resposta = menu_estatisticas();
            printf("%d", resposta);
            break;
        default:
            printf("Digite o numero correspondente a uma das opçoes do menu\n");
            resposta = menu_principal();
    }
    } while(resposta != 0);
    getchar();
}

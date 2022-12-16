#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(){
    int resposta;

    setlocale(LC_ALL, "Portuguese");

    do{
        abrir_ficheiro();
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
            default:
                if(resposta != 0){
                    printf("Digite o numero correspondente a uma das opçoes do menu\n");
                    resposta = menu_principal();
                }
        }
    } while(resposta != 0);
    getchar();
}

#include <stdio.h>
#include <stdlib.h>
#include "dados.c"

int limpar_console(){
    system("cls");
}

char imprimir_data(Data data){
    char data_formatada[11];
    data_formatada = printf("%d/%d/%d", data.dia, data.mes, data.ano);
    return data_formatada;
}
int registrar_participante(int ultimo_participante){
    getchar();
        limpar_console();
        printf("Nome:");
        gets(participante[ultimo_participante].nome);
        printf("Email: ");
        gets(participante[ultimo_participante].email);
        participante[ultimo_participante].id_part = ultimo_participante;
        printf("Escola: ");
        gets(participante[ultimo_participante].escola);
        fflush(stdin);
        printf("NIF: ");
        scanf("%ld", &participante[ultimo_participante].nif);
        printf("Telefone: ");
        scanf("%ld", &participante[ultimo_participante].telefone);
        ultimo_participante++;

    return ultimo_participante;
}
//Podemos incluir as atividades em que o aluno esta matriculado
int consultar_participante(int id_part, int x){
    limpar_console();
    int encontrado;
    for(int i = 0; i < x; i++){
        if(participante[i].id_part == id_part){
            encontrado = 1;//verdadeiro
            printf("Encontrado\n");
            printf("Id: %d Nome: %s NIF: %ld\n",participante[i].id_part, participante[i].nome, participante[i].nif);
            printf("Escola: %s Email: %s Telefone: %ld\n", participante[i].escola, participante[i].email, participante[i].telefone);
        }
    }
    return encontrado;
}

int registrar_atividade(int ultima_atividade){

    limpar_console();
    getchar();
    atividade[ultima_atividade].id_ativ = ultima_atividade;
    printf("Id: %d\n", atividade[ultima_atividade].id_ativ);
    printf("Designação: ");
    gets(atividade[ultima_atividade].designacao);
    printf("Local: ");
    gets(atividade[ultima_atividade].local);
    printf("Tipo de atividade: ");
    gets(atividade[ultima_atividade].tipo_atividade);
    printf("Associação de estudantes organizadora: ");
    gets(atividade[ultima_atividade].associacao);
    printf("Valor da inscrição: ");
    scanf("%f", &atividade[ultima_atividade].valor_inscricao);
    printf("Data: ");
    //gets(atividade[ultima_atividade].designacao);
    fflush (NULL);
    scanf("%d/%d/%d", &atividade[ultima_atividade].data.dia, &atividade[ultima_atividade].data.mes, &atividade[ultima_atividade].data.ano);
    printf("%d/%d/%d", atividade[ultima_atividade].data.dia, atividade[ultima_atividade].data.mes, atividade[ultima_atividade].data.ano);
    printf("Hora: ");
    //gets(atividade[ultima_atividade].designacao);
    ultima_atividade++;

    return ultima_atividade;
}

int consultar_atividade(int id_atividade, int ultima_atividade){

    limpar_console();
    int encontrado = 0;

    for(int i = 0; i < ultima_atividade; i++){
        if(atividade[i].id_ativ == id_atividade){
            printf("Atividade encontrada\n");
            encontrado = 1;
            printf("Id: %d\t Designação: %s\t Local: %s\t Tipo de atividade: %s\n",atividade[i].id_ativ, atividade[i].designacao, atividade[i].local, atividade[i].tipo_atividade);
            printf("Associação organizadora: %s\t Valor: %.2f\t Data: %s \t Hora: \n", atividade[i].associacao, atividade[i].valor_inscricao, imprimir_data(atividade[ultima_atividade].data), atividade[i].hora);
        }
    }
    return encontrado;
}

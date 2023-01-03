#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "dados.c"



void limpar_console(){
    system("cls");
}

int converter_entrada_inteiro(char *entrada){
    int numero;

    numero = atoi(entrada);
    printf("%d    %s .",numero, entrada);
    return numero;
}

int validar_email(char *email) {
    int tam = strlen(email), i, arroba, ponto, antesPonto, depoisPonto;
    arroba = ponto = antesPonto = depoisPonto = 0;

    for (i = 0; i < tam; i++) {
        char c = email[i];
        if (c == '@') {  // Verifica se tem arroba
            if (arroba)
                break;
            arroba = 1;
            if (i < 3)  // Verifica se tem 3 letras antes do arroba;
                break;
        }
        else if (arroba) {
            if (ponto)
                depoisPonto++;
            else if (c == '.') {
                ponto = 1;
                if (antesPonto < 2)  //Verifica se tem 2 letras antes do ponto
                    break;
            }
            else
                antesPonto++;

        }
    }

    if (i == tam && depoisPonto > 1)
        return 1;
    else
        return 0;
}

int validar_data(t_data_hora data_hora){
    if (data_hora.ano >= 1900 && data_hora.ano <= 2050){
        if (data_hora.mes >= 1 && data_hora.mes <= 12){
            if ((data_hora.dia >= 1 && data_hora.dia <= 31) && (data_hora.mes == 1 || data_hora.mes == 3 || data_hora.mes == 5 || data_hora.mes == 7 || data_hora.mes == 8 || data_hora.mes == 10 || data_hora.mes == 12))
                return 1;
            else if ((data_hora.dia >= 1 && data_hora.dia <= 30) && (data_hora.mes == 4 || data_hora.mes == 6 || data_hora.mes == 9 || data_hora.mes == 11))
                return 1;
            else if ((data_hora.dia >= 1 && data_hora.dia <= 29) && (data_hora.mes == 2))
                return 1;
        }
    }
    return 0;// Retorna 0 caso algum dos datos nao seja valido
}

int validar_hora(t_data_hora data_hora){

    printf("%d:%d",data_hora.hora, data_hora.minuto);
    if (data_hora.hora < 0 || data_hora.hora > 23)
        return 0;
    if (data_hora.minuto < 0 || data_hora.minuto > 59)
        return 0;
    if (data_hora.segundo < 0 || data_hora.segundo > 59)
        return 0;
    return 1;
}

void imprimir_data(t_data_hora data_hora){
    printf("%d/%d/%d\n", data_hora.dia, data_hora.mes, data_hora.ano);
}

void imprimir_hora(t_data_hora data_hora){
    printf("%d:%d\n", data_hora.hora, data_hora.minuto);
}

int registrar_participante(int ultimo_participante){
    int resposta_escola, email_valido;
    char *escola[5];
    t_participante participante;
    FILE *participantes;
    getchar();
    limpar_console();

    participante.id_part = ultimo_participante;
    printf("Nome:");
    gets(participante.nome);
    printf("Email: ");
    gets(participante.email);
    email_valido = validar_email(participante.email);
    while (email_valido == 0){
        printf("email invalido, tente novamente\n Email: ");
        gets(participante.email);
        email_valido = validar_email(participante.email);
    };
    fflush(stdin);
    printf("Digite o numero correspontende a Escola\n1-ESTG 2-ESECS 3-ESSLEI 4-ESAD 5-ESTM: ");
    scanf("%d", &resposta_escola);
    identificador_escola(resposta_escola, ultimo_participante, 0, &participante);
    printf("NIF: ");
    scanf("%ld", &participante.nif);
    printf("Telefone: ");
    scanf("%ld", &participante.telefone);
    ultimo_participante++;

    participantes = fopen("participantes.dat", "a+b");
    if(participantes){
        fwrite(&participante, sizeof(t_participante), 1, participantes);
        fclose(participantes);
    }
    else
        printf("ERRO: nao foi possivel abrir o arquivo.\n\n");

    return ultimo_participante;
}

int consultar_participante(int busca, int ultimo_participante){
    int encontrado, i;
    t_participante participante[MAX_P];
    FILE *participantes;
    limpar_console();

    participantes = fopen("participantes.dat","rb");
    if(participantes){
        fread(participante, sizeof(t_participante), 10, participantes);
        fclose(participantes);
    }
    else{
        printf("ERRO: nao foi possivel abrir o arquivo.\n\n");
        }
    for(int i = 0; i <10; i++){
        printf("Id: %d Nome: %s NIF: %ld  Escola: %s Email: %s Telefone: %ld\n",participante[i].id_part, participante[i].nome, participante[i].nif, participante[i].escola, participante[i].email, participante[i].telefone);
    }

//    for(i = 0; i < ultimo_participante; i++){
//        if(busca == -1){
//            printf("Id: %d Nome: %s NIF: %ld  Escola: %s Email: %s Telefone: %ld\n",participante[i].id_part, participante[i].nome, participante[i].nif, participante[i].escola, participante[i].email, participante[i].telefone);
//            encontrado = 1;
//        }
//        else if(participante[i].id_part == busca) {
//            encontrado = 1;//verdadeiro
//            printf("Encontrado\n");
//            printf("Id: %d Nome: %s NIF: %ld\n",participante[i].id_part, participante[i].nome, participante[i].nif);
//            printf("Escola: %s Email: %s Telefone: %ld\n", participante[i].escola, participante[i].email, participante[i].telefone);
//        }
//    }
    return encontrado;
}

int registrar_atividade(int ultima_atividade){
    int resposta_escola, data_valida, hora_valida;

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
    fflush(stdin);
    printf("Digite o numero correspontende a associação de estudantes organizadora\n1- AE-ESTG 2- AE-ESECS 3- AE-ESSLEI 4- AE-ESAD 5- AE-ESTM: ");
    scanf("%d", &resposta_escola);
    //identificador_escola(resposta_escola, ultima_atividade, 1);
    printf("Valor da inscrição: ");
    scanf("%f", &atividade[ultima_atividade].valor_inscricao);

    do {
        printf("Data (DD/MM/YYYY): ");
        scanf("%d/%d/%d", &atividade[ultima_atividade].data_hora.dia, &atividade[ultima_atividade].data_hora.mes, &atividade[ultima_atividade].data_hora.ano);
        data_valida = validar_data(atividade[ultima_atividade].data_hora); //Retorna 0 em caso de erro e 1 em caso de sucesso
        if (data_valida == 0)
            printf("Erro, a data não é valida\n");
    }while (data_valida == 0);
    do{
        printf("Hora (HH:MM): ");
        scanf("%d:%d", &atividade[ultima_atividade].data_hora.hora, &atividade[ultima_atividade].data_hora.minuto);
        hora_valida = validar_hora(atividade[ultima_atividade].data_hora);
        printf("%d\n", hora_valida);
        if (hora_valida == 0)
            printf("Erro, horario invalido\n");
    }while (hora_valida == 0);

    ultima_atividade++;
    return ultima_atividade;
}

int consultar_atividade(int id_atividade, int ultima_atividade){

    int i, encontrado = 0;
    limpar_console();

    for(i = 0; i < ultima_atividade; i++){
        if(atividade[i].id_ativ == id_atividade){
            printf("Atividade encontrada\n");
            encontrado = 1;
            printf("Id: %d\t Designação: %s\t Local: %s\t Tipo de atividade: %s\n",atividade[i].id_ativ, atividade[i].designacao, atividade[i].local, atividade[i].tipo_atividade);
            printf("Associação organizadora: %s\t Valor: %.2f\t\n", atividade[i].associacao, atividade[i].valor_inscricao);
            imprimir_data(atividade[i].data_hora);
            imprimir_hora(atividade[i].data_hora);
        }
    }
    return encontrado;
}

int registrar_inscricoes(int id_part, int id_ativ, int ultima_inscricao){
    time_t segundos;
    time(&segundos);


    inscricao[ultima_inscricao].id_ins = ultima_inscricao;
    inscricao[ultima_inscricao].id_ins_part = id_part;
    inscricao[ultima_inscricao].id_ins_ativ = id_ativ;
    inscricao[ultima_inscricao].valor_ins_ativ = atividade[id_ativ].valor_inscricao;
    participante[id_part].atividades_inscritas++;
    ultima_inscricao++;

    inscricao[ultima_inscricao].data_hora_atual = localtime(&segundos);
    printf("%d/%d/%d   %d:%d", inscricao[ultima_inscricao].data_hora_atual->tm_mday, inscricao[ultima_inscricao].data_hora_atual->tm_mon+1, inscricao[ultima_inscricao].data_hora_atual->tm_year+1900, inscricao[ultima_inscricao].data_hora_atual->tm_hour, inscricao[ultima_inscricao].data_hora_atual->tm_min);
    printf("%d, %d, %f", inscricao[ultima_inscricao].id_ins_part, inscricao[ultima_inscricao].id_ins_ativ, inscricao[ultima_inscricao].valor_ins_ativ);

    return ultima_inscricao;
}

void consultar_inscricoes(int id_ins, int ultima_inscricao){
    int i;

    for(i = 0; i < ultima_inscricao; i++){
        if(inscricao[i].id_ins == id_ins){
            printf("Id inscrição: %d\n", inscricao[i].id_ins);
            printf("Id participante: %d\n", inscricao[i].id_ins_part);
            printf("Id atividade: %d\n", inscricao[i].id_ins_ativ);
            printf("Valor pago: %f\n", inscricao[i].valor_ins_ativ);
            printf("Data: %d/%d/%d Hora: %d:%d:%d\n", inscricao[ultima_inscricao].data_hora_atual->tm_mday, inscricao[ultima_inscricao].data_hora_atual->tm_mon+1, inscricao[ultima_inscricao].data_hora_atual->tm_year+1900, inscricao[ultima_inscricao].data_hora_atual->tm_hour, inscricao[ultima_inscricao].data_hora_atual->tm_min, inscricao[ultima_inscricao].data_hora_atual->tm_sec);
        }
        else
            printf("Inscrição nao encontrada\n");
    }
}

void atividade_por_associacao(int ultima_atividade){
    int i, ESTG, ESECS, ESSLEI, ESAD, ESTM;
    ESTG = ESECS = ESSLEI = ESAD = ESTM = 0;

    for(i = 0; i < ultima_atividade; i++){
            if(strcmp(atividade[i].associacao, "AE-ESTG") == 0){
                ESTG++;
            }
            else if(strcmp(atividade[i].associacao, "AE-ESECS") == 0){
                ESECS++;
            }
            else if(strcmp(atividade[i].associacao, "AE-ESSLEI") == 0){
                ESSLEI++;
            }
            else if(strcmp(atividade[i].associacao, "AE-ESAD") == 0){
                ESAD++;
            }
            else if(strcmp(atividade[i].associacao, "AE-ESTM") == 0){
                ESTM++;
            }
            else
                printf("ERRO %s NAO EXISTE\n", atividade[i].associacao);
    }
    printf("AE-ESTG: %d\nAE-ESECS: %d\nAE-ESSLEI: %d\nAE-ESAD: %d\nAE-ESTM: %d\n", ESTG, ESECS, ESSLEI, ESAD, ESTM);
}

void identificador_escola(int resposta, int final_lista, int associacao_estudante, t_participante participante){
    if(associacao_estudante == 0){
        switch(resposta){
            case 1:
                strcpy(participante.escola, "ESTG");
                break;
            case 2:
                strcpy(participante.escola, "ESECS");
                break;
            case 3:
                strcpy(participante.escola, "ESSLEI");
                break;
            case 4:
                strcpy(participante.escola, "ESAD");
                break;
            case 5:
                strcpy(participante.escola, "ESTM");
                break;
        }
    }
    if(associacao_estudante == 1){
                switch(resposta){
            case 1:
                strcpy(atividade[final_lista].associacao, "AE-ESTG");
                break;
            case 2:
                strcpy(atividade[final_lista].associacao, "AE-ESECS");
                break;
            case 3:
                strcpy(atividade[final_lista].associacao, "AE-ESSLEI");
                break;
            case 4:
                strcpy(atividade[final_lista].associacao, "AE-ESAD");
                break;
            case 5:
                strcpy(atividade[final_lista].associacao, "AE-ESTM");
                break;
        }
    }
}

void inscricao_por_escola(int ultimo_participante, int ultima_inscricao){
    int i;
    float ESTG, ESECS, ESSLEI, ESAD, ESTM;
    ESTG = ESECS = ESSLEI = ESAD = ESTM = 0;

    for(i = 0; i < ultima_inscricao; i++){
        if(participante[i].atividades_inscritas > 0){
            if(strcmp(participante[i].escola, "ESTG") == 0){
                ESTG++;
            }
            else if(strcmp(participante[i].escola, "ESECS") == 0){
                ESECS++;
            }
            else if(strcmp(participante[i].escola, "ESSLEI") == 0){
                ESSLEI++;
            }
            else if(strcmp(participante[i].escola, "ESAD") == 0){
                ESAD++;
            }
            else if(strcmp(participante[i].escola, "ESTM") == 0){
                ESTM++;
            }
            else
                printf("ERRO");
        }
    }
    ESTG = (ESTG * 100) / ultima_inscricao;
    ESECS = (ESECS * 100) / ultima_inscricao;
    ESSLEI = (ESSLEI * 100) / ultima_inscricao;
    ESAD = (ESAD * 100) / ultima_inscricao;
    ESTM =(ESTM * 100) / ultima_inscricao;
    printf("ESTG: %.2f%%\n", ESTG);
    printf("ESECS: %.2f%%\n", ESECS);
    printf("ESSLEI: %.2f%%\n", ESSLEI);
    printf("ESAD: %.2f%%\n", ESAD);
    printf("ESTM: %.2f%%\n", ESTM);

}

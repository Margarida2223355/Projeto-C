#include <stdio.h>
#include <stdlib.h>

#define MAX_P 5000
#define MAX_A 200
#define MAX_I 10000
#define MAX_CARACT 50


typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    int hora, minuto, segundo;
} Hora;

typedef struct {
    int id_part;
    long nif, telefone;
    char nome[MAX_CARACT], email[MAX_CARACT], escola[5];
} t_participante;

typedef struct {
    int id_ativ;
    char designacao[MAX_CARACT], tipo_atividade[MAX_CARACT], associacao[MAX_CARACT], local[MAX_CARACT];
    float valor_inscricao;
    Data data;
    Hora hora;
} Atividade;

typedef struct {
    int id_ins, id_ins_part, id_ins_ativ;
    float valor_ins_ativ;
    Data data;
    Hora hora;
} Inscricao;



t_participante participante[MAX_P];
Atividade atividade[MAX_A];
Inscricao inscricao[MAX_I];


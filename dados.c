#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_P 5000
#define MAX_A 200
#define MAX_I 10000
#define MAX_CARACT 50
#define MAX_HORA 24
#define MAX_MIN 60
#define MAX_SEG 60


typedef struct {
    int dia, mes, ano, hora, minuto, segundo;
} t_data_hora;

typedef struct {
    int id_part, atividades_inscritas;
    long nif, telefone;
    char nome[MAX_CARACT], email[MAX_CARACT], escola[10];
} t_participante;

typedef struct {
    int id_ativ;
    char designacao[MAX_CARACT], tipo_atividade[MAX_CARACT], associacao[MAX_CARACT], local[MAX_CARACT];
    float valor_inscricao;
    t_data_hora data_hora;
} t_atividade;

typedef struct {
    int id_ins, id_ins_part, id_ins_ativ;
    float valor_ins_ativ;
    struct tm *data_hora_atual;
} t_inscricao;


t_participante participante[MAX_P];
t_atividade atividade[MAX_A];
t_inscricao inscricao[MAX_I];
struct tm *data_hora_atual;

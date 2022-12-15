#include <stdio.h>
#include <stdlib.h>

/* Definição das constantes */
#define MAX_P 5000
#define MAX_A 200
#define MAX_I 10000
#define MAX_CARACT 50


/* Estruturas */
typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    int hora, minuto, segundo;
} Hora;

typedef struct {
    int id_part;
    long nif, telefone;
    char nome[MAX_CARACT], email[MAX_CARACT];
    int escola;
} t_participante;

typedef struct {
    int id_ativ;
    char designacao[MAX_CARACT], local[MAX_CARACT];
    int tipo_atividade, associacao;
    float valor_inscricao;
    Data data;
    Hora hora;
} t_ativividade;

typedef struct {
    int id_ins, id_ins_part, id_ins_ativ;
    float valor_ins_ativ;
    Data data;
    Hora hora;
} t_inscricao;


/* Definir quantidade de participantes, atividades e inscrições */
t_participante participante[MAX_P];
t_ativividade atividade[MAX_A];
t_inscricao inscricao[MAX_I];

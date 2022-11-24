#include <stdio.h>
#include <stdlib.h>

#define MAX_P 5000
#define MAX_A 200
#define MAX_I 10000
#define MAX_CARACT 50
#define MAX_DATA 10
#define MAX_HORA 5


typedef struct {
    int id_part, escola, nif, telefone;
    char nome[MAX_CARACT], email[MAX_CARACT];
} t_participante;

typedef struct {
    int id_ativ, atividade, associacao;
    char designacao[MAX_CARACT], data[MAX_DATA], hora[MAX_HORA], local[MAX_CARACT];
    float valor_ins;
} Atividade;

typedef struct {
    int id_ins, id_ins_part, id_ins_ativ;
    float valor_ins_ativ;
    char data[MAX_DATA], hora[MAX_HORA];
} Inscricao;

t_participante participante[MAX_P]={};
Atividade atividade[MAX_A];
Inscricao inscricao[MAX_I];


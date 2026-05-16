//BIBLIOTECAS > PASSAR PARA .H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dados.h"

//MACROS

#define MAX_REGAS 500
#define MAX_TAREFAS 200

//STRUCTS

typedef struct
{
    int id_rega;
    int id_planta;
    int data_rega; /* timestamp: dias desde 01/01/2026 */
    int quantidade_agua; /* em ml */
} Rega;

typedef struct
{
    int id_tarefa;
    char descricao[100];
    int data_prevista; /* timestamp: dias desde 01/01/2026 */
    int concluida; /* 0 = pendente | 1 = concluida */
} Tarefa;

//VARIÁVEIS GLOBAIS
//Planta plantas[MAX_PLANTAS];
Rega regas[MAX_REGAS];
Tarefa tarefas[MAX_TAREFAS];

//FUNÇÕES
/*
static int carregar_plantas()
{
    int total_plantas = 0;
    FILE *f_plantas = fopen("plantas.csv", "r");
    if (f_plantas == NULL)
    {
        printf("Não foi possível carregar os dados sobre Plantas.\n"
            "Caso ainda não tenha adicionado nenhuma planta à base de dados, certifique-se de fazê-lo antes de aceder a esta funcionalidade.\n");
        return 0;
    }
    while (fscanf(f_plantas, "%d,%[^,],%[^,],%[^,],%d,%d\n",
            &plantas[total_plantas].id,
            plantas[total_plantas].nome,
            plantas[total_plantas].especie,
            plantas[total_plantas].data_plantio,
            &plantas[total_plantas].intervalo_rega,
            &plantas[total_plantas].ultima_rega) == 6)
        total_plantas++;
    fclose(f_plantas);
    return total_plantas;
}*/

static int carregar_regas()
{
    int total_regas = 0;
    FILE *f_regas = fopen("regas.csv", "r");
    if (f_regas == NULL)
    {
        printf("Erro ao carregar dados sobre Regas\n");
        return 0;
    }
    while (fscanf(f_regas, "%d,%d,%d,%d\n",
            &regas[total_regas].id_rega,
            &regas[total_regas].id_planta,
            &regas[total_regas].data_rega,
            &regas[total_regas].quantidade_agua) == 4)
        total_regas++;
    fclose(f_regas);
    return total_regas;
}

static int carregar_tarefas()
{
    int total_tarefas = 0;
    FILE *f_tarefas = fopen("tarefas.csv", "r");
    if (f_tarefas == NULL)
    {
        printf("Erro ao carregar dados sobre Tarefas\n");
        return 0;
    }
//    while (fscanf(f_tarefas, "%d,%[^,],%d,%d",
//            &tarefas[total_tarefas].id_tarefa,
//            tarefas[total_tarefas].descricao[100],
//            &tarefas[total_tarefas].data_prevista,
//            &tarefas[total_tarefas].concluida) == 4)
        total_tarefas++;
    fclose(f_tarefas);
    return total_tarefas;
}

void carregar_dados()
{
   // int total_plantas = 0;
    int total_regas = 0;
    int total_tarefas = 0;

   // total_plantas = carregar_plantas();
    total_regas = carregar_regas();
    total_tarefas = carregar_tarefas();
}

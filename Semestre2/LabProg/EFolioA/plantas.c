#include "plantas.h"

#define MAX_PLANTAS 100 //nao funcionou

typedef struct Planta
{
    int id;
    char nome[50];
    char especie[50];
    char data_plantio[11]; /* DD/MM/AAAA */
    int intervalo_rega; /* em dias */
    int ultima_rega; /* timestamp: dias desde 01/01/2026 */
} Planta;

static Planta plantas[MAX_PLANTAS]; //ser ponteiro nao ajuda, tirei
static int total_plantas = 0;

void listar_plantas()
{
    printf("=== PLANTAS ===\n");
    for (int i = 0; i < total_plantas; i++) //corrigido de <= para <
    {
        printf("ID: %d | Nome: %s | Espécie: %s | Data de Plantio: %s | Intervalo de Rega: %d | Última Rega: %d\n",
            plantas[i].id,
            plantas[i].nome,
            plantas[i].especie,
            plantas[i].data_plantio,
            plantas[i].intervalo_rega,
            plantas[i].ultima_rega);
    }
    printf("===== FIM =====\n");
}

void adicionar_planta() //int id, char* nome, char* especie, char* data_plantio, int intervalo
{
    if(total_plantas >= MAX_PLANTAS)
    {
        printf("Capacidade máxima de plantas atingida\n");
        return;
    }
    printf("Total plantas: %d\n", total_plantas);
    printf("Insira o ID: ");
    printf("Insira o ID: ");
    scanf("%d", &plantas[total_plantas].id);
    //plantas[i].id,
    //plantas[i].nome,
//    plantas[i].data_plantio,
//    plantas[total_plantas].intervalo_rega = intervalo;
//    plantas[total_plantas].ultima_rega = 0; // data atual do sistema
//    total_plantas++;
}

/*
void guardar_dados()
{
    FILE *f_plantas = fopen("plantas.csv", "w");
    if (f_plantas == NULL)
    {
        printf("Erro\n");
        return;
    }
    for (int i = 0; i < total_plantas; i++)
    {
        fprintf(f_plantas, "%d,%s,%s,%s,%d,%d\n", plantas[i].id, [...]);
    }
    fclose(f_plantas);
}
*/
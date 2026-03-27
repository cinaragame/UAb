#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para armazenar dados de um estudante
typedef struct {
    char nome[50];
    float nota;
} Estudante;

// Variáveis globais
Estudante* estudantes;
int numEstudantes;

// Protótipos das funções
void adicionarEstudante(char* nome, float nota);
float calcularMedia();
void listarEstudantes();
void libertarMemoria();

// Função principal
int main(void) {
    int opcao; // nao inicializa opcao, é problema?
    char nome[50];
    float nota;
    setlocale(LC_ALL, "PT"); // Não inclui bbt locale.h
    numEstudantes = 0;
    estudantes = (Estudante*)malloc(10 * sizeof(Estudante)); //Não verifica alocação de memoria
    
    do {
        printf("\n=== MENU ===\n");
        printf("1. Adicionar estudante\n");
        printf("2. Calcular média\n");
        printf("3. Listar estudantes\n");
        printf("0. Sair\n");
        printf("Opção: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                printf("Nome: ");
                scanf("%s", nome);
                printf("Nota: ");
                scanf("%f", &nota); // falta virgula
                adicionarEstudante(nome, nota);
                break;
            case 2:
                printf("Média: %.2f\n", calcularMedia());
                break;
            case 3:
                listarEstudantes();
                break;
        }
    } while(opcao != 0);
    
    libertarMemoria();
    return 0;
}

// Adiciona um estudante à lista
void adicionarEstudante(char* nome, float nota) {
    if(numEstudantes < 10) { //numero de estudantes não está comunicando com main - global
        strcpy(estudantes[numEstudantes].nome, nome);
        estudantes[numEstudantes].nota = nota;
        numEstudantes++;
        printf("Estudante adicionado com sucesso!\n");
    } else {
        printf("Lista cheia!\n");
    }
}

// Calcula a média das notas
float calcularMedia() {
    float soma = 0;
    int i;
    
    for(i = 0; i < numEstudantes; i++) {
        soma = soma + estudantes[i].nota; //Não inicializa soma a 0
    }    
    return soma / numEstudantes; //Não checa media quando ha 0 estudantes (0/0)
}

// Lista todos os estudantes
void listarEstudantes() {
    int i;
    
    if(numEstudantes == 0) {
        printf("Nenhum estudante registado.\n");
        return;
    }
    
    printf("\n=== Lista de Estudantes ===\n");
    for(i = 0; i < numEstudantes; i++) {
        printf("%d. %s - %.2f\n", i+1, estudantes[i].nome, estudantes[i].nota);
    }
}

// Liberta a memória alocada
void libertarMemoria() {
    printf("A libertar memória...\n");
    // (código de libertação omitido pelo programador original)
}

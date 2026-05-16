#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
// Estrutura para armazenar dados de um estudante
typedef struct {
    char nome[50];
    float nota;
} Estudante;

// Estrutura para gerir a lista de estudantes
typedef struct {
    Estudante* lista;
    int numEstudantes;
    int capacidade;
} GestorEstudantes;

// Protótipos das funções
GestorEstudantes* criarGestor(int capacidadeInicial);
void adicionarEstudante(GestorEstudantes* gestor, char* nome, float nota);
float calcularMedia(GestorEstudantes* gestor);
void listarEstudantes(GestorEstudantes* gestor);
void libertarGestor(GestorEstudantes* gestor);
int validarNota(float nota);

// Cria um novo gestor de estudantes
GestorEstudantes* criarGestor(int capacidadeInicial) {
    GestorEstudantes* gestor = (GestorEstudantes*)malloc(sizeof(GestorEstudantes));
    
    if(gestor == NULL) {
        return NULL;
    }
    
    gestor->lista = (Estudante*)malloc(capacidadeInicial * sizeof(Estudante));
    
    if(gestor->lista == NULL) {
        free(gestor);
        return NULL;
    }
    
    gestor->numEstudantes = 0;
    gestor->capacidade = capacidadeInicial;
    
    return gestor;
}

// Valida se a nota está no intervalo correto
int validarNota(float nota) {
    return (nota >= 0 && nota <= 20);
}

// Adiciona um estudante à lista (com expansão dinâmica)
void adicionarEstudante(GestorEstudantes* gestor, char* nome, float nota) {
    if(gestor == NULL) {
        printf("Erro: gestor inválido.\n");
        return;
    }
    
    // Validação da nota
    if(!validarNota(nota)) {
        printf("Erro: nota inválida (deve estar entre 0 e 20).\n");
        return;
    }
    
    // Expandir array se necessário
    if(gestor->numEstudantes >= gestor->capacidade) {
        int novaCapacidade = gestor->capacidade * 2;
        Estudante* novaLista = (Estudante*)realloc(gestor->lista, 
                                                    novaCapacidade * sizeof(Estudante));
        
        if(novaLista == NULL) {
            printf("Erro ao expandir lista!\n");
            return;
        }
        
        gestor->lista = novaLista;
        gestor->capacidade = novaCapacidade;
        printf("Lista expandida para %d estudantes.\n", novaCapacidade);
    }
    
    // Adicionar estudante
    strcpy(gestor->lista[gestor->numEstudantes].nome, nome);
    gestor->lista[gestor->numEstudantes].nota = nota;
    gestor->numEstudantes++;
    printf("Estudante adicionado com sucesso!\n");
}

// Calcula a média das notas
float calcularMedia(GestorEstudantes* gestor) {
    float soma = 0;
    int i;
    
    if(gestor == NULL || gestor->numEstudantes == 0) {
        printf("Não há estudantes registados.\n");
        return 0;
    }
    
    for(i = 0; i < gestor->numEstudantes; i++) {
        soma += gestor->lista[i].nota;
    }
    
    return soma / gestor->numEstudantes;
}

// Lista todos os estudantes
void listarEstudantes(GestorEstudantes* gestor) {
    int i;
    
    if(gestor == NULL || gestor->numEstudantes == 0) {
        printf("Nenhum estudante registado.\n");
        return;
    }
    
    printf("\n=== Lista de Estudantes (Total: %d) ===\n", gestor->numEstudantes);
    for(i = 0; i < gestor->numEstudantes; i++) {
        printf("%d. %s - %.2f\n", i+1, 
               gestor->lista[i].nome, 
               gestor->lista[i].nota);
    }
}

// Liberta toda a memória alocada
void libertarGestor(GestorEstudantes* gestor) {
    if(gestor != NULL) {
        if(gestor->lista != NULL) {
            free(gestor->lista);
            gestor->lista = NULL;
        }
        free(gestor);
        printf("Memória libertada com sucesso.\n");
    }
}

// Função principal
int main(void) {
    GestorEstudantes* gestor = criarGestor(10);
    int opcao;
    char nome[50];
    float nota;
    
    if(gestor == NULL) {
        printf("Erro ao criar gestor de estudantes!\n");
        return 1;
    }
    
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
                printf("Nota (0-20): ");
                scanf("%f", &nota);
                adicionarEstudante(gestor, nome, nota);
                break;
            case 2:
                printf("Média: %.2f\n", calcularMedia(gestor));
                break;
            case 3:
                listarEstudantes(gestor);
                break;
            case 0:
                printf("A encerrar programa...\n");
                break;
            default:
                printf("Opção inválida!\n");
                break;
        }
    } while(opcao != 0);
    libertarGestor(gestor);
    return 0;
}


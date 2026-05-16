#include "menu.h"
#include "plantas.h"

static int ParseInput(char *input, int max_input)
{
    int i = 0;
    if(input[i] >= '1' && input[i] <= '8') //Apesar de ser char, é possível fazer comparação direta pela ASCII table
    {
        i++;
        while(input[i] == ' ')
            i++;
        if(input[i] == '\0' || input[i] == '\n')
            return atoi(input); // Retorna entrada válida
    }
    return 0; //Retorna entrada inválida
}

static int GetInput()
{
    int max_input = 50; // Tamanho do buffer
    int parsed_input = 0;
    char input[max_input];

    //clean buffer
    if (!strchr(input, '\n'))
        while (getchar() != '\n' && getchar() != EOF);
	fgets(input, max_input, stdin);
    //clean buffer
    if (!strchr(input, '\n'))
        while (getchar() != '\n' && getchar() != EOF);
    
    parsed_input = ParseInput(input, max_input);
    return parsed_input;
}

static void AcionarOpcao(int opcao)
{
switch (opcao)
{
    case 1:
    {
        listar_plantas();
        break;
    }
    case 2:
    {
        adicionar_planta();
        break;
    }
    case 3:
    {
        printf("3\n");
        break;
    }
    case 4:
    {
        printf("4\n");
        break;
    }
    case 5:
    {
        printf("5\n");
        break;
    }
    case 6:
    {
        /*char descricao[100]; int data_prevista;
        printf("Descricao: "); scanf("%s", descricao);
        [...]
        break;*/
        printf("6\n");
        break;
    }
    case 7:
    {
        printf("7\n");
        break;
    }
    case 8:
    {
        printf("Programa encerrado\n");
        break;
    }
    default:
    {
        printf("Opção inválida\n");
        break;
    }
}
}

int MenuOpcoes(int opcao)
{
    printf("===MENU===\n"
        "1 - Listar plantas\n"
        "2 - Adicionar planta\n"
        "3 - Verificar rega\n"
        "4 - Registar rega\n"
        "5 - Listar tarefas pendentes\n"
        "6 - Criar tarefa\n"
        "7 - Concluir tarefa\n"
        "8 - Encerrar programa\n"
        "Opção: ");
    opcao = GetInput();

    AcionarOpcao(opcao);
    //Retornar falso para encerrar programa
    if(opcao == 8)
        return 0;
    //Retornar verdadeiro para continuar programa
    return 1;
}

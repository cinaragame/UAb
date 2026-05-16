#include "menu.h"
#include "dados.h"
#include <locale.h>

int main()
{
    setlocale(LC_ALL, ".UTF-8");
//    carregar_dados();
    int opcao = 0;
    do
    {
        opcao = MenuOpcoes(opcao);
    } while (opcao);
    
    return 0;
}
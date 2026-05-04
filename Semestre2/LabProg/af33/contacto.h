#ifndef CONTACTO_H
#define CONTACTO_H

#define CONTACTO_NOME_MAX	100
#define CONTACTO_EMAIL_MAX	100
#define CONTACTO_TEL_MAX	 20

typedef struct
{
	char nome[CONTACTO_NOME_MAX];
	char email[CONTACTO_EMAIL_MAX];
	char telefone[CONTACTO_TEL_MAX];
} Contacto;

/*
* Inicializa um contacto com os dados fornecidos
* Valida o email e o telefone antes de aceitar
*
* Prâmetros:
*	novo		- ponteiro para o Contacto a preencher (não pode ser NULL)
*	nome		- nome do contacto (não pode ser NULL ou vazio)
*	email		- endereço de email (validado)
*	telefone	- numero de telefone (validado)
*
* Retorna:
*	1 se o contacto foi criado com sucesso, 0 se algum dado é inválido
*/
int contacto_criar(Contacto *novo, const char *nome, const char *email,
					const char *telefone);

/*
* Imprime os dados de um contacto no ecrã
*
* Parâmetros:
*	contacto	- ponteiro para o Contacto a mostrar(não pode ser NULL)
*/
void contacto_mostrar(const Contacto *contacto);

#endif

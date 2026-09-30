# ===================================================================================
# ETAPA 2: Para que se possam realizar manutenções pontuais no estacionamento,
# um programador implementou uma função que permite a administração fechar o parque
# de estacionamento independentemente de sua lotação.
# BUG: o programa funciona bem para bloquear novas entradas, entretanto, caso um carro
# que já estivesse dentro do estacionamento saia, a função saida_carro() volta a abrir
# o estacionamento para novas entradas automaticamente
# ===================================================================================
from typing import Final

#quantidade de vagas existentes
MAX_LUGARES: Final = 5

#variaveis globais de quantidade de vagas ocupadas + estado do estacionamento
#é sempre possível sair do estacionamento fechado, mas não é possível entrar
lugares_ocupados = 0
estacionamento_aberto = True


# incrementa variavel lugares_ocupados quando entra um novo carro no estacionamento
def entrada_carro():
    global lugares_ocupados
    global estacionamento_aberto

    if estacionamento_aberto:
        lugares_ocupados += 1
        print(f"Entrada permitida: Bem-vindo! ({lugares_ocupados}/{MAX_LUGARES})")
        if lugares_ocupados == MAX_LUGARES:
            estacionamento_aberto = False
    else:
        print("Entrada não permitida, volte mais tarde!")


# decrementa a variavel lugares_ocupados quando sai um carro do estacionamento
def saida_carro():
    global lugares_ocupados
    global estacionamento_aberto

    if lugares_ocupados == 0:
        print("Erro: Tentativa de registar saída em estacionamento vazio!")
        return
    if lugares_ocupados > 0:
        lugares_ocupados -= 1
        estacionamento_aberto = True
        print(f"Saída registada: Volte sempre! ({lugares_ocupados}/{MAX_LUGARES})")

# tranca o estacionamento, nao permitindo novas entradas
def trancar_estacionamento():
    global estacionamento_aberto

    estacionamento_aberto = False
    print("Estacionamento tracado para novas entradas!")


#execução do programa
saida_carro()                       #tentativa de registar saída sem carros no estacionamento
entrada_carro()                     #caso normal: entrada aceita
entrada_carro()                     #caso normal: entrada aceita
entrada_carro()                     #caso normal: entrada aceita
trancar_estacionamento() #encerrado manualmente para manutenção
entrada_carro()                     #caso normal: entrada negada
saida_carro()                       #caso normal: saída
entrada_carro()                     #caso de erro: entrada deveria ser negada
entrada_carro()                     #caso de erro: entrada deveria ser negada
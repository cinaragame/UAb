# ===================================================================================
# ETAPA 1: Programa controla entradas e saídas em parque de estacionamentos,
# liberando a entrada para carros apenas caso hajam vagas disponíveis
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

#execução do programa
saida_carro()   #tentativa de registar saída sem carros no estacionamento
entrada_carro() #caso normal: entrada
entrada_carro() #caso normal: entrada
entrada_carro() #caso normal: entrada
entrada_carro() #caso normal: entrada
entrada_carro() #caso limite: entrada
entrada_carro() #tentativa de entrada com estacionamento cheio
saida_carro()   #caso normal: saída
entrada_carro() #caso limite: entrada
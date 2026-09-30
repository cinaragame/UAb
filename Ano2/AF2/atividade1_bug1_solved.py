# ===================================================================================
# ETAPA 3: Bug solucionado com adição de variável global estacionamento_trancado,
# adição de guard clause em saida_carro() para reabertura do estacionamento e adição
# de função para destrancar estacionamento
# ===================================================================================
from typing import Final

#quantidade de vagas existentes
MAX_LUGARES: Final = 5

#variaveis globais de quantidade de vagas ocupadas + estado do estacionamento
#é sempre possível sair do estacionamento fechado, mas não é possível entrar
lugares_ocupados = 0
estacionamento_aberto = True
estacionamento_trancado = False

#incrementa variavel lugares_ocupados quando entra um novo carro no estacionamento
def entrada_carro():
    global lugares_ocupados
    global estacionamento_aberto

    if estacionamento_aberto:
        lugares_ocupados += 1
        print(f"Entrada permitida: Bem-vindo! ({lugares_ocupados}/{MAX_LUGARES})")
        if lugares_ocupados == MAX_LUGARES:
            estacionamento_aberto = False
    else:
        print(f"Entrada não permitida, volte mais tarde!")

#decrementa a variavel lugares_ocupados quando sai um carro do estacionamento
def saida_carro():
    global lugares_ocupados
    global estacionamento_aberto
    global estacionamento_trancado

    if lugares_ocupados == 0:
        print("Erro: Tentativa de registar saída em estacionamento vazio!")
        return
    if lugares_ocupados > 0:
        lugares_ocupados -= 1
        if not estacionamento_trancado:
            estacionamento_aberto = True
        print(f"Saída registada: Volte sempre! ({lugares_ocupados}/{MAX_LUGARES})")

# tranca o estacionamento, nao permitindo novas entradas
def trancar_estacionamento():
    global estacionamento_aberto
    global estacionamento_trancado

    estacionamento_aberto = False
    estacionamento_trancado = True
    print("Estacionamento tracado para novas entradas!")

def destrancar_estacionamento():
    global estacionamento_trancado
    global estacionamento_aberto
    global lugares_ocupados

    estacionamento_trancado = False
    print("Estacionamento destrancado!")
    if lugares_ocupados < MAX_LUGARES:
        estacionamento_aberto = True


#execução do programa
saida_carro()               #tentativa de registar saída sem carros no estacionamento
entrada_carro()             #caso normal: entrada aceita
entrada_carro()             #caso normal: entrada aceita
entrada_carro()             #caso normal: entrada aceita
trancar_estacionamento()    #encerrado manualmente para manutenção
entrada_carro()             #caso normal: entrada negada
saida_carro()               #caso normal: saída
entrada_carro()             #caso normal: entrada negada
destrancar_estacionamento() #caso normal: reabertura estacionamento
entrada_carro()             #caso normal: entrada aceita
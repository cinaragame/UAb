from typing import Final

#quantidade de vagas existentes
MAX_LUGARES: Final = 5

#variaveis globais de quantidade de vagas ocupadas + estado do estacionamento
#é sempre possível sair do estacionamento fechado, mas não é possível entrar
lugares_ocupados = 0
estacionamento_aberto = True

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
        print(f"Entrada não permitida: Estacionamento cheio, volte mais tarde!")

#decrementa a variavel lugares_ocupados quando sai um carro do estacionamento
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

# com o funcionamento diário do estacionamento, percebe-se que é necessário incluir no sistema
# a opção de fechar o estacionamento, acionada manualmente de forma pontual, seja para a
# realização de manutenções urgentes, seja para impedir novas entradas, garantindo vagas para
# os CEOs que vêm do Dubai
def fechar_estacionamento_manualmente():
    global estacionamento_aberto

    estacionamento_aberto = False


#execução do programa
saida_carro()                       #tentativa de registar saída sem carros no estacionamento
entrada_carro()                     #caso normal: entrada aceita
entrada_carro()                     #caso normal: entrada aceita
entrada_carro()                     #caso normal: entrada aceita
fechar_estacionamento_manualmente() #encerrado manualmente para manutenção
entrada_carro()                     #caso normal: entrada negada
saida_carro()                       #caso normal: saída
entrada_carro()                     #caso de erro: entrada deveria ser negada
entrada_carro()                     #caso de erro: entrada deveria ser negada
entrada_carro()                     #caso de erro: entrada deveria ser negada
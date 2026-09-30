# ===================================================================================
# ETAPA 4: Com a evolução da tecnologia, o estacionamento decide implementar um
# sistema de reserva antecipada pela app, dedicando um lugar exclusivo para reservas
# apenas a um grupo seleto de clientes. Um desenvolvedor implementa uma nova variável
# e funções novas para reserva e entrada no estacionamento através da leitura da
# matrícula do veículo.
# BUG: Um cliente faz a reserva do lugar pela app, que aprova a mesma. Logo a seguir
# a administração tranca o estacionamento para manutenção, ao chegar ao estacionamento
# a entrada é automaticamente liberada pela leitura da matrícula do carro,
# interferindo com a manutenção
# ===================================================================================
from typing import Final

#quantidade de vagas existentes
MAX_LUGARES: Final = 5

#variaveis globais de quantidade de vagas ocupadas + estado do estacionamento
#é sempre possível sair do estacionamento fechado, mas não é possível entrar
lugares_ocupados = 0
estacionamento_aberto = True
estacionamento_trancado = False
lugar_app_disponivel = True
matricula_reserva = None

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
        print("Entrada não permitida, volte mais tarde!")

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

def app_nova_reserva(matricula_app):
    global lugares_ocupados
    global estacionamento_aberto
    global lugar_app_disponivel
    global matricula_reserva
    global MAX_LUGARES

    if lugar_app_disponivel:
        lugares_ocupados += 1
        lugar_app_disponivel = False
        matricula_reserva = matricula_app
        print(f"Reserva na app feita com sucesso! ({lugares_ocupados}/{MAX_LUGARES})")
        if lugares_ocupados == MAX_LUGARES:
            estacionamento_aberto = False
    else:
        print("A vaga não está disponível!")

def entrada_app(matricula_cancela):
    global matricula_reserva

    if matricula_cancela == matricula_reserva:
        print("Entrada permitida: vaga app!")
    else:
        print("Entrada não permitida!")

#execução do programa
saida_carro()               #tentativa de registar saída sem carros no estacionamento
entrada_carro()             #caso normal: entrada aceita
entrada_carro()             #caso normal: entrada aceita
entrada_carro()             #caso normal: entrada aceita
app_nova_reserva("AB01CD")  #caso norma: programa procede à reserva
trancar_estacionamento()    #encerrado manualmente para manutenção
entrada_carro()             #caso normal: entrada negada
entrada_app("AB01CD")       #caso erro: entrada deveria ser negada (estacionamento trancado)
entrada_carro()             #caso normal: entrada negada

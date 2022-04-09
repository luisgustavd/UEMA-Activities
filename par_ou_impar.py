## PYTHON 3 ##

# EXERCÍCIO #
# Faça um programa que peça para o usuário digitar um número e este verificar se é ímpar ou par
# no caso do número não ser inteiro, retornar uma mensagem de aviso.

num = input("Digite um número:")
if num.isdigit():
    num = int(num)
    if num%2 == 0:
        print("Este número é PAR!")
    else:
        print("Este número é ÍMPAR!")
else:
    print("Não pode converter!Não é um número inteiro")

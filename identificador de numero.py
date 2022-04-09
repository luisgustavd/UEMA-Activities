# PYTHON 3
import re # importando biblioteca de sistema operacional
#Definindo funções:
def is_float(val):
    if isinstance(val, float): return True
    if re.search(r'^\-{,1}[0-9]+\.{1}[0-9]+$', val): return True

    return False


def is_int(val):
    if isinstance(val, int): return True
    if re.search(r'^\-{,1}[0-9]+$', val): return True

    return False


def is_number(val):
    return is_int(val) or is_float(val)

###########
#  USAGE  #
###########
x = input("Digite um número:\t")
if is_number(x):
    if is_int(x):
        print("Este é um número inteiro!")
    else:
        print("Este é um número decimal!")
else:
    print("Isto não é um número!")
############
#    END   #
############
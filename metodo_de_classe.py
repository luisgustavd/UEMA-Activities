class Pessoa:
    ano_atual= 2022 #Atributo de classe
    def __init__(self,nome,idade):
        self.nome = nome
        self.idade = idade

    def get_data_de_nascimento(self):
        print(self.ano_atual - self.idade)

    @classmethod #DECORADOR
    def por_ano_de_nascimento(cls,nome,ano_nascimento): # MÉTODO DE CLASSE QUE CRIA OBJETOS
        idade = cls.ano_atual - ano_nascimento
        return cls(nome, idade)

p1 = Pessoa.por_ano_de_nascimento("Luis Gustavo",2002) # PASSANDO PARÂMETROS
print(p1)
print(p1.nome, p1.idade) # IMPRIMINDO
p1.get_data_de_nascimento()
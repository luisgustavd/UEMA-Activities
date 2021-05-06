using System;
namespace C__.NET{
    class Program{
        static void Main(string[] args){
            /*
            Em C# existe três tipos de variáveis númericas
            String (nome da variável) = "Texto";
            Int__ recebe o tamanho de um número inteiro na memória
            float recebe um número de ponto flutuante
            Double recebe valores númericos reais
            Bool variável do tipo booleano (false or true)
            */
            String MeuTexto = "Meu Texto";
            Int16 MeuNumeroInteiro = 15;
            Double MeuNumeroReal = 8.25;

            Console.WriteLine(MeuTexto);
            Console.WriteLine("Eu sou o Luis IA, seu assistente!");
            Console.WriteLine(MeuNumeroReal + MeuNumeroInteiro);
            Console.WriteLine(MeuNumeroInteiro);
            Console.ReadLine();
        }
    }
}
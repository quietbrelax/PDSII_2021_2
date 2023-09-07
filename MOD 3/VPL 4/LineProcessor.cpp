#include <regex>
#include <math.h>
#include <string>
#include <vector>
#include <sstream>

#include "LineProcessor.hpp"

void LinePrinter::processaLinha(const std::string &str) {
  std::cout << str << std::endl;
}

bool ContadorPopRural::linhaValida(const std::string &str) const {
  // Neste exemplo usaremos expressoes regulares para verificar se uma linha
  // eh valida ou nao.
  //
  // Esta expressao regular eh formada por cinco partes. Cada uma dessas
  // partes eh um dos tres tipos de padrao regular abaixo:
  //
  // \\w+ eh qualquer palavra com um ou mais digitos, letras e sublinhas (_)
  // \\s* eh qualquer sequencia de zero ou mais espacos (inclui tab)
  // \\d+ eh qualquer sequencia de um ou mais digitos
  std::regex regularExpr("\\w+\\s*\\d+\\s*\\d+");

  // A funcao regex_match vai retornar verdadeiro se a string str casa-se com
  // a expressao regular que acabamos de criar:
  return std::regex_match(str, regularExpr);
}

void ContadorPopRural::processaLinha(const std::string &str) {
  //
  // Em geral eh mais facil ler dados de uma string se a string eh transformada
  // em um objeto do tipo stringstream:
  std::stringstream ss(str);
  //
  // Iremos ler os dados da string nestas tres variaveis abaixo:
  std::string nomePais;
  unsigned populacao, percUrbana;
  //
  // Como sabemos que a linha contem string int int, podemos fazer a leitura
  // facilmente usando o operador de streaming:
  ss >> nomePais >> populacao >> percUrbana;
  //
  // Note que precisamos arredondar o valor que serah impresso. O arredondamento
  // serah feito via a funcao floor. Ou seja, decimais serao sempre
  // arredondados para baixo:
  unsigned popRural = floor(populacao - (populacao * (percUrbana/100.0)));
  //
  // Uma vez encontrados os valores que precisam ser impressos, seguimos o
  // modelo do enunciado do exercicio:
  std::cout << popRural << " pessoas vivem no campo no " << nomePais <<
    std::endl;
}

bool ContadorNumNaturais::linhaValida(const std::string &str) const {
  // TODO: Implemente este metodo
  std::regex regularExpr("\\d+(\\s*\\d+)?(\\s*\\d+\\s*\\d+)?(\\s*\\d+\\s*\\d+\\s*\\d+)?(\\s*\\d+\\s*\\d+\\s*\\d+\\s*\\d+)?");
    return std::regex_match(str, regularExpr);
}

void ContadorNumNaturais::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  int soma = 0, num = 0;
  std::string aux;
  for(int i = 0; i < str.length(); i++)
  {
      if(str[i] != ' ')
      {
          aux += str[i];
      }
      if(str[i] == ' ')
      {
        std::stringstream ss;  
        ss << aux;  
        ss >> num;
        soma += num;
        aux.clear();
      }
      if(i == str.length() - 1)
      {
        std::stringstream ss;  
        ss << aux;  
        ss >> num;
        soma += num;
        aux.clear();
      }
  }
  std::cout << soma << std::endl;
}

bool LeitorDeFutebol::linhaValida(const std::string &str) const {
  // TODO: Implemente este metodo
  std::regex regularExpr("(\\s*)?\\w+\\s*\\d+\\s*\\w+\\s*\\d+");
  return std::regex_match(str, regularExpr);
}

void LeitorDeFutebol::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  std::stringstream ss(str);
  std::string timeUm, timeDois;
  int pontUm, pontDois;
  ss >> timeUm >> pontUm >> timeDois >> pontDois;
  if(pontUm > pontDois)
  {
      std::cout << "Vencedor: " << timeUm << std::endl;
  }
  if(pontUm < pontDois)
  {
      std::cout << "Vencedor: " << timeDois << std::endl;
  }
  if(pontUm == pontDois)
  {
      std::cout << "Empate"<< std::endl;
  }
  
}

void ContadorDePalavras::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  int contador = 0;
  for(int i = 0; i < str.length(); i++)
  {
      if(i != 0)
      {
        if(str[i] == ' ')
        {
          contador++;
        }
      }
  }
  std::cout << contador + 1 << std::endl;
}

bool InversorDeFrases::linhaValida(const std::string &str) const {
  // TODO: Implemente este metodo
  for(int i = 0; i < str.length(); i++)
  {
     if(str[i] != ' ')
     {
      if(!isalpha(str[i]))
      {
          return false;
      }
     }
  }
  return true;
}

void InversorDeFrases::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  std::vector<std::string> frase { };
  std::string aux;
  for(int i = 0; i < str.length(); i++)
  {
      if(str[i] != ' ')
      {
          aux += str[i];
      }
      if(str[i] == ' ')
      {
        frase.push_back(aux);
        aux.clear();
      }
      if(i == str.length() - 1)
      {
        frase.push_back(aux);
        aux.clear();
      }
  }
  for(int i = frase.size(); i > 0; i--)
  {
      std::cout << frase[i - 1];
      if(i != 1)
      {
          std::cout << " ";
      }
  }
  
  std::cout << std::endl;
  
}

bool EscritorDeDatas::linhaValida(const std::string &str) const {
  std::string dateFormat = "\\s*\\d\\d?/\\d\\d?/\\d{4}";
  // TODO: Implemente este metodo
  // Note que você pode usar uma expressao regular como:
  // "\\s*\\d\\d?/\\d\\d?/\\d{4}" para saber se a linha eh valida:
  std::regex regularExpr(dateFormat);
  return std::regex_match(str, regularExpr);
}

void EscritorDeDatas::processaLinha(const std::string &str) {
  // TODO: Implemente este metodo:
  // Lembre-se que as iniciais dos meses sao:
  // "Jan", "Fev", "Mar", "Abr", "Mai", "Jun", "Jul", "Ago", "Set", "Out",
  // "Nov", e "Dez".
  
  std::vector<std::string> meses {"Jan", "Fev", "Mar", "Abr", "Mai", "Jun", 
  "Jul", "Ago", "Set", "Out", "Nov", "Dez" };
  std::string aux;
  int mesAtual = 0;
  for(int i = 0; i < str.length(); i++)
  {
      if(str[i - 1] == '/' && str[i+1] == '/')
      {
          aux = str[i];
      }
      if(str[i - 1] == '/' && str[i+2] == '/')
      {
          aux += str[i];
          aux += str[i + 1];
      }
  }
    std::stringstream ss;  
    ss << aux;  
    ss >> mesAtual;
  std::cout << meses[mesAtual - 1] << std::endl;
}
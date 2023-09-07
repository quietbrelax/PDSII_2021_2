#include "celular.hpp"
#include <iostream>
#include <iomanip>

// TODO: Inicialize aqui sua variavel estatica. Caso tenha optado por essa
// solucao.
int Celular::cod = 0;

Celular::Celular(std::string modelo, std::string fabricante, int armazenamento,
                 int memoria, double peso, std::string cor, int qtd, float valor) {
  // TODO: Implemente este metodo
    char c;
    Celular::cod++;
    this -> modelo = modelo;
    this -> fabricante = fabricante;
    this -> armazenamento = armazenamento;
    this -> memoria = memoria;
    this -> peso = 1000 * peso;
    this -> cor = cor;
    if(this -> cor[0] > 90)
    {
        c = cor[0];
        this -> cor[0] = toupper(c);
    }
    this -> qtd = qtd;
    this -> valor = valor;
    
    this -> codUtil = cod;
    
}

bool Celular::operator<(const Celular& other) {
  // TODO: Implemente este metodo. 
  // Preste atencao no exemplo que a descricao utilizada na ordenacao considera
  // a fabricante antes do modelo do celular
  if(this -> codUtil < other.codUtil)
  {
        return true;
  }
  
  return false;
}

void Celular :: imprimir_dados() const{
   std::cout << std::setprecision(2) << std::fixed;
    if(qtd == 1)
    {
        std :: cout << fabricante << " " << modelo << ", " << armazenamento <<
        "GB, " << memoria << "GB RAM, " << (int)peso << " gramas, " << cor << ", "
        << qtd << " restante, " << "R$ " << valor << std :: endl;
    }

    else if(qtd > 1)
    {
        std :: cout << fabricante << " " << modelo << ", " << armazenamento <<
        "GB, " << memoria << "GB RAM, " << (int)peso << " gramas, " << cor << ", "
        << qtd << " restantes, " << "R$ " << valor << std :: endl;
    }

}
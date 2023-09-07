#include "pizza.hpp"

std::string Pizza::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da pizza.
   *
   * Exemplos:
   * 2X Pizza Calabresa, 4 pedacos e borda recheada.
   * 2X Pizza Calabresa, 4 pedacos sem borda recheada.
   */
   std::string descricao;
    descricao = m_qtd + 48;
    descricao += "X Pizza ";
    descricao += sabor;
    descricao += ", ";
    if(pedacos >= 10)
    {
        descricao += (pedacos/10) + 48;
    }
    descricao += (pedacos%10) + 48;
    descricao += " pedacos ";
    descricao += "e";
    if(!borda_recheada)
    {
        descricao += " sem";
    }
    
    descricao += " borda recheada.";
    descricao += '\n';
   
  return descricao;
}

Pizza::Pizza(const std::string& sabor,
             int pedacos,
             bool borda_recheada,
             int qtd,
             float valor_unitario) {
  // TODO: Implemente este metodo.
  this -> sabor = sabor;
  this -> pedacos = pedacos;
  this -> borda_recheada = borda_recheada;
  this -> m_qtd = qtd;
  this -> m_valor_unitario = valor_unitario;
}
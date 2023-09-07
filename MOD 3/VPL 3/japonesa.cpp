#include "japonesa.hpp"

std::string Japonesa::descricao() const {
  // TODO: Implemente este metodo.
  /*
   * Note que aqui voce deve retornar uma descricao detalhada da comida
   * japonesa.
   *
   * Exemplos:
   * 1X Comida japonesa - Combo 1, 4 sushis, 5 temakis e 6 hots.
   * 1X Comida japonesa - Combo 2, 5 sushis, 6 temakis e 8 hots.
   */
    std::string descricao;
    descricao = m_qtd + 48;
    descricao += "X Comida japonesa - ";
    descricao += combinado;
    descricao += ", ";
    if(sushi >= 10)
    {
        descricao += (sushi/10) + 48;
    }
    descricao += (sushi%10) + 48;
    descricao += " sushis, ";
    if(temaki >= 10)
    {
        descricao += (temaki/10) + 48;
    }
    descricao += (temaki%10) + 48;
    descricao += " temakis e ";
    if(hots >= 10)
    {
        descricao += (hots/10) + 48;
    }
    descricao += (hots%10) + 48;
    descricao += " hots.";
    descricao += '\n';

  return descricao;
}

Japonesa::Japonesa(const std::string& combinado,
                   int sushis,
                   int temakis,
                   int hots,
                   int qtd,
                   float valor_unitario) {
  // TODO: Implemente este metodo.
  this -> combinado = combinado;
  this -> sushi = sushis;
  this -> temaki = temakis;
  this -> hots = hots;
  this -> m_qtd = qtd;
  this -> m_valor_unitario = valor_unitario;
}
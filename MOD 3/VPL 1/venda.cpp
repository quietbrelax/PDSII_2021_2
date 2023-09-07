#include "venda.hpp"

#include <cmath>
#include <iomanip>
#include <iostream>

bool ordem_alf (const Celular& first, const Celular& second)
{
  if(first.fabricante < second.fabricante)
  {
    return true;
  }
  if(first.fabricante == second.fabricante)
  {
      if(first.modelo < second.modelo)
      {
          return true;
      }
  }
  return false;
}

void Venda::adicionaCelular(const Celular& celular) {
  // TODO: Implemente este metodo
    m_celulares.push_back(celular);
}

void Venda::ordena() {
  // TODO: Implemente este metodo
  // Preste atencao no exemplo que a descricao utilizada na ordenacao considera
  // a fabricante antes do modelo do celular. sort
    m_celulares.sort(ordem_alf);
    
}

void Venda::recarregaEstoque(int cod, int qtd) {
  // TODO: Implemente este metodo
  for (std::list<Celular>::iterator it=m_celulares.begin(); it != m_celulares.end(); ++it)
  {
      if(it->codUtil == cod)
      {
        it->qtd += qtd;
      }
  }
}

void Venda::efetuaVenda(int cod, int qtd) {
  // TODO: Implemente este metodo
  /**
   * Observe na descricao do enunciado que nao e permita a venda de um modelo
   * cuja quantidade seja maior que a quantidade atual em estoque.
   * Ex: Se existirem apenas 5 celulares Motorola Moto G50 em estoque, vendas a
   * partir de 6 unidades devem ser ignoradas.
   */
  for (std::list<Celular>::iterator it=m_celulares.begin(); it != m_celulares.end(); ++it)
  {
      if(it -> codUtil == cod && it -> qtd >= qtd)
      {
          if(it -> qtd >= qtd)
        it -> qtd -= qtd;
      }
  }
}

void Venda::aplicaDesconto(const std::string& fabricante, float desconto) {
  // TODO: Implemente este metodo
  for (std::list<Celular>::iterator it=m_celulares.begin(); it != m_celulares.end(); ++it)
  {
      if(it -> fabricante == fabricante)
      {
        it -> valor -= it -> valor * (desconto/100);
      }
  }
}

void Venda::removeModelo(int cod) {
  // TODO: Implemente este metodo
  for (std::list<Celular>::iterator it=m_celulares.begin(); it != m_celulares.end(); ++it)
  {
      if(it -> codUtil == cod)
      {
        it -> qtd -= it -> qtd;
      }
      
  }
  
}

void Venda::imprimeEstoque() const{
  // TODO: Implemente este metodo.
  /**
   * Aqui voce tera que imprimir a lista de celulares em estoque com as
   * restricoes descritas no enunciado do problema. Notem no exemplo que a
   * primeira letra da cor do celular fica maiuscula. Outra coisa, se houver
   * apenas um item em estoque de determinado modelo de celular, voce tera que
   * imprimir '1 restante' e nao '1 restantes'. Por ultimo, apenas modelos de
   * celulares com pelo menos um item em estoque deverao ser exibidos.
   */
  for (std::list<Celular>::const_iterator it=m_celulares.begin(); it != m_celulares.end(); ++it)
  {
    it -> imprimir_dados();
  }
}
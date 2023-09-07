#include "pedido.hpp"


Pedido::~Pedido() {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_produtos
   */
  m_produtos.clear();
}

void Pedido::setEndereco(const std::string& endereco) {
  // TODO: Implemente este metodo.
  this -> m_endereco = endereco;
}

float Pedido::calculaTotal() const {
  // TODO: Implemente este metodo.
  float somaValores = 0;
  for (std::list<Produto*>::const_iterator it=m_produtos.begin(); 
  it != m_produtos.end(); ++it)
   {
       somaValores += (*it) -> getValor() * (*it) -> getQtd(); 
   }
  return somaValores;
}

void Pedido::adicionaProduto(Produto* p) {
  // TODO: Implemente este metodo.
  m_produtos.push_back(p);
}

std::string Pedido::resumo() const {
  // TODO: Implemente este metodo.
  /**
   * Aqui voce deve percorrer a lista de produtos para criar um resumo completo
   * do pedido. A cada iteracao, utilize o metodo descricao de cada produto para
   * montar o resumo do pedido. Por fim, adicione o endereco de entrega.
   *
   */
   std::string resumo;
   for (std::list<Produto*>::const_iterator it=m_produtos.begin(); 
   it != m_produtos.end(); ++it)
   {
       resumo += (*it) -> descricao();
   }
    resumo += "Endereco: ";
    resumo += m_endereco;
   
  return resumo;
}
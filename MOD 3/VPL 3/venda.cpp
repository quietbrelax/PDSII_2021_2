#include "venda.hpp"

#include <iomanip>


Venda::~Venda() {
  // TODO: Implemente este metodo
  /**
   * Aqui voce deve deletar os ponteiros contidos na lista m_pedidos
   */
   m_pedidos.clear();
}

void Venda::adicionaPedido(Pedido* p) {
  // TODO: Implemente este metodo
  m_pedidos.push_back(p);
}

void Venda::imprimeRelatorio() const {
  // TODO: Implemente este metodo
  /**
   * Aqui voce tem que percorrer a lista de todos os pedidos e imprimir o resumo
   * de cada um. Por ultimo, devera ser exibido o total de venda e a quantidade
   * de pedidos processados.
   */
   float valorVenda = 0;
   int pedidosProcessados = 0;
   int pedido = 1;
   for (std::list<Pedido*>::const_iterator it=m_pedidos.begin(); it != m_pedidos.end(); ++it)
   {
       std :: cout << "Pedido " << pedido << '\n' << (*it)->resumo() 
       << std :: endl;
       valorVenda += (*it) -> calculaTotal();
       pedido ++;
       
   }
   pedidosProcessados =  m_pedidos.size();
   
   std::cout << std::setprecision(2) << std::fixed;
   std :: cout << "Relatorio de vendas" << '\n' << "Total de vendas: R$ " 
   << valorVenda << '\n' << "Total de pedidos: " << pedidosProcessados 
   << std :: endl;

}
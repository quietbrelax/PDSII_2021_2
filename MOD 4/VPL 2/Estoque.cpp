#include <string>
#include <map>

#include "Estoque.hpp"

bool compara(pair<string, int>& a, pair<string, int>& b)
{
    return a.first < b.first;
}

void sort(map<string, int>& M)
{
    vector<pair<string, int> > A;
    for (auto& it : M) {
        A.push_back(it);
    }
    sort(A.begin(), A.end(), compara);
}

void Estoque::add_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  // TODO
  unsigned int qtdAtual = 0;
  if(mapEstoque.count(mercadoria) <= 0)
  {
    mapEstoque.insert(std::pair<std::string, int>(mercadoria, qtd));
  }
  else
  {
    qtdAtual = mapEstoque.find(mercadoria)->second + qtd;
    mapEstoque.find(mercadoria)->second = qtdAtual;
  }
}

void Estoque::sub_mercadoria(const std::string& mercadoria, unsigned int qtd) {
  // TODO
  unsigned int qntNova = 0;
  if(mapEstoque.count(mercadoria) <= 0)
  {
    std::cout << mercadoria << "inexistente" << std::endl;
  }
  else if(mapEstoque.find(mercadoria)->second < qtd)
  {
    std::cout << mercadoria << "insuficiente" << std::endl;
  }
  else
  {
    qtdNova = mapEstoque.find(mercadoria)->second - qtd;
    mapEstoque.find(mercadoria)->second = qtdNova;
  }
}

unsigned int Estoque::get_qtd(const std::string& mercadoria) const {
  // TODO
  unsigned int qnt = 0;
  if(mapEstoque.count(mercadoria) > 0)
  {
      qnt = mapEstoque.find(mercadoria)->second;
  }
  return qnt;
}

void Estoque::imprime_estoque() const {
  // TODO
    sort(mapEstoque);
    for (auto it = mapEstoque.begin(); it != mapEstoque.end(); it++) 
    {
        std::cout << it -> first << ", " << it -> second << std::endl;
    }
}

Estoque& Estoque::operator += (const Estoque& rhs) {
  // TODO
  for (auto it = rhs -> mapEstoque.begin(); it != rhs -> mapEstoque.end(); it++) 
    {
        if(mapEstoque.count(it -> first) > 0)
        {
            mapEstoque.find(it -> first) -> second += it -> second;
        }
        else
        {
            mapEstoque.insert(it);
        }
    }
  return *this;
}

Estoque& Estoque::operator -= (const Estoque& rhs) {
  // TODO
  for (auto it = rhs.mapEstoque.begin(); it != rhs.mapEstoque.end(); it++) 
    {
        if(mapEstoque.count(it -> first) > 0)
        {
            mapEstoque.find(it -> first) -> second -= it -> second;
        }
    }
  return *this;
}

bool operator < (Estoque& lhs, Estoque& rhs) {
  // TODO
  //tudo que esta em lhs esta em rhs
  for (auto it = rhs.mapEstoque.begin(); it != rhs.mapEstoque.end(); it++) 
    {
        if(mapEstoque.count(it -> first) <= 0)
        {
            return false;
        }
        else if(mapEstoque.find(it -> first) -> second > it -> second)
        {
            return false;
        }
    }
  return true;
}

bool operator > (Estoque& lhs, Estoque& rhs) {
  // TODO
  return false;
}
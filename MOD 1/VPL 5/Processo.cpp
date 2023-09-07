#include <iostream>
#include <cmath>
#include <string>
using namespace std;

#include "Processo.hpp"

Processo :: Processo(int id, string nome, int prioridade){

    _id = id;
    _nome = nome;
    _prioridade = prioridade;

}

void Processo :: imprimir_dados(){

    cout << _id << " " << _nome << " " << _prioridade << endl;
    
}
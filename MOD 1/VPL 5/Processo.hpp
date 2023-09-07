#ifndef PROCESSOS_H
#define PROCESSOS_H

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

struct Processo {
    
    //Atributos
    int _id, _prioridade;
    string _nome;
    Processo* next; 

    //Funçoes

    Processo(int id, string nome, int prioridade);
    void imprimir_dados();
    
};

#endif
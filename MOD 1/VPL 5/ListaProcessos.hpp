#ifndef LISTAPROCESSOS_H
#define LISTAPROCESSOS_H

#include <iostream>
#include <cmath>
#include "Processo.hpp"
#include "ListaProcessos.hpp"

struct Node {
    Processo* processoEndereco;
    Node* next;
};

struct ListaProcessos {
    
    Node * head = nullptr;
    Node * tail = nullptr;

    void adicionar_processo(Processo* proc);
    Processo* remover_processo_maior_prioridade();
    Processo* remover_processo_menor_prioridade();
    Processo* remover_processo_por_id(int id);
    void imprimir_lista();

};

#endif
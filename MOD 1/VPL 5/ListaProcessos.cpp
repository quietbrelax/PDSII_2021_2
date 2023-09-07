#include <iostream>
#include <cmath>
#include <string>
using namespace std;

#include "Processo.hpp"
#include "ListaProcessos.hpp"



void ListaProcessos :: adicionar_processo(Processo* proc)
{
    //cria novo processo
    Node* aux = new Node;
    Node* auxPrevious = new Node;
    Node* current = head;
    aux -> next = nullptr;
    aux -> processoEndereco = proc;
    
    while (current != nullptr)
    {
        if(current->next == tail)
        {
            auxPrevious = current;
        }
        current = current->next;
    }
    
    //ajuste head
    if(head == nullptr)
    {
        head = aux;
        tail = aux;
    }
    
    else if(head->processoEndereco->_prioridade < aux->processoEndereco->_prioridade)
    {
        aux -> next = head;
        head = aux;
    }
    
    else if(head->processoEndereco->_prioridade == aux->processoEndereco->_prioridade)
    {   
        if(head->processoEndereco->_id > aux->processoEndereco->_id)
        {
            aux -> next = head;
            head = aux;
        }
        else
        {
           aux -> next = head -> next;
           head -> next = aux;
        }
    }

    //ajuste tail
    
    else
    {  
        if(tail->processoEndereco->_prioridade > aux->processoEndereco->_prioridade)
        {
            tail -> next = aux;
            tail = aux;
        }
        else
        {
            auxPrevious->next = aux;
            aux->next = tail; 
        }
    } 
    
}

Processo* ListaProcessos :: remover_processo_maior_prioridade()
{

    Node* current = head;
    Node* previous = nullptr;
    int maiorPrioridade = 0;

    while (current != nullptr)
    {
        if(current->processoEndereco-> _prioridade > maiorPrioridade)
        {
            maiorPrioridade = current->processoEndereco-> _prioridade;
        }
        previous = current;
        current = current->next;
    }

    current = head;
    previous = nullptr;

    while (current != nullptr)
    {
        if (current->processoEndereco-> _prioridade == maiorPrioridade)
        {
            if (previous == nullptr)
            { // HEAD
                head = current->next;
            }   
            else if (current->next == nullptr)
            { //TAIL
                previous->next = nullptr;
                tail = previous;
            } 
            else
            {
                previous->next = current->next;
            }
            return current->processoEndereco;
        }
        previous = current;
        current = current->next;
    }   
    return current->processoEndereco;
}

Processo* ListaProcessos :: remover_processo_menor_prioridade()
{
    Node* current = head;
    Node* previous = nullptr;
    int menorPrioridade = current->processoEndereco->_prioridade;

    while (current != nullptr)
    {
        if(current->processoEndereco->_prioridade < menorPrioridade)
        {
            menorPrioridade = current->processoEndereco-> _prioridade;
        }
        previous = current;
        current = current->next;
    }

    current = head;
    previous = nullptr;

    while (current != nullptr)
    {
        if (current->processoEndereco-> _prioridade == menorPrioridade)
        {
            if (previous == nullptr)
            { // HEAD
                head = current->next;
            }   
            else if (current->next == nullptr)
            { //TAIL
                previous->next = nullptr;
                tail = previous;
            } 
            else
            {
                previous->next = current->next;
            }
            return current->processoEndereco;
        }
        previous = current;
        current = current->next;
    }   
    return current->processoEndereco;
}

Processo* ListaProcessos :: remover_processo_por_id(int id)
{
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr)
    {
        if (current->processoEndereco->_id == id)
        {
            if (previous == nullptr)
            { // HEAD
                head = current->next;
            }   
            else if (current->next == nullptr)
            { //TAIL
                previous->next = nullptr;
                tail = previous;
            } 
            else
            {
                previous->next = current->next;
            }
            return current->processoEndereco;
        }
        previous = current;
        current = current->next;
    }

    return nullptr;   
    
}

void ListaProcessos :: imprimir_lista()
{
    Node *aux = head;
    while (aux != nullptr) 
    {
        aux -> processoEndereco ->imprimir_dados();
        aux = aux->next;
    }
    
}
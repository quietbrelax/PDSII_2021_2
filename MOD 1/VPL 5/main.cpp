// NÃO ALTERE ESSA LINHA
#include "avaliacao_basica_escalonador.hpp"

#include <iostream>
 #include "Processo.hpp"
 #include "ListaProcessos.hpp"

 int main() {

    // Criando um ponteiro para novos processos
    Processo* novoProcesso;
    ListaProcessos listaDeProcessos;
    int id, prioridade;
    string nome;
    // Executando as ações
    char data;

    while (cin >> data) {
        switch (data) {
            
            // Adicionando novo processo
            case 'a':   
                
                cin >> id >> nome >> prioridade;
                novoProcesso = new Processo(id, nome, prioridade);
                listaDeProcessos.adicionar_processo(novoProcesso);
                break;

            // Removendo o processo de maior prioridade
            case 'm': 

                listaDeProcessos.remover_processo_maior_prioridade();
                
                break;

            // Removendo o processo de menor prioridade
            case 'n':                  
                
                listaDeProcessos.remover_processo_menor_prioridade();
                
                break;   

            // Removendo processo de acordo com o id
            case 'r':                  
                cin >> id;
                listaDeProcessos.remover_processo_por_id(id);
                
                break;     

            // Imprime lista
            case 'p':                  
                
                listaDeProcessos.imprimir_lista();
                
                break;

            //Comando de avaliação    
            case 'b':                  
                
                avaliacao_basica();
                
                break;                                           
        }
    }
    //
    

    return 0;
}
#ifndef CHAMADO_H
#define CHAMADO_H

#include <string>
#include "Cliente.h"
#include "Tecnico.h"

class Chamado {
protected:
    int id;
    std::string descricao;
    std::string status;
    std::string relatorioSolucao;
    Cliente cliente;          
    Tecnico* tecnicoAlocado;  

public:
    Chamado(int id, Cliente cl, std::string desc);
    virtual ~Chamado();

    virtual int calcularSLA() const; 
    
    bool atribuirTecnico(Tecnico* t);      
    bool encerrarChamado(std::string rel); 

    int getId() const;
    std::string getStatus() const;
    std::string getDescricao() const;
    std::string getRelatorio() const;
    Tecnico* getTecnico() const;
    Cliente getCliente() const;
};

#endif
#ifndef CENTRALATENDIMENTO_H
#define CENTRALATENDIMENTO_H

#include <vector>
#include "Chamado.h"

class CentralAtendimento {
private:
    std::vector<Chamado*> chamados; 
    int proximoId;

public:
    CentralAtendimento();
    ~CentralAtendimento();

    void abrirChamado(Cliente cl, std::string desc);
    void abrirChamado(Cliente cl, std::string desc, std::string equipamento);

    void listarChamados() const;
    Chamado* buscarChamado(int id);
};

#endif
#ifndef CHAMADOINFRAESTRUTURA_H
#define CHAMADOINFRAESTRUTURA_H

#include "Chamado.h"

class ChamadoInfraestrutura : public Chamado { 
private:
    std::string equipamentoAfetado;

public:
    ChamadoInfraestrutura(int id, Cliente cl, std::string desc, std::string equipamento);
    int calcularSLA() const override; 
    std::string getEquipamento() const;
};

#endif
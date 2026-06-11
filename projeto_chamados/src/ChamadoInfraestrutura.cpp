#include "ChamadoInfraestrutura.h"

ChamadoInfraestrutura::ChamadoInfraestrutura(int id, Cliente cl, std::string desc, std::string equipamento)
    : Chamado(id, cl, desc), equipamentoAfetado(equipamento) {}

int ChamadoInfraestrutura::calcularSLA() const { return 8; }

std::string ChamadoInfraestrutura::getEquipamento() const { return equipamentoAfetado; }
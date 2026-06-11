#include "CentralAtendimento.h"
#include "ChamadoInfraestrutura.h"
#include <iostream>

CentralAtendimento::CentralAtendimento() : proximoId(1) {}

CentralAtendimento::~CentralAtendimento() {
    for (Chamado* c : chamados) delete c;
    chamados.clear();
}

void CentralAtendimento::abrirChamado(Cliente cl, std::string desc) {
    Chamado* novo = new Chamado(proximoId++, cl, desc);
    chamados.push_back(novo);
    std::cout << "[CENTRAL] Criado Chamado Comum ID: " << novo->getId() << " (SLA: " << novo->calcularSLA() << "h)\n";
}

void CentralAtendimento::abrirChamado(Cliente cl, std::string desc, std::string equipamento) {
    Chamado* novo = new ChamadoInfraestrutura(proximoId++, cl, desc, equipamento);
    chamados.push_back(novo);
    std::cout << "[CENTRAL] Criado Chamado Infra ID: " << novo->getId() << " (SLA: " << novo->calcularSLA() << "h)\n";
}

void CentralAtendimento::listarChamados() const {
    std::cout << "\n=== STATUS DOS CHAMADOS EM MEMORIA ===\n";
    for (const Chamado* c : chamados) {
        std::cout << "ID: " << c->getId() << " | [" << c->getStatus() << "] | Cliente: " << c->getCliente().getNome() << "\n";
    }
    std::cout << "======================================\n\n";
}

Chamado* CentralAtendimento::buscarChamado(int id) {
    for (Chamado* c : chamados) {
        if (c->getId() == id) return c;
    }
    return nullptr;
}
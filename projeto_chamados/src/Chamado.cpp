#include "Chamado.h"
#include <iostream>

Chamado::Chamado(int id, Cliente cl, std::string desc)
    : id(id), cliente(cl), descricao(desc), status("Aberto"), tecnicoAlocado(nullptr), relatorioSolucao("") {}

Chamado::~Chamado() {}

int Chamado::calcularSLA() const { return 24; }

bool Chamado::atribuirTecnico(Tecnico* t) {
    if (!t) return false;
    if (t->getChamadosAtivos() >= t->getLimiteMaximo()) {
        std::cout << "[ERRO] Tecnico " << t->getNome() << " com limite maximo atingido.\n";
        return false;
    }
    tecnicoAlocado = t;
    t->incrementarChamados();
    status = "Em Atendimento";
    return true;
}

bool Chamado::encerrarChamado(std::string relatorio) {
    if (!tecnicoAlocado) {
        std::cout << "[ERRO] Chamado " << id << " sem tecnico atribuido.\n";
        return false;
    }
    if (relatorio.empty()) {
        std::cout << "[ERRO] Relatorio de solucao vazio.\n";
        return false;
    }
    relatorioSolucao = relatorio;
    status = "Encerrado";
    tecnicoAlocado->decrementarChamados();
    return true;
}

int Chamado::getId() const { return id; }
std::string Chamado::getStatus() const { return status; }
std::string Chamado::getDescricao() const { return descricao; }
std::string Chamado::getRelatorio() const { return relatorioSolucao; }
Tecnico* Chamado::getTecnico() const { return tecnicoAlocado; }
Cliente Chamado::getCliente() const { return cliente; }
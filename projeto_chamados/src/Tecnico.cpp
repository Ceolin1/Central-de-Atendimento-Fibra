#include "Tecnico.h"

Tecnico::Tecnico(std::string nome, int limiteMaximo) 
    : nome(nome), chamadosAtivos(0), limiteMaximo(limiteMaximo) {}

std::string Tecnico::getNome() const { return nome; }
int Tecnico::getChamadosAtivos() const { return chamadosAtivos; }
int Tecnico::getLimiteMaximo() const { return limiteMaximo; }

bool Tecnico::incrementarChamados() {
    if (chamadosAtivos < limiteMaximo) {
        chamadosAtivos++;
        return true;
    }
    return false;
}

void Tecnico::decrementarChamados() {
    if (chamadosAtivos > 0) chamadosAtivos--;
}
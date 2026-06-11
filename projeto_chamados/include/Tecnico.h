#ifndef TECNICO_H
#define TECNICO_H

#include <string>

class Tecnico {
private:
    std::string nome;
    int chamadosAtivos;
    int limiteMaximo;

public:
    Tecnico(std::string nome, int limiteMaximo = 2);
    std::string getNome() const;
    int getChamadosAtivos() const;
    int getLimiteMaximo() const;
    bool incrementarChamados();
    void decrementarChamados();
};

#endif
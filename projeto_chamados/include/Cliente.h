#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>

class Cliente {
private:
    std::string nome;
    std::string contrato;

public:
    Cliente();
    Cliente(std::string nome, std::string contrato);
    std::string getNome() const;
    std::string getContrato() const;
};

#endif
#include "Cliente.h"

Cliente::Cliente() : nome(""), contrato("") {}

Cliente::Cliente(std::string nome, std::string contrato) : nome(nome), contrato(contrato) {}

std::string Cliente::getNome() const { return nome; }
std::string Cliente::getContrato() const { return contrato; }
#include <iostream>
#include "CentralAtendimento.h"
#include "Cliente.h"
#include "Tecnico.h"

int main() {
    CentralAtendimento central;
    
    Cliente c1("Empresa Alfa", "CONTRATO-01");
    Cliente c2("Empresa Beta", "CONTRATO-02");

    Tecnico t1("Joao (Suporte)", 1); 
    Tecnico t2("Carlos (Infra)", 3);

    central.abrirChamado(c1, "Instabilidade no sinal");
    central.abrirChamado(c2, "Rompimento de Fibra Optica", "Switch-Central-01");

    central.listarChamados();

    Chamado* ch1 = central.buscarChamado(1);
    Chamado* ch2 = central.buscarChamado(2);

    std::cout << "--- Executando Mensagens e Validacoes ---\n";
    
    if (ch1) ch1->atribuirTecnico(&t1);
    if (ch2) ch2->atribuirTecnico(&t1); // É pra errar(já tem  tec trabalhando)
    if (ch2) ch2->atribuirTecnico(&t2); //Certo

    if (ch1) ch1->encerrarChamado(""); // é pra errar (vazio)
    if (ch1) ch1->encerrarChamado("Resolvido com reinicializacao da porta.");
    if (ch2) ch2->encerrarChamado("Fusao de fibra finalizada.");

    central.listarChamados();

    return 0;
}
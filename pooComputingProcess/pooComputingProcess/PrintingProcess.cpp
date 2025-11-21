#include "PrintingProcess.h"
#include <iostream>

PrintingProcess::PrintingProcess(){}
PrintingProcess::~PrintingProcess(){}

PrintingProcess::PrintingProcess(Fila* fila)
	: Processo(4)
{
	this->fila = fila;
}

void PrintingProcess::testeDown()
{
    std::cout << "DOWN FUNCIONANDO" << this->pid;
}

void PrintingProcess::execute()
{
    std::cout << "===== Processos na fila =====" << std::endl;

    Nodo* atual = fila->getPrimeiro();

    while (atual != nullptr) {
        Processo* p = atual->processo;
        std::cout << "PID: " << p->getPid()
            << " | Tipo: " << p->getTipo() << std::endl;
        atual = atual->proximo;
    }

    std::cout << "=============================" << std::endl;
}

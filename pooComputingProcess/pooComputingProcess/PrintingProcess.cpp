#include "PrintingProcess.h"

#define TIPO 4

PrintingProcess::PrintingProcess(){}
PrintingProcess::~PrintingProcess(){}

PrintingProcess::PrintingProcess(Fila* fila)
	: Processo(TIPO)
{
	this->fila = fila;
}

PrintingProcess::PrintingProcess(int pid, Fila* fila)
    : Processo(pid, TIPO)
{
    this->fila = fila;
}

void PrintingProcess::execute()
{
    std::cout << "===== Processos na fila =====" << std::endl;

    Nodo* atual = fila->getPrimeiro();

    while (atual != nullptr) {
        Processo* p = atual->processo;
        std::cout << "PID: " << p->getPid()
            << " | Tipo: " << p->getTipo() 
            << " | Serialize: " << p->serialize() << std::endl;
        atual = atual->proximo;
    }

    std::cout << "=============================" << std::endl;
}

std::string PrintingProcess::serialize() const
{
    return Processo::serialize();
}

Processo* PrintingProcess::deserialize(const std::string& linha, Fila* fila)
{
    std::stringstream ss(linha);
    std::string token;

    // formato esperado: pid;tipo
    int pid, tipo;

    // pega pid
    std::getline(ss, token, ';');
    pid = std::stoi(token);

    // pega tipo
    std::getline(ss, token, ';');
    tipo = std::stoi(token);

    if (tipo != TIPO) return nullptr;

    return new PrintingProcess(pid, fila);
}

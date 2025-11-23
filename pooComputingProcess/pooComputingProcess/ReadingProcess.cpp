#include "ReadingProcess.h"
#include "ComputingProcess.h"

#define TIPO 3

ReadingProcess::ReadingProcess(){}
ReadingProcess::~ReadingProcess(){}

ReadingProcess::ReadingProcess(Fila* fila)
	: Processo(TIPO)
{
	this->fila = fila;
}

ReadingProcess::ReadingProcess(int pid, Fila* fila)
    : Processo(pid, TIPO)
{
    this->fila = fila;
}

void ReadingProcess::execute()
{
    std::ifstream arquivo("computation.txt");

    if (!arquivo.is_open()) {
        std::cout << "Erro ao abrir computation.txt no processo PID " << this->pid << std::endl;
        return;
    }

    std::string linha;
    int count = 0;

    while (std::getline(arquivo, linha))
    {
        if (linha.empty()) continue;

        std::stringstream ss(linha);
        std::string token;

        // formato esperado: op;num1;num2
        char op;
        float n1, n2;

        // pegar operação
        std::getline(ss, token, ';');
        op = token[0];

        // pegar num1
        std::getline(ss, token, ';');
        n1 = std::stof(token);

        // pegar num2
        std::getline(ss, token, ';');
        n2 = std::stof(token);

        // cria o processo de computação e adiciona na fila
        fila->push(new ComputingProcess(op, n1, n2));
        count++;
    }

    arquivo.close();

    // limpar o arquivo depois de ler
    std::ofstream clear("computation.txt", std::ios::trunc);
    clear.close();

    std::cout << "PID " << pid << ": Leitura concluída. "
        << count << " processos adicionados à fila." << std::endl;
}

std::string ReadingProcess::serialize() const
{
    return Processo::serialize();
}

Processo* ReadingProcess::deserialize(const std::string& linha, Fila* fila)
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

    return new ReadingProcess(pid, fila);
}


#include "WritingProcess.h"

#define TIPO 2

WritingProcess::WritingProcess(){}
WritingProcess::~WritingProcess(){}

WritingProcess::WritingProcess(std::string expressao)
	: Processo(TIPO)
{
	// <operacao>;<num1>;<num2>
	this->expressao = expressao;
}

WritingProcess::WritingProcess(int pid, std::string expressao)
    : Processo(pid, TIPO)
{
    this->expressao = expressao;
}

void WritingProcess::execute()
{
    // Abre em modo append (não sobrescreve)
    std::ofstream arquivo("computation.txt", std::ios::app);

    if (!arquivo.is_open()) {
        std::cout << "Erro ao abrir o arquivo para gravacao no processo PID "
            << pid << std::endl;
        return;
    }

    // Grava a expressão + quebra de linha
    arquivo << expressao << std::endl;
    arquivo.close();

    std::cout << "PID " << pid << " gravou a expressao: " << expressao << std::endl;
}

std::string WritingProcess::serialize() const
{
    return Processo::serialize() + ";" + expressao;
}

Processo* WritingProcess::deserialize(const std::string& linha)
{
    std::stringstream ss(linha);
    std::string token;

    // formato esperado: pid;tipo;op;num1;num2
    int pid, tipo;
    char op;
    float n1, n2;

    // pega pid
    std::getline(ss, token, ';');
    pid = std::stoi(token);

    // pega tipo
    std::getline(ss, token, ';');
    tipo = std::stoi(token);

    // pegar operação
    std::getline(ss, token, ';');
    op = token[0];

    // pegar num1
    std::getline(ss, token, ';');
    n1 = std::stof(token);

    // pegar num2
    std::getline(ss, token, ';');
    n2 = std::stof(token);

    if (tipo != TIPO) return nullptr;

    std::string exp = std::string(1, op) + ";" + std::to_string(n1) + ";" + std::to_string(n2);

    return new WritingProcess(pid, exp);
}


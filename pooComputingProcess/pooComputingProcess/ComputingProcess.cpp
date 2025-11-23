#include "ComputingProcess.h"

#define TIPO 1

ComputingProcess::ComputingProcess(){};
ComputingProcess::~ComputingProcess(){};

ComputingProcess::ComputingProcess(char operacao, float num1, float num2)
	: Processo(TIPO)
{
    this->operacao = operacao;
	this->num1 = num1;
	this->num2 = num2;
}

ComputingProcess::ComputingProcess(int pid, char operacao, float num1, float num2)
    : Processo(pid, TIPO)
{
    this->operacao = operacao;
    this->num1 = num1;
    this->num2 = num2;
}

void ComputingProcess::execute()
{
    float resultado = 0;

    switch (this->operacao)
    {
    case '+':
        resultado = this->num1 + this->num2;
        break;

    case '-':
        resultado = this->num1 - this->num2;
        break;

    case '*':
        resultado = this->num1 * this->num2;
        break;

    case '/':
        if (this->num2 == 0) {
            std::cout << "Erro: divisao por zero no processo PID " << this->pid << std::endl;
            return;
        }
        resultado = this->num1 / this->num2;
        break;

    default:
        std::cout << "Operacao invalida no processo PID " << this->pid << std::endl;
        return;
    }

    std::cout << "Computacao PID " << this->pid << " => "
        << this->num1 << " " << this->operacao << " " << this->num2
        << " = " << resultado << std::endl;
}

std::string ComputingProcess::serialize() const
{
    return Processo::serialize() + ";" + operacao + ";" + std::to_string(num1) + ";" + std::to_string(num2);
}

Processo* ComputingProcess::deserialize(const std::string& linha)
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

    return new ComputingProcess(pid, op, n1, n2);
}


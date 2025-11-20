#include "ComputingProcess.h"
#include <iostream>

ComputingProcess::ComputingProcess(){};
ComputingProcess::~ComputingProcess(){};

ComputingProcess::ComputingProcess(float num1, float num2, char operacao)
	: Processo(1)
{
	this->num1 = num1;
	this->num2 = num2;
	this->operacao = operacao;
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

#include "WritingProcess.h"
#include <fstream>
#include <iostream>

WritingProcess::WritingProcess(){}
WritingProcess::~WritingProcess(){}

WritingProcess::WritingProcess(std::string expressao)
	: Processo(2)
{
	// <operacao>;<num1>;<num2>
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
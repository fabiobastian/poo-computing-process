#pragma once
#include "Processo.h"

class ComputingProcess : public Processo
{
private:
	int num1;
	int num2;
	char operacao;

public:
	ComputingProcess();
	~ComputingProcess();
	ComputingProcess(float num1, float num2, char operacao);

	void execute() override;
};


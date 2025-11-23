#pragma once
#include "Processo.h"

class ComputingProcess : public Processo
{
private:
	char operacao;
	int num1;
	int num2;

public:
	ComputingProcess();
	~ComputingProcess();
	ComputingProcess(char operacao, float num1, float num2);
	ComputingProcess(int pid, char operacao, float num1, float num2);

	void execute() override;
	std::string serialize() const override;
	static Processo* deserialize(const std::string& linha);
};


#pragma once
#include "Processo.h"

class WritingProcess : public Processo
{
private:
	// operacao;num1;num2    ex: "+;100;20"
	std::string expressao;

public:
	WritingProcess();
	~WritingProcess();
	WritingProcess(std::string expressao);
	WritingProcess(int pid, std::string expressao);

	void execute() override;
	std::string serialize() const override;
	static Processo* deserialize(const std::string& linha);
};


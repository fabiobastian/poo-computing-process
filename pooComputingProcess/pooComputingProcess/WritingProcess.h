#pragma once
#include "Processo.h"
#include <string>

class WritingProcess : public Processo
{
private:
	std::string expressao;

public:
	WritingProcess();
	~WritingProcess();
	WritingProcess(std::string expressao);

	void execute() override;
};


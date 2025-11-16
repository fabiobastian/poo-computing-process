#pragma once
#include "Processo.h"

class ComputingProcess : public Processo
{
public:
	ComputingProcess();
	~ComputingProcess();

	void executar() override;
};


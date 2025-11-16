#pragma once
#include "Processo.h"

class PrintingProcess : Processo
{
public:
	PrintingProcess();
	~PrintingProcess();

	void executar() override;
};


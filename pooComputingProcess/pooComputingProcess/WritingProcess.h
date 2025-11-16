#pragma once
#include "Processo.h"

class WritingProcess : Processo
{
public:
	WritingProcess();
	~WritingProcess();

	void executar() override;
};


#pragma once
#include "Processo.h"

class ReadingProcess : public Processo
{
public:
	ReadingProcess();
	~ReadingProcess();

	void executar() override;
};


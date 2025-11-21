#pragma once
#include "Processo.h"
#include "Fila.h"

class PrintingProcess : public Processo
{
private:
	Fila* fila;

public:
	PrintingProcess();
	~PrintingProcess();
	PrintingProcess(Fila* fila);
	void testeDown();

	void execute() override;
};


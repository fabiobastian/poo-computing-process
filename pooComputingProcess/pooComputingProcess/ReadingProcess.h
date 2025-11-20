#pragma once
#include "Processo.h"
#include "Fila.h"
#include <string>

class ReadingProcess : public Processo
{
private:
	Fila* fila;

public:
	ReadingProcess();
	~ReadingProcess();
	ReadingProcess(Fila* fila);

	void execute() override;
};


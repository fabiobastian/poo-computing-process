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
	PrintingProcess(int pid, Fila* fila);

	void execute() override;
	std::string serialize() const override;
	static Processo* deserialize(const std::string& linha, Fila* fila);
};


#pragma once
#include "Processo.h"
#include "Fila.h"

class ReadingProcess : public Processo
{
private:
	Fila* fila;

public:
	ReadingProcess();
	~ReadingProcess();
	ReadingProcess(Fila* fila);
	ReadingProcess(int pid, Fila* fila);

	void execute() override;
	std::string serialize() const override;
	static Processo* deserialize(const std::string& linha, Fila* fila);
};


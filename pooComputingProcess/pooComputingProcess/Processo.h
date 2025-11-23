#pragma once
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

class Processo
{
protected:
	int pid;
	int tipo;
	static int nextPid;

public:
	Processo();
	~Processo();

	// type: 1 - ComputingProcess
	// type: 2 - WritingProcess
	// type: 3 - ReadingProcess
	// type: 4 - PrintingProcess
	Processo(int tipo);
	Processo(int pid, int tipo);

	virtual void execute() = 0;
	int getPid() const;
	int getTipo() const;
	virtual std::string serialize() const;
	static Processo* deserialize(const std::string& linha);
};


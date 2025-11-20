#pragma once
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

	virtual void execute() = 0;
	int getPid() const;
	int getTipo() const;
};


#pragma once
class Processo
{
protected:
	int pid;

public:
	Processo();
	~Processo();

	virtual void executar();
	int getPid() const;
};


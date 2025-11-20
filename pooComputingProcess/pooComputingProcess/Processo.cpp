#include "Processo.h"

int Processo::nextPid = 1;

Processo::Processo() {}
Processo::~Processo() {}

Processo::Processo(int tipo)
{
	this->pid = nextPid++;
	this->tipo = tipo;
}

int Processo::getPid() const
{
	return this->pid;
}

int Processo::getTipo() const
{
	return this->tipo;
}


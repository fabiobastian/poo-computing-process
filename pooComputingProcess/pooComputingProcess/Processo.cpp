#include "Processo.h"

int Processo::nextPid = 1;

Processo::Processo() {}
Processo::~Processo() {}

Processo::Processo(int tipo)
{
	this->pid = nextPid++;
	this->tipo = tipo;
}

Processo::Processo(int pid, int tipo)
{
	this->pid = pid;
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

std::string Processo::serialize() const
{
	return std::to_string(pid) + ";" + std::to_string(tipo);
}


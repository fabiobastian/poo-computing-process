#pragma once
#include "Nodo.h"

class Fila
{
private:
	Nodo* primeiro;
	Nodo* ultimo;
	int tamanho;

public:
	Fila();
	~Fila();
	void push(Processo*); // Adiciona processo final da fila
	Processo* pop(); // remove o primeiro processo da fila
	Processo* front(); // Retorna o primeiro processo da fila
	Processo* findByPid(int pid); // procurar e retornar um processo especifico pelo PID
	bool empty(); // true se a fila estiver vazia

	Nodo* getPrimeiro() const;
};


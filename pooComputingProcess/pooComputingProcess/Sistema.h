#pragma once
//#include "Pilha.h"
//#include "Aluno.h"
#include "Fila.h"
#include "ComputingProcess.h"
#include "WritingProcess.h"
#include "ReadingProcess.h"
#include "PrintingProcess.h"
using namespace std;

class Sistema
{
public:
	Sistema();
	~Sistema();

	void executar();
	void criarProcesso();
	void criarProcessoGravacao();
	void criarProcessoLeitura();
	void criarProcessoImpressao();
	void criarProcessoCalculo();
	void carregarFila(Fila* fila);
	void salvarFila(Fila* fila);
	void executarProximo();
	void executarProcessoEspecifico();

private:
	void opcoesSistema();
	void opcoesProcessos();
	Fila fila;
};


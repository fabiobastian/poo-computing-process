#include <iostream>
#include "ComputingProcess.h"
#include "WritingProcess.h"
#include "ReadingProcess.h"
#include "PrintingProcess.h"
#include "Fila.h"

using namespace std;

int main()
{
	cout << "HELOOO";

    Fila fila;

    // Adicionando processos
    fila.push(new PrintingProcess(&fila));
    fila.push(new ComputingProcess(50.0, 80.0, '+'));

    //<operacao>;<num1>;<num2>
    string expr = "+;100;20";
    fila.push(new WritingProcess(expr));

    fila.push(new ReadingProcess(&fila));
    fila.push(new PrintingProcess(&fila));

    cout << "Primeiro da fila (front): PID = "
        << fila.front()->getPid() << endl;

    // Procurando um processo específico
    int buscaPid = 20;
    Processo* achado = fila.findByPid(buscaPid);

    if (achado != nullptr)
        cout << "Processo encontrado PID = " << achado->getPid() << endl;
    else
        cout << "Processo PID " << buscaPid << " não encontrado.\n";

    // Executando e removendo processos
    while (!fila.empty()) {
        Processo* p = fila.pop();  // remove
        p->execute();              // simula execução
        delete p;                  // desaloca o processo após executar
    }

    cout << "Fila esvaziada com sucesso!" << endl;

	return 0;
}
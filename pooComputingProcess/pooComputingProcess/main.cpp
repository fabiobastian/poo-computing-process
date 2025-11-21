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
    int buscaPid = 2;
    Processo* achado = fila.findByPid(buscaPid);

    if (achado != nullptr)
        cout << "Processo encontrado PID = " << achado->getPid() << endl;
    else
        cout << "Processo PID " << buscaPid << " não encontrado.\n";


    Processo* downcasting = fila.front();

    if (downcasting->getTipo() == 4) { // Exemplo: tipo 1 = PrintingProcess

        PrintingProcess* pr = dynamic_cast<PrintingProcess*>(downcasting);

        if (pr != nullptr) {
            // Agora posso acessar atributos específicos e métodos do tipo
            pr->testeDown();
        }
    }

    // Executando e removendo processos
    while (!fila.empty()) {
        Processo* p = fila.pop();  // remove
        p->execute();              // simula execução
        delete p;                  // desaloca o processo após executar
    }

    cout << "Fila esvaziada com sucesso!" << endl;

	return 0;
}
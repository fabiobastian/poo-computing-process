#include "Sistema.h"

#include "ComputingProcess.h"
#include "WritingProcess.h"
#include "ReadingProcess.h"
#include "PrintingProcess.h"
#include "Fila.h"

using namespace std;

/*
void salvarFila(Fila* fila);
void carregarFila(Fila* fila);
*/
int main()
{
    //sistema
    Sistema sistema;
    sistema.executar();

    /*
    Fila fila;

    ComputingProcess* cp1 = new ComputingProcess('+', 50.0, 80.0);

    string expr = "+;100;20";
    WritingProcess* wp1 = new WritingProcess(expr);

    ReadingProcess* rp1 = new ReadingProcess(&fila);
    PrintingProcess* pp1 = new PrintingProcess(&fila);

    cout << "\n" + cp1->serialize();
    cout << "\n" + wp1->serialize();
    cout << "\n" + rp1->serialize();
    cout << "\n" + pp1->serialize();

    fila.push(cp1);
    fila.push(wp1);
    fila.push(rp1);
    fila.push(pp1);


    salvarFila(&fila);
    carregarFila(&fila);


    cout << "\nPrimeiro da fila (front): PID = "
        << fila.front()->getPid() << endl;


    // Procurando um processo específico
    int buscaPid = 2;
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
*/

	return 0;
}


//COLOQUEI ESSES METODOS NA CLASSE SISTEMA
/*
void salvarFila(Fila* fila)
{
    std::ofstream arquivo("computationProcess.txt", std::ofstream::out);

    if (!arquivo.is_open()) {
        std::cout << "Erro ao abrir arquivo para escrita! 'computationProcess.txt'\n";
        return;
    }

    // Enquanto houver processos na fila
    while (!fila->empty())
    {
        Processo* p = fila->pop();     // remove o primeiro da fila
        arquivo << p->serialize() << "\n"; // grava serializado no arquivo
        delete p;
    }

    arquivo.close();

    std::cout << "\nFila salva e esvaziada com sucesso!\n";
}


void carregarFila(Fila* fila)
{
    std::ifstream arquivo("computationProcess.txt");

    if (!arquivo.is_open()) {
        std::cout << "Erro ao abrir arquivo! 'computationProcess.txt'\n";
    }

    std::string linha;

    while (std::getline(arquivo, linha))
    {
        std::stringstream ss(linha);
        std::string temp;

        // Primeiro campo: PID
        std::getline(ss, temp, ';');
        int pid = std::stoi(temp);

        // Segundo campo: tipo
        std::getline(ss, temp, ';');
        int tipo = std::stoi(temp);

        Processo* proc = nullptr;

        switch (tipo)
        {
        case 1: // ComputingProcess
            proc = ComputingProcess::deserialize(linha);
            break;

        case 2: // WritingProcess
            proc = WritingProcess::deserialize(linha);
            break;

        case 3: // ReadingProcess
            proc = ReadingProcess::deserialize(linha, fila);
            break;

        case 4: // PrintingProcess
            proc = PrintingProcess::deserialize(linha, fila);
            break;

        default:
            std::cout << "\nTipo desconhecido na linha: " << linha << std::endl;
        }

        if (proc != nullptr) {
            std::cout << "\nProcesso carregado PID " << proc->getPid() << "\n";
            fila->push(proc);
        }
    }

    arquivo.close();
}*/
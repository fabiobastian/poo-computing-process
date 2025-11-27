#include "Sistema.h"
#include "ComputingProcess.h"
#include "WritingProcess.h"
#include "ReadingProcess.h"
#include "PrintingProcess.h"
#include "Fila.h"
using namespace std;


Sistema::Sistema() {
	fila = Fila();
}
Sistema::~Sistema() {
}

void Sistema::executar()
{
	int escolha;

	while (1) {
		opcoesSistema();
		cin >> escolha;

		switch (escolha)
		{
		case 1:
			cout << "\nCriar processo:" << endl;
			criarProcesso();
			break;
		case 2:
			cout << "\nExecutar proximo" << endl;
			executarProximo();
			break;
		case 3:
			cout << "\nExecutar um processo especifico" << endl;
			executarProcessoEspecifico();
			break;
		case 7:
			cout << "Ate logo!";
			return;
			break;
		default:
			cout << "Opcao inválida. Digite novamente!" << endl;
			break;
		}
		cout << endl;
	}
}

void Sistema::opcoesSistema() {
	cout << "Menu:" << endl;
	cout << "1 - Criar processo" << endl;
	cout << "2 - Executar proximo" << endl;
	cout << "3 - Executar um processo especifico" << endl;
	cout << "7 - Sair" << endl;
	cout << "Escolha uma das opcoes acima: ";
}

void Sistema::opcoesProcessos() {
	cout << "Tipos de Processo:" << endl;
	cout << "1 - Calculo" << endl;
	cout << "2 - Gravacao" << endl;
	cout << "3 - Leitura" << endl;
	cout << "4 - Impressao" << endl;
	cout << "7 - Sair" << endl;
	cout << "Escolha uma das opcoes acima: ";
}

void Sistema::criarProcesso() {
	int escolha;

	while (1) {
		opcoesProcessos();
		cin >> escolha;

		switch (escolha)
		{

		case 1:
			cout << "\nCalculo" << endl;
			criarProcessoCalculo();
			break;
		case 2:
			cout << "\nGravacao" << endl;
			criarProcessoGravacao();
			break;
		case 3:
			cout << "\nLeitura" << endl;
			criarProcessoLeitura();
			break;
		case 4:
			cout << "\nImpressao" << endl;
			criarProcessoImpressao();
			break;
		case 7:
			cout << "Saiu";
			return;
			break;
		default:
			cout << "Opcao inválida. Digite novamente!" << endl;
			break;
		}
		cout << endl;
	}
}

// refatorar criarProcesso?
void Sistema::criarProcessoGravacao() {
	string expr = "+;100;20";
	WritingProcess* wp1 = new WritingProcess(expr);
	cout << "Processo do tipo gravacao criado." << endl;
	fila.push(wp1);
	cout << "Processo do tipo gravacao adicionado ao final da fila." << endl;
	cout << "\n" + wp1->serialize();
	salvarFila(&fila);
	carregarFila(&fila);
	cout << "Fila atualizada." << endl;
}

void Sistema::criarProcessoLeitura() {
	ReadingProcess* rp1 = new ReadingProcess(&fila);
	cout << "Processo do tipo leitura criado." << endl;
	fila.push(rp1);
	cout << "Processo do tipo leitura adicionado ao final da fila." << endl;
	cout << "\n" + rp1->serialize();
	salvarFila(&fila);
	carregarFila(&fila);
	cout << "Fila atualizada." << endl;
}

void Sistema::criarProcessoImpressao() {
	PrintingProcess* pp1 = new PrintingProcess(&fila);
	cout << "Processo do tipo impressao criado." << endl;
	fila.push(pp1);
	cout << "Processo do tipo impressao adicionado ao final da fila." << endl;
	cout << "\n" + pp1->serialize();
	salvarFila(&fila);
	carregarFila(&fila);
	cout << "Fila atualizada." << endl;
}

void Sistema::criarProcessoCalculo() {
	int operandoUm, operandoDois;
	char expressao;
	cout << "\nDigite o simbolo  (+, -, * ou /) equivalente a operação do calculo:" << endl;
	cin >> expressao;
	cout << "\nDigite o primeiro operando:" << endl;
	cin >> operandoUm;
	cout << "\nDigite o segundo operando:" << endl;
	cin >> operandoDois;
	ComputingProcess* cp1 = new ComputingProcess(expressao, operandoUm, operandoDois);
	cout << "Processo do tipo calculo criado." << endl;
	fila.push(cp1);
	cout << "Processo do tipo calculo adicionado ao final da fila." << endl;
	cout << "\n" + cp1->serialize();
	salvarFila(&fila);
	carregarFila(&fila);
	cout << "Fila atualizada." << endl;
}

void Sistema::executarProximo() {

	int buscaPid = fila.front()->getPid();
	cout << "\nPrimeiro da fila (front): PID = " << buscaPid << endl;
	// Procurando um processo específico
	Processo* achado = fila.findByPid(buscaPid);
	int pid = achado->getPid();

	if (achado != nullptr)
		cout << "Processo encontrado PID = " << pid << endl;
	else
		cout << "Processo PID " << buscaPid << " não encontrado.\n";

	achado = fila.pop();											// remove da fila
	achado->execute();												// simula execução
	cout << "Processo PID = " << pid << " executado.\n" << endl;
	delete achado;													// desaloca o processo após executar

	//encapsular essas 3 linhas abaixo para refatorar?
	salvarFila(&fila);
	carregarFila(&fila);
	cout << "Fila atualizada." << endl;
}

void Sistema::executarProcessoEspecifico() {

	cout << "\nDigite o PID do processo a ser executado" << endl;
	int buscaPid;
	cin >> buscaPid;
	// Procurando um processo específico
	Processo* achado = fila.findByPid(buscaPid);
	int pid = achado->getPid();

	if (achado != nullptr)
		cout << "Processo encontrado PID = " << pid << endl;
	else
		cout << "Processo PID " << buscaPid << " não encontrado.\n";

	achado = fila.pop();											// remove da fila
	achado->execute();												// simula execução
	cout << "Processo PID = " << pid << " executado.\n" << endl;
	delete achado;													// desaloca o processo após executar

	//encapsular essas 3 linhas abaixo para refatorar?
	salvarFila(&fila);
	carregarFila(&fila);
	cout << "Fila atualizada." << endl;
}

//estes metodos deveriam estar na classe fila?

void Sistema::salvarFila(Fila* fila)
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

	std::cout << "Fila salva e esvaziada com sucesso!\n";
}

void Sistema::carregarFila(Fila* fila)
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
			std::cout << "Processo carregado PID " << proc->getPid() << "\n";
			fila->push(proc);
		}
	}

	arquivo.close();
}
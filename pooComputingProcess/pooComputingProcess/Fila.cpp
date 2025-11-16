#include "Fila.h"

void Fila::push(Processo* processo)
{
    Nodo* novo = new Nodo();
    novo->processo = processo;
    novo->proximo = nullptr;

    // Caso especial: fila vazia
    if (primeiro == nullptr) {
        primeiro = novo;
        ultimo = novo;
    }
    else {
        ultimo->proximo = novo;
        ultimo = novo;
    }
    tamanho++;
}

Processo* Fila::pop()
{
    // Fila vazia
    if (primeiro == nullptr) {
        return nullptr;
    }

    // Guarda o nó que será removido
    Nodo* removido = primeiro;
    Processo* processo = removido->processo;

    // Avança o ponteiro do início
    primeiro = primeiro->proximo;

    // Se ficou vazia após remover, ajusta o 'ultimo'
    if (primeiro == nullptr) {
        ultimo = nullptr;
    }

    delete removido;  // libera memória do nodo
    tamanho--;

    return processo;  // retorna o processo removido
}

Processo* Fila::front()
{
    if (primeiro == nullptr)
        return nullptr;

    return primeiro->processo;
}

bool Fila::empty()
{
    return primeiro == nullptr;
}

Processo* Fila::findByPid(int pid)
{
    Nodo* atual = primeiro;

    while (atual != nullptr) {
        if (atual->processo->getPid() == pid) {
            return atual->processo;
        }
        atual = atual->proximo;
    }

    return nullptr; // não encontrado
}
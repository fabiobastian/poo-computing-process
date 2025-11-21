#include "Fila.h"

Fila::Fila() {
    this->primeiro = nullptr;
    this->ultimo = nullptr;
    this->tamanho = 0;
}

Fila::~Fila(){}

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

Nodo* Fila::getPrimeiro() const {
    return primeiro;
}

Processo* Fila::popByPid(int pid)
{
    if (primeiro == nullptr) return nullptr;

    Nodo* atual = primeiro;
    Nodo* anterior = nullptr;

    // Procurar o nó
    while (atual != nullptr && atual->processo->getPid() != pid) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == nullptr) return nullptr; // não encontrou

    // Se for o primeiro da fila
    if (atual == primeiro) {
        primeiro = primeiro->proximo;
        if (primeiro == nullptr) ultimo = nullptr; // fila ficou vazia
    }
    else {
        anterior->proximo = atual->proximo;
        if (atual == ultimo) ultimo = anterior; // era o último
    }

    tamanho--;
    Processo* p = atual->processo;
    delete atual;  // remove o nó, mas não o processo!

    return p; // retorna o processo removido
}

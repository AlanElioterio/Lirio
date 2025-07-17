#include "Trufa.h"
#include <string>

using namespace std;
Trufa::Trufa(int idTipoTrufa, int idSaborTrufa, float preco)
{
    this->idTipoTrufa = idTipoTrufa;
    this->idSaborTrufa = idSaborTrufa;
    this->preco = preco;
    this->estoque = 0;
}

Trufa::Trufa(int idTipoTrufa, int idSaborTrufa, float preco, int estoque)
{
    this->idTipoTrufa = idTipoTrufa;
    this->idSaborTrufa = idSaborTrufa;
    this->preco = preco;
    this->estoque = estoque;
}

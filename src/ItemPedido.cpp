#include "ItemPedido.h"
#include <string>

using namespace std;

ItemPedido::ItemPedido(int id, int idPedido, int idTrufa, int quantidade, float totalPedido)
{
    this->id = id;
    this->idPedido = idPedido;
    this->idTrufa = idTrufa;
    this->quantidade = quantidade;
    this->totalPedido = totalPedido;
}

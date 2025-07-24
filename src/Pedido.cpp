#include "Pedido.h"
#include <string>

using namespace std;
Pedido::Pedido(int id, int idCliente, string dataPedido)
{
    this->idPedido = idPedido;
    this->idCliente = idCliente;
    this->dataPedido = dataPedido;
}

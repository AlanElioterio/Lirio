#ifndef PEDIDO_H
#define PEDIDO_H
#include <string>

using namespace std;

class Pedido
{
    public:
        Pedido(int id, int idCliente, string dataPedido);

        int GetIdPedido() { return idPedido; }
        int GetIdCliente() { return idCliente; }
        string GetDataPedido() { return dataPedido; }

    protected:

    private:
        int idPedido;
        int idCliente;
        string dataPedido;
};

#endif // PEDIDO_H

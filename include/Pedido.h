#ifndef PEDIDO_H
#define PEDIDO_H
#include <string>

using namespace std;

class Pedido
{
    public:
        Pedido(int id, int idCliente, string dataPedido);

        int GetIdPedido() { return idPedido; }
        void SetIdPedido(int val) { idPedido = val; }
        int GetIdCliente() { return idCliente; }
        void SetIdCliente(int val) { idCliente = val; }
        string GetDataPedido() { return dataPedido; }
        void SetDataPedido(string val) { dataPedido = val; }

    protected:

    private:
        int idPedido;
        int idCliente;
        string dataPedido;
};

#endif // PEDIDO_H

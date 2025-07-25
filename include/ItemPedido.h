#ifndef ITEMPEDIDO_H
#define ITEMPEDIDO_H

#include <string>

using namespace std;

class ItemPedido
{
    public:
        ItemPedido(int id, int idPedido, int idTrufa, int quantidade, float totalPedido);

        int GetId() { return id; }
        int GetIdPedido() { return idPedido; }
        int GetIdTrufa() { return idTrufa; }
        int GetQuantidade() { return quantidade; }
        int GetTotalPedido() { return totalPedido; }

    protected:

    private:
        int id;
        int idPedido;
        int idTrufa;
        int quantidade;
        float totalPedido;
};

#endif // ITEMPEDIDO_H

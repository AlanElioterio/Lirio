#ifndef ITEMPEDIDO_H
#define ITEMPEDIDO_H

#include <string>

using namespace std;

class ItemPedido
{
    public:
        ItemPedido(int id, int idPedido, int idTrufa, int quantidade, float totalPedido);

        int GetId() { return id; }
        void SetId(int val) { id = val; }
        int GetIdPedido() { return idPedido; }
        void SetIdPedido(int val) { idPedido = val; }
        int GetIdTrufa() { return idTrufa; }
        void SetIdTrufa(int val) { idTrufa = val; }
        int GetQuantidade() { return quantidade; }
        void SetQuantidade(int val) { quantidade = val; }
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

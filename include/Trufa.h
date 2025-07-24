#ifndef TRUFA_H
#define TRUFA_H

#include <string>

using namespace std;
class Trufa
{
    public:
        Trufa(int idTipoTrufa, int idSaborTrufa, float preco);
        Trufa(int idTipoTrufa, int idSaborTrufa, float preco, int estoque);

        int GetId() { return id; }
        void SetId(int val) { id = val; }
        int GetIdTipoTrufa() { return idTipoTrufa; }
        void SetIdTipoTrufa(int val) { idTipoTrufa = val; }
        int GetIdSaborTrufa() { return idSaborTrufa; }
        void SetIdSaborTrufa(int val) { idSaborTrufa = val; }
        float GetPreco() { return preco; }
        void SetPreco(float val) { preco = val; }
        int GetEstoque() { return estoque; }
        void SetEstoque(int val) { estoque = val; }

    protected:

    private:
        int id;
        int idTipoTrufa;
        int idSaborTrufa;
        float preco;
        int estoque;
};

#endif // TRUFA_H

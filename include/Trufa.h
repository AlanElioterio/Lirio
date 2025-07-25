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
        int GetIdTipoTrufa() { return idTipoTrufa; }
        int GetIdSaborTrufa() { return idSaborTrufa; }
        float GetPreco() { return preco; }
        int GetEstoque() { return estoque; }

    protected:

    private:
        int id;
        int idTipoTrufa;
        int idSaborTrufa;
        float preco;
        int estoque;
};

#endif // TRUFA_H

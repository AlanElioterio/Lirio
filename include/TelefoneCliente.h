#ifndef TELEFONECLIENTE_H
#define TELEFONECLIENTE_H

#include <string>

using namespace std;
class TelefoneCliente
{
    public:
        TelefoneCliente(int id, int idCliente, int codigoPais, int ddd, int telefone);

        int GetId() { return id; }
        void SetId(int val) { id = val; }
        int GetIdCliente() { return idCliente; }
        void SetIdCliente(int val) { idCliente = val; }
        int GetCodigoPais() { return codigoPais; }
        void SetCodigoPais(int val) { codigoPais = val; }
        int GetDdd() { return ddd; }
        void SetDdd(int val) { ddd = val; }
        int GetTelefone() { return telefone; }
        void SetTelefone(int val) { telefone = val; }

    protected:

    private:
        int id;
        int idCliente;
        int codigoPais;
        int ddd;
        int telefone;
};

#endif // TELEFONECLIENTE_H

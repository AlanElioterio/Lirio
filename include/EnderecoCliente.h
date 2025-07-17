#include <string>

#ifndef ENDERECOCLIENTE_H
#define ENDERECOCLIENTE_H
#include <string>
using namespace std;

class EnderecoCliente
{
    public:
        EnderecoCliente(int id, int idCliente, string logradouro, int idCidade, int idEstado, int idPais);

        int GetId() { return id; }
        void SetId(int val) { id = val; }
        int GetIdCidade() { return idCidade; }
        void SetIdCidade(int val) { idCidade = val; }
        int GetIdEstado() { return idEstado; }
        void SetIdEstado(int val) { idEstado = val; }
        int GetIdPais() { return idPais; }
        void SetIdPais(int val) { idPais = val; }
        string GetLogradouro() { return logradouro; }
        void SetLogradouro(string val) { logradouro = val; }
        int GetIdCliente() { return idCliente; }
        void SetIdCliente(int val) { idCliente = val; }

    protected:

    private:
        int id;
        int idCliente;
        int idCidade;
        int idEstado;
        int idPais;
        string logradouro;
};

#endif // ENDERECOCLIENTE_H

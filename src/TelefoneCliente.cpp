#include "TelefoneCliente.h"
#include <string>

using namespace std;
TelefoneCliente::TelefoneCliente(int id, int idCliente, int codigoPais, int ddd, int telefone)
{
    this->id = id;
    this->idCliente = idCliente;
    this->codigoPais = codigoPais;
    this->ddd = ddd;
    this->telefone = telefone;
}

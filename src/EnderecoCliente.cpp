#include "EnderecoCliente.h"
#include <string>

using namespace std;
EnderecoCliente::EnderecoCliente(int id, int idCliente, string logradouro, int idCidadeidCidade, int idEstado, int idPais)
{
    this->id = id;
    this->idCliente = idCliente;
    this->logradouro = logradouro;
    this->idCidade = idCidade;
    this->idEstado = idEstado;
    this->idPais = idPais;
}

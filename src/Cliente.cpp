#include "Cliente.h"
#include <string>
using namespace std;

Cliente::Cliente(string nome, int cpf, string dataNascimento, string genero, int id)
{
    this->id = id;
    this->nome = nome;
    this->cpf = cpf;
    this->dataNascimento = dataNascimento;
    this->genero = genero;
}

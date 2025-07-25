#include <string>
#ifndef CLIENTE_H
#define CLIENTE_H

using namespace std;

class Cliente
{
    public:
        Cliente(string nome, int cpf, string dataNascimento, string genero, int id = 0);

        int GetId() { return id; }
        string GetNome() { return nome; }
        int GetCpf() { return cpf; }
        string GetDataNascimento() { return dataNascimento; }
        string GetGenero() { return genero; }
        void SetGenero(string val) { genero = val; }

    protected:

    private:
        int id;
        string nome;
        int cpf;
        string dataNascimento;
        string genero;
};

#endif // CLIENTE_H

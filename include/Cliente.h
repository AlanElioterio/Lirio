#include <string>
#ifndef CLIENTE_H
#define CLIENTE_H

using namespace std;

class Cliente
{
    public:
        Cliente(string nome, int cpf, string dataNascimento, string genero);

        int GetId() { return id; }
        void SetId(int val) { id = val; }
        string GetNome() { return nome; }
        void SetNome(string val) { nome = val; }
        int GetCpf() { return cpf; }
        void SetCpf(int val) { cpf = val; }
        string GetDataNascimento() { return dataNascimento; }
        void SetDataNascimento(string val) { dataNascimento = val; }
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

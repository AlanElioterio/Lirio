#include <iostream>
#include <sqlite3.h>
#include <stdio.h>
#include <vector>
#include <string>
#include "MenuCliente.h"
#include "Cliente.h"
#include "DatabaseService.h"

using namespace std;

void MenuCliente::inserirCliente() {
    string nome;
    int cpf;
    string dataNascimento;
    string genero;

    cout << "Digite o nome do cliente: ";
    cin >> nome;
    cout << "Digite o CPF do cliente: ";
    cin >> cpf;
    cout << "Digite a Data de Nascimento do cliente (YYYY-MM-DD): ";
    cin >> dataNascimento;
    cout << "Digite o gênero do cliente: ";
    cin >> genero;

    Cliente cliente(nome, cpf, dataNascimento, genero);

    string sql = "INSERT INTO Cliente (nome, cpf, data_nascimento, genero) VALUES (?, ?, ?, ?);";
    sqlite3_stmt* stmt; // Pacote a ser enviado

    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);

    sqlite3_bind_text(stmt, 1, cliente.GetNome().c_str(), -1, SQLITE_TRANSIENT); // Inserindo o nome na primeira interrogação
    sqlite3_bind_int(stmt, 2, cliente.GetCpf()); // Inserindo o cpf na segunda interrogação
    sqlite3_bind_text(stmt, 3, cliente.GetDataNascimento().c_str(), -1, SQLITE_TRANSIENT); // Inserindo a data de nascimento na terceira interrogação
    sqlite3_bind_text(stmt, 4, cliente.GetGenero().c_str(), -1, SQLITE_TRANSIENT); // Inserindo o gênero na quarta interrogação

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        cout << "Cliente inserido com sucesso.\n";
    } else {
        cout << "Erro ao inserir cliente.\n";
    }
    sqlite3_finalize(stmt);

    system("pause");
}

void MenuCliente::listarClientes() {

    const char* sql = "SELECT id_cliente, nome, cpf, data_nascimento, genero FROM Cliente;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK) {
        cout << "\n--- Lista de Clientes ---\n";

        while (sqlite3_step(stmt) == SQLITE_ROW) {

            int id = sqlite3_column_int(stmt, 0);
            string nome = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)) ;
            int cpf = sqlite3_column_int(stmt, 2);
            string dataNascimento = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)) ;
            string genero = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));

            Cliente cliente(nome, cpf, dataNascimento, genero, id);

            cout << "ID: " << cliente.GetId() << " | Nome: " << cliente.GetNome() << " | CPF: " << cliente.GetCpf()  << " | Data de Nascimento: " << cliente.GetDataNascimento() << " | Gênero: " << cliente.GetGenero() << "\n";
        }


        sqlite3_finalize(stmt);


    } else {
        cout << "Erro ao consultar clientes.\n";
    }
    system("pause");
}

void MenuCliente::atualizarCliente() {
    int id;
    string novoNome;

    cout << "Digite o ID do cliente a ser atualizado: ";
    cin >> id;
    cout << "Digite o novo nome: ";
    cin >> novoNome;

    string sql = "UPDATE Cliente SET nome = ? WHERE id_cliente = ?;";
    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);

    sqlite3_bind_text(stmt, 1, novoNome.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 2, id);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        cout << "Cliente atualizado com sucesso.\n";
    } else {
        cout << "Erro ao atualizar cliente.\n";
    }
    sqlite3_finalize(stmt);
    system("pause");
}

void MenuCliente::deletarCliente() {
    int id;
    cout << "Digite o ID do cliente a ser deletado: ";
    cin >> id;

    string sql = "DELETE FROM Cliente WHERE id_cliente = ?;";
    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
    sqlite3_bind_int(stmt, 1, id);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        cout << "Cliente deletado com sucesso.\n";
    } else {
        cout << "Erro ao deletar cliente.\n";
    }
    sqlite3_finalize(stmt);
    system("pause");
}

void MenuCliente::mostrarMenu() {
    int opcao;
    do {
        system("cls");
        cout << "\n===== MENU CLIENTE =====\n";
        cout << "1. Inserir cliente\n";
        cout << "2. Listar clientes\n";
        cout << "3. Atualizar cliente\n";
        cout << "4. Deletar cliente\n";
        cout << "0. Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
            case 1: inserirCliente(); break;
            case 2: listarClientes(); break;
            case 3: atualizarCliente(); break;
            case 4: deletarCliente(); break;
            case 0: cout << "Saindo...\n"; break;
            default: cout << "Opção inválida.\n";
        }
    } while (opcao != 0);
}

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
    std::cin >> nome;
    cout << "Digite o CPF do cliente: ";
    std::cin >> cpf;
    cout << "Digite a Data de Nascimento do cliente (YYYY-MM-DD): ";
    std::cin >> dataNascimento;
    cout << "Digite o gênero do cliente: ";
    std::cin >> genero;

    Cliente cliente(nome, cpf, dataNascimento, genero);

    std::string sql = "INSERT INTO Cliente (nome, cpf, data_nascimento, genero) VALUES (?, ?, ?, ?);";
    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, cliente.GetNome().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 2, cliente.GetCpf());
    sqlite3_bind_text(stmt, 3, cliente.GetDataNascimento().c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, cliente.GetGenero().c_str(), -1, SQLITE_TRANSIENT);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        std::cout << "Cliente inserido com sucesso.\n";
    } else {
        std::cerr << "Erro ao inserir cliente.\n";
    }
    sqlite3_finalize(stmt);
}

void MenuCliente::listarClientes() {
    const char* sql = "SELECT id_cliente, nome, cpf, data_nascimento, genero FROM Cliente;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, nullptr) == SQLITE_OK) {
        std::cout << "\n--- Lista de Clientes ---\n";

        while (sqlite3_step(stmt) == SQLITE_ROW) {

            int id = sqlite3_column_int(stmt, 0);
            string nome = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)) ;
            int cpf = sqlite3_column_int(stmt, 2);
            string dataNascimento = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)) ;
            string genero = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));

            Cliente cliente(nome, cpf, dataNascimento, genero);
            cliente.SetId(id);

            std::cout << "ID: " << cliente.GetId() << " | Nome: " << cliente.GetNome() << " | CPF: " << cliente.GetCpf()  << " | Data de Nascimento: " << cliente.GetDataNascimento() << " | Gênero: " << cliente.GetGenero() << "\n";
        }

        sqlite3_finalize(stmt);

        cin.ignore();
    } else {
        std::cerr << "Erro ao consultar clientes.\n";
    }
}

void MenuCliente::atualizarCliente() {
    int id;
    std::string novoNome;
    std::cout << "Digite o ID do cliente a ser atualizado: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Digite o novo nome: ";
    std::getline(std::cin, novoNome);

    std::string sql = "UPDATE Cliente SET nome = ? WHERE id_cliente = ?;";
    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);

    sqlite3_bind_text(stmt, 1, novoNome.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 2, id);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        std::cout << "Cliente atualizado com sucesso.\n";
    } else {
        std::cerr << "Erro ao atualizar cliente.\n";
    }
    sqlite3_finalize(stmt);
}

void MenuCliente::deletarCliente() {
    int id;
    std::cout << "Digite o ID do cliente a ser deletado: ";
    std::cin >> id;
    std::cin.ignore();

    std::string sql = "DELETE FROM Cliente WHERE id_cliente = ?;";
    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, nullptr);
    sqlite3_bind_int(stmt, 1, id);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        std::cout << "Cliente deletado com sucesso.\n";
    } else {
        std::cerr << "Erro ao deletar cliente.\n";
    }
    sqlite3_finalize(stmt);
}

void MenuCliente::mostrarMenu() {
    int opcao;
    do {
        system("cls");
        std::cout << "\n===== MENU CLIENTE =====\n";
        std::cout << "1. Inserir cliente\n";
        std::cout << "2. Listar clientes\n";
        std::cout << "3. Atualizar cliente\n";
        std::cout << "4. Deletar cliente\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore();

        switch (opcao) {
            case 1: inserirCliente(); break;
            case 2: listarClientes(); break;
            case 3: atualizarCliente(); break;
            case 4: deletarCliente(); break;
            case 0: std::cout << "Saindo...\n"; break;
            default: std::cout << "Opção inválida.\n";
        }
    } while (opcao != 0);
}

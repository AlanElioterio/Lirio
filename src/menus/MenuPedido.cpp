#include <iostream>
#include <sqlite3.h>
#include <stdio.h>
#include <vector>
#include <string>
#include "MenuPedido.h"
#include "Pedido.h"
#include "ItemPedido.h"
#include "DatabaseService.h"
#include <ctime>

using namespace std;

string obterDataAtual() {
    time_t now = time(0);  // Tempo Atual
    struct tm* timeinfo = localtime(&now);

    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", timeinfo);

    return string(buffer);
}

void MenuPedido::inserirPedido() {
    MenuTrufa::listarTrufas();

    int idTrufa;
    int idCliente;
    int quantidadeTrufa;
    string dataPedido = obterDataAtual();

    cout << "Digite o ID da trufa do pedido: ";
    cin >> idTrufa;

    cout << "Digite o quantidade de trufas: ";
    cin >> quantidadeTrufa;

    cout << "Digite o ID do cliente: ";
    cin >> idCliente;

    Cliente cliente(nome, cpf, dataNascimento, genero);

    string sql = "INSERT INTO Cliente (nome, cpf, data_nascimento, genero) VALUES (?, ?, ?, ?);";
    sqlite3_stmt* stmt; // Pacote a ser enviado

    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);

    sqlite3_bind_text(stmt, 1, cliente.GetNome().c_str(), -1, SQLITE_TRANSIENT); // Inserindo o nome na primeira interrogação
    sqlite3_bind_int(stmt, 2, cliente.GetCpf()); // Inserindo o cpf na segunda interrogação
    sqlite3_bind_text(stmt, 3, cliente.GetDataNascimento().c_str(), -1, SQLITE_TRANSIENT); // Inserindo a data de nascimento na terceira interrogação
    sqlite3_bind_text(stmt, 4, cliente.GetGenero().c_str(), -1, SQLITE_TRANSIENT); // Inserindo o gênero na quarta interrogação

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        cout << "Pedido inserido com sucesso.\n";
    } else {
        cerr << "Erro ao inserir pedido.\n";
    }
    sqlite3_finalize(stmt);
}

void MenuPedido::listarPedidos() {

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

            Cliente cliente(nome, cpf, dataNascimento, genero);
            cliente.SetId(id);

            std::cout << "ID: " << cliente.GetId() << " | Nome: " << cliente.GetNome() << " | CPF: " << cliente.GetCpf()  << " | Data de Nascimento: " << cliente.GetDataNascimento() << " | Gênero: " << cliente.GetGenero() << "\n";
        }

        sqlite3_finalize(stmt);

        cin.ignore();
    } else {
        cerr << "Erro ao consultar clientes.\n";
    }
}

void MenuPedido::mostrarMenu() {
    int opcao;
    do {
        system("cls");
        std::cout << "\n===== MENU PEDIDOS =====\n";
        std::cout << "1. Inserir pedido\n";
        std::cout << "2. Listar pedidos\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore();

        switch (opcao) {
            case 1: inserirPedido(); break;
            case 2: listarPedidos(); break;
            case 0: cout << "Saindo...\n"; break;
            default: cout << "Opção inválida.\n";
        }
    } while (opcao != 0);
}

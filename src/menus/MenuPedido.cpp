#include <ctime>
#include <iostream>
#include <sqlite3.h>
#include <stdio.h>
#include <vector>
#include <string>
#include "MenuPedido.h"
#include "MenuTrufa.h"
#include "MenuCliente.h"
#include "Pedido.h"
#include "ItemPedido.h"
#include "DatabaseService.h"

using namespace std;

void MenuPedido::inserirPedido() {

    MenuCliente::listarClientes();

    int idCliente;
    cout << "Digite o ID do cliente: ";
    cin >> idCliente;

    int idPedido;

    time_t t = time(NULL);
    char data[20];
    strftime(data, sizeof(data), "%Y-%m-%d", localtime(&t));

    const char* sql = "INSERT INTO Pedido (id_cliente, data_pedido) VALUES (?, ?);";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, sql, -1, &stmt, NULL);

    sqlite3_bind_int(stmt, 1, idCliente);
    sqlite3_bind_text(stmt, 2, data, -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        idPedido = (int)sqlite3_last_insert_rowid(db);
        sqlite3_finalize(stmt);
    } else {
        cout << "Erro ao criar pedido.\n";
        sqlite3_finalize(stmt);
    }

    if (idPedido == -1) return;

    while (true) {
        MenuTrufa::listarTrufas();
        int idTrufa, qtd;
        cout << "Digite o ID da trufa (ou 0 para finalizar o pedido): ";
        cin >> idTrufa;
        if (idTrufa == 0) break;
        cout << "Digite a quantidade: ";
        cin >> qtd;
        MenuPedido::inserirItemPedido(idPedido, idTrufa, qtd);
    }

    cout << "Pedido #" << idPedido << " finalizado com sucesso!\n";
}

void MenuPedido::inserirItemPedido(int idPedido, int idTrufa, int quantidade) {
    // Buscar preço da trufa
    const char* sqlPreco = "SELECT preco, estoque FROM Trufa WHERE id_trufa = ?";
    sqlite3_stmt* stmtPreco;

    sqlite3_prepare_v2(db, sqlPreco, -1, &stmtPreco, nullptr);
    sqlite3_bind_int(stmtPreco, 1, idTrufa);

    double preco = 0.0;
    int estoqueAtual = 0;

    if (sqlite3_step(stmtPreco) == SQLITE_ROW) {
        preco = sqlite3_column_double(stmtPreco, 0);
        estoqueAtual = sqlite3_column_int(stmtPreco, 1);
    } else {
        cout << "Trufa não encontrada.\n";
        sqlite3_finalize(stmtPreco);
        return;
    }

    sqlite3_finalize(stmtPreco);

    // Verificar estoque
    if (quantidade > estoqueAtual) {
        cout << "Estoque insuficiente! Disponível: " << estoqueAtual << "\n";
        return;
    }

    double total = preco * quantidade;

    // Inserir ItemPedido
    const char* sqlItem = "INSERT INTO ItemPedido (id_pedido, id_trufa, quantidade, total_pedido) VALUES (?, ?, ?, ?)";
    sqlite3_stmt* stmtItem;

    sqlite3_prepare_v2(db, sqlItem, -1, &stmtItem, nullptr);
    sqlite3_bind_int(stmtItem, 1, idPedido);
    sqlite3_bind_int(stmtItem, 2, idTrufa);
    sqlite3_bind_int(stmtItem, 3, quantidade);
    sqlite3_bind_double(stmtItem, 4, total);

    if (sqlite3_step(stmtItem) != SQLITE_DONE) {
        cout << "Erro ao inserir item no pedido.\n";
        sqlite3_finalize(stmtItem);
        return;
    }
    sqlite3_finalize(stmtItem);

    // Atualizar estoque da trufa
    const char* sqlUpdateEstoque = "UPDATE Trufa SET estoque = estoque - ? WHERE id_trufa = ?";
    sqlite3_stmt* stmtUpdate;

    sqlite3_prepare_v2(db, sqlUpdateEstoque, -1, &stmtUpdate, nullptr);
    sqlite3_bind_int(stmtUpdate, 1, quantidade);
    sqlite3_bind_int(stmtUpdate, 2, idTrufa);

    if (sqlite3_step(stmtUpdate) == SQLITE_DONE) {
        cout << "Item inserido e estoque atualizado com sucesso.\n";
    } else {
        cout << "Erro ao atualizar estoque da trufa.\n";
    }

    sqlite3_finalize(stmtUpdate);
}

void MenuPedido::listarPedidos() {
    string sql = "SELECT p.id_pedido, c.nome, p.data_pedido, tt.tipo_trufa, st.sabor, ip.quantidade, ip.total_pedido FROM Pedido p "
    "JOIN Cliente c ON p.id_cliente = c.id_cliente JOIN ItemPedido ip ON ip.id_pedido = p.id_pedido JOIN Trufa t ON t.id_trufa = ip.id_trufa JOIN TipoTrufa tt ON tt.id_tipo_trufa = t.id_tipo_trufa "
    "JOIN SaborTrufa st ON st.id_sabor_trufa = t.id_sabor_trufa ORDER BY p.id_pedido;";

    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK) {
        int pedidoAtual = -1;

        cout << "\n===== LISTA DE PEDIDOS =====\n";

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int idPedido = sqlite3_column_int(stmt, 0);
            string nomeCliente = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            string dataPedido = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            string tipoTrufa = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
            string saborTrufa = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
            int quantidade = sqlite3_column_int(stmt, 5);
            double totalItem = sqlite3_column_double(stmt, 6);

            if (idPedido != pedidoAtual) {
                pedidoAtual = idPedido;
                cout << "\nPedido #" << idPedido
                          << " | Cliente: " << nomeCliente
                          << " | Data: " << dataPedido << "\n";
            }

            cout << "  - Trufa: " << tipoTrufa << " | Sabor: " << saborTrufa
                      << " | Quantidade: " << quantidade
                      << " | Total: R$" << totalItem << "\n";
        }

        sqlite3_finalize(stmt);

    } else {
        cout << "Erro ao listar pedidos.\n";
    }

    cout << "\n";
    system("pause");
}

void MenuPedido::mostrarMenu() {
    int opcao;
    do {
        system("cls");
        cout << "\n===== MENU PEDIDOS =====\n";
        cout << "1. Criar novo pedido\n";
        cout << "2. Listar pedidos\n";
        cout << "0. Voltar\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
            case 1: inserirPedido(); break;
            case 2: listarPedidos(); break;
            case 0: cout << "Saindo...\n"; break;
            default: cout << "Opção inválida.\n";
        }

    } while (opcao != 0);
}

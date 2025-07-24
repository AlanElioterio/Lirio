#include "MenuTrufa.h"
#include "Trufa.h"
#include <iostream>
#include <sqlite3.h>
#include <stdio.h>
#include <vector>
#include <string>
#include "DatabaseService.h"

using namespace std;


void MenuTrufa::listarTipoTrufas() {
    const char* sql = "select id_tipo_trufa, tipo_trufa from TipoTrufa";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK) {
        std::cout << "\n--- Lista de Tipo de Trufas ---\n";

        while (sqlite3_step(stmt) == SQLITE_ROW) {

            int idTrufa = sqlite3_column_int(stmt, 0);
            string tipoTrufa = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)) ;

            std::cout << "ID Tipo: " << idTrufa << " | Tipo da Trufa: " << tipoTrufa << "\n";
        }

        sqlite3_finalize(stmt);
    } else {
        std::cerr << "Erro ao consultar sabor de trufas.\n";
    }
}

void MenuTrufa::listarSaborTrufas() {
    const char* sql = "select id_sabor_trufa, sabor from SaborTrufa";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK) {
        std::cout << "\n--- Lista de Sabor de Trufas ---\n";

        while (sqlite3_step(stmt) == SQLITE_ROW) {

            int idSaborTrufa = sqlite3_column_int(stmt, 0);
            string saborTrufa = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)) ;

            std::cout << "ID Sabor: " << idSaborTrufa << " | Sabor da Trufa: " << saborTrufa << "\n";
        }

        sqlite3_finalize(stmt);
    } else {
        std::cerr << "Erro ao consultar sabor de trufas.\n";
    }
}

void MenuTrufa::inserirTrufa() {

    listarTipoTrufas();
    listarSaborTrufas();

    int idTipoTrufa;
    int idSaborTrufa;
    float preco;

    cout << "Digite o Id do tipo da trufa: ";
    std::cin >> idTipoTrufa;
    cout << "Digite o Id do sabor da trufa: ";
    std::cin >> idSaborTrufa;
    cout << "Digite o preço dessa trufa: ";
    std::cin >> preco;

    Trufa trufa(idTipoTrufa, idSaborTrufa, preco);

    std::string sql = "INSERT INTO Trufa (idTipoTrufa, idSaborTrufa, preco, estoque) VALUES (?, ?, ?, ?);";
    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);

    sqlite3_bind_int(stmt, 1, trufa.GetIdTipoTrufa());
    sqlite3_bind_int(stmt, 2, trufa.GetIdTipoTrufa());
    sqlite3_bind_double(stmt, 3, trufa.GetPreco());
    sqlite3_bind_int(stmt, 4, trufa.GetEstoque());

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        std::cout << "Trufa inserida com sucesso.\n";
    } else {
        std::cerr << "Erro ao inserir trufa.\n";
    }
    sqlite3_finalize(stmt);
}

void MenuTrufa::listarTrufas() {
    const char* sql = "SELECT t.id_trufa, tt.tipo_trufa, st.sabor, t.preco, t.estoque FROM Trufa t LEFT JOIN TipoTrufa tt on t.id_tipo_trufa = tt.id_tipo_trufa LEFT JOIN SaborTrufa st on t.id_tipo_trufa = st.id_sabor_trufa";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK) {
        std::cout << "\n--- Lista de Trufas ---\n";

        while (sqlite3_step(stmt) == SQLITE_ROW) {

            int idTrufa = sqlite3_column_int(stmt, 0);
            string tipoTrufa = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)) ;
            string saborTrufa = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)) ;
            double precoTrufa = sqlite3_column_double(stmt, 3);
            int estoqueTrufa = sqlite3_column_int(stmt, 4);

            std::cout << "ID: " << idTrufa << " | Tipo da Trufa: " << tipoTrufa << " | Sabor da Trufa: " << saborTrufa  << " | Preço: R$" << precoTrufa << " | Estoque: " << estoqueTrufa << "\n";
        }

        sqlite3_finalize(stmt);

        cin.ignore();
    } else {
        std::cerr << "Erro ao consultar trufas.\n";
    }
}

void MenuTrufa::atualizarTrufa() {
    int id;
    float novoPreco;
    std::cout << "Digite o ID da trufa a ser atualizada: ";
    std::cin >> id;
    std::cin.ignore();
    std::cout << "Digite o novo preço: ";
    std::cin >> novoPreco;

    std::string sql = "UPDATE Trufa SET preco = ? WHERE id_trufa = ?;";
    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);

    sqlite3_bind_double(stmt, 1, novoPreco);
    sqlite3_bind_int(stmt, 2, id);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        std::cout << "Trufa atualizada com sucesso.\n";
    } else {
        std::cerr << "Erro ao atualizar trufa.\n";
    }
    sqlite3_finalize(stmt);
}

void MenuTrufa::deletarTrufa() {
    int id;
    std::cout << "Digite o ID da trufa a ser deletada: ";
    std::cin >> id;
    std::cin.ignore();

    std::string sql = "DELETE FROM Trufa WHERE id_trufa = ?;";
    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
    sqlite3_bind_int(stmt, 1, id);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        std::cout << "Trufa deletada com sucesso.\n";
    } else {
        std::cerr << "Erro ao deletar trufa.\n";
    }
    sqlite3_finalize(stmt);
}

void MenuTrufa::mostrarMenu() {
    int opcao;
    do {
        system("cls");
        std::cout << "\n===== MENU TRUFAS =====\n";
        std::cout << "1. Inserir trufas\n";
        std::cout << "2. Listar trufas\n";
        std::cout << "3. Atualizar trufa\n";
        std::cout << "4. Deletar trufa\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore();

        switch (opcao) {
            case 1: inserirTrufa(); break;
            case 2: listarTrufas(); break;
            case 3: atualizarTrufa(); break;
            case 4: deletarTrufa(); break;
            case 0: std::cout << "Saindo...\n"; break;
            default: std::cout << "Opção inválida.\n";
        }
    } while (opcao != 0);

}

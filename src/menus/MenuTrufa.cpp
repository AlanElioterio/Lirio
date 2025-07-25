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
        cout << "\n--- Lista de Tipo de Trufas ---\n";

        while (sqlite3_step(stmt) == SQLITE_ROW) {

            int idTrufa = sqlite3_column_int(stmt, 0);
            string tipoTrufa = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)) ;

            cout << "ID Tipo: " << idTrufa << " | Tipo da Trufa: " << tipoTrufa << "\n";
        }

        sqlite3_finalize(stmt);
    } else {
        cout << "Erro ao consultar sabor de trufas.\n";
    }
    system("pause");
}

void MenuTrufa::listarSaborTrufas() {
    const char* sql = "select id_sabor_trufa, sabor from SaborTrufa";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK) {
        cout << "\n--- Lista de Sabor de Trufas ---\n";

        while (sqlite3_step(stmt) == SQLITE_ROW) {

            int idSaborTrufa = sqlite3_column_int(stmt, 0);
            string saborTrufa = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)) ;

            cout << "ID Sabor: " << idSaborTrufa << " | Sabor da Trufa: " << saborTrufa << "\n";
        }

        sqlite3_finalize(stmt);
    } else {
        cout << "Erro ao consultar sabor de trufas.\n";
    }
    system("pause");
}

void MenuTrufa::inserirTrufa() {

    listarTipoTrufas();
    listarSaborTrufas();

    int idTipoTrufa;
    int idSaborTrufa;
    float preco;

    cout << "Digite o Id do tipo da trufa: ";
    cin >> idTipoTrufa;
    cout << "Digite o Id do sabor da trufa: ";
    cin >> idSaborTrufa;
    cout << "Digite o preço dessa trufa: ";
    cin >> preco;

    Trufa trufa(idTipoTrufa, idSaborTrufa, preco);

    string sql = "INSERT INTO Trufa (idTipoTrufa, idSaborTrufa, preco, estoque) VALUES (?, ?, ?, ?);";
    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);

    sqlite3_bind_int(stmt, 1, trufa.GetIdTipoTrufa());
    sqlite3_bind_int(stmt, 2, trufa.GetIdTipoTrufa());
    sqlite3_bind_double(stmt, 3, trufa.GetPreco());
    sqlite3_bind_int(stmt, 4, trufa.GetEstoque());

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        cout << "Trufa inserida com sucesso.\n";
    } else {
        cout << "Erro ao inserir trufa.\n";
    }
    sqlite3_finalize(stmt);
    system("pause");
}

void MenuTrufa::listarTrufas() {
    const char* sql = "SELECT t.id_trufa, tt.tipo_trufa, st.sabor, t.preco, t.estoque FROM Trufa t LEFT JOIN TipoTrufa tt on t.id_tipo_trufa = tt.id_tipo_trufa LEFT JOIN SaborTrufa st on t.id_tipo_trufa = st.id_sabor_trufa";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) == SQLITE_OK) {
        cout << "\n--- Lista de Trufas ---\n";

        while (sqlite3_step(stmt) == SQLITE_ROW) {

            int idTrufa = sqlite3_column_int(stmt, 0);
            string tipoTrufa = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)) ;
            string saborTrufa = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)) ;
            double precoTrufa = sqlite3_column_double(stmt, 3);
            int estoqueTrufa = sqlite3_column_int(stmt, 4);

            cout << "ID: " << idTrufa << " | Tipo da Trufa: " << tipoTrufa << " | Sabor da Trufa: " << saborTrufa  << " | Preço: R$" << precoTrufa << " | Estoque: " << estoqueTrufa << "\n";
        }

        sqlite3_finalize(stmt);

    } else {
        cout << "Erro ao consultar trufas.\n";
    }
    system("pause");
}

void MenuTrufa::atualizarTrufa() {
    int id;
    float novoPreco;
    cout << "Digite o ID da trufa a ser atualizada: ";
    cin >> id;
    cout << "Digite o novo preço: ";
    cin >> novoPreco;

    string sql = "UPDATE Trufa SET preco = ? WHERE id_trufa = ?;";
    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);

    sqlite3_bind_double(stmt, 1, novoPreco);
    sqlite3_bind_int(stmt, 2, id);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        cout << "Trufa atualizada com sucesso.\n";
    } else {
        cout << "Erro ao atualizar trufa.\n";
    }
    sqlite3_finalize(stmt);
    system("pause");
}

void MenuTrufa::deletarTrufa() {
    int id;
    cout << "Digite o ID da trufa a ser deletada: ";
    cin >> id;

    string sql = "DELETE FROM Trufa WHERE id_trufa = ?;";
    sqlite3_stmt* stmt;

    sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL);
    sqlite3_bind_int(stmt, 1, id);

    if (sqlite3_step(stmt) == SQLITE_DONE) {
        cout << "Trufa deletada com sucesso.\n";
    } else {
        cout << "Erro ao deletar trufa.\n";
    }
    sqlite3_finalize(stmt);
    system("pause");
}

void MenuTrufa::mostrarMenu() {
    int opcao;
    do {
        system("cls");
        cout << "\n===== MENU TRUFAS =====\n";
        cout << "1. Inserir trufas\n";
        cout << "2. Listar trufas\n";
        cout << "3. Atualizar trufa\n";
        cout << "4. Deletar trufa\n";
        cout << "0. Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
            case 1: inserirTrufa(); break;
            case 2: listarTrufas(); break;
            case 3: atualizarTrufa(); break;
            case 4: deletarTrufa(); break;
            case 0: cout << "Saindo...\n"; break;
            default: cout << "Opção inválida.\n";
        }
    } while (opcao != 0);

}

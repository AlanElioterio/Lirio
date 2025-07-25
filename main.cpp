#include <iostream>
#include <sqlite3.h>
#include <stdio.h>
#include <vector>
#include <string>
#include "MenuCliente.h"
#include "MenuTrufa.h"
#include "MenuPedido.h"
#include "DatabaseService.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Portuguese");

    if (connect_database() != 0) {
        return 1; // erro na conexão
    }

    int opcao;
    do {
        system("cls");
        cout << "\n===== MENU GERAL =====\n";
        cout << "1. Área de Clientes \n";
        cout << "2. Área de Trufas\n";
        cout << "3. Área de Pedidos\n";
        cout << "0. Sair\n";
        cout << "Escolha: ";
        cin >> opcao;

        switch (opcao) {
            case 1: MenuCliente::mostrarMenu(); break;
            case 2: MenuTrufa::mostrarMenu(); break;
            case 3: MenuPedido::mostrarMenu(); break;
            case 0: cout << "Saindo...\n"; break;
            default: cout << "Opção inválida.\n";
        }
    } while (opcao != 0);

    fecharBanco();
    return 0;
}


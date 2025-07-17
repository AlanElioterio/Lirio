#include <iostream>
#include <sqlite3.h>
#include <stdio.h>
#include <vector>
#include <string>
#include "MenuCliente.h"
#include "MenuTrufa.h"
#include "DatabaseService.h"

using namespace std;

int main() {
    if (connect_database() != 0) {
        return 1; // erro na conexão
    }

    int opcao;
    do {
        system("cls");
        std::cout << "\n===== MENU GERAL =====\n";
        std::cout << "1. Área de Clientes \n";
        std::cout << "2. Área de Trufas\n";
        std::cout << "3. Área de Pedidos\n";
        std::cout << "0. Sair\n";
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore();

        switch (opcao) {
            case 1: MenuCliente::mostrarMenu(); break;
            case 2: MenuTrufa::mostrarMenu(); break;
            case 3: MenuCliente::mostrarMenu(); break;
            case 4: MenuCliente::mostrarMenu(); break;
            case 0: std::cout << "Saindo...\n"; break;
            default: std::cout << "Opção inválida.\n";
        }
    } while (opcao != 0);

    fecharBanco();
    return 0;
}

